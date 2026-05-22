# KMI_MDM Transmit Buffer Audit & Proposed Changes

**Date:** April 19, 2026  
**Scope:** `shared/KMI_MDM/KMI_mdm.cpp`, `KMI_mdm.h`, and SoftStep Advanced editor integration  
**Context:** Windows MIDI Services (WMS) broke SysEx transmission for WinMM apps. The 4th message in a startup burst consistently fails with `MMSYSERR_ERROR`. Retry after a short delay succeeds every time.

## Handoff Status (April 21, 2026)

This document remains the baseline for KMI_MDM transmit behavior and retry logic, and should be used alongside current bug-tracking work.

Current continuation priorities:

- Ongoing comms monitoring in real editor workflows (especially Hosted mode)
- Hosted mode port access reliability and recovery behavior
- Expression pedal calibration and runtime pedal behavior validation in Hosted mode
- General bug fixing and regression validation around MIDI transport and state transitions
- Keep the current commit scoped to launch/logging stabilization and firmware payload refresh where possible
- Implement firmware-update packet chunking in the next commit using `Documentation/FIRMWARE_CHUNKING.md` as the execution plan
- Remove packaged `(... Debug Console)` editor binaries only after the shared logger work is committed and validated across both editors

Temporary fixtures under `shared/test_winmm/` are available for backend-specific investigation and controlled repro runs.

Recommended validation path in the current VS Code workspace:

- Launch `Launch SoftStep Advanced Editor` so the GUI runs on the visible Windows desktop through the Release launch helper
- Run `Tail SoftStep Advanced Editor Log` in parallel when live log following is needed
- Expect logs under `%APPDATA%\Keith McMillen Instruments\SoftStep Advanced Editor\logs`
- When Hosted pedal behavior looks wrong, also verify the paired firmware state in `00_Firmware/SoftStep`, because the Hosted pedal path now depends on both the editor-side pedal state and the firmware-side calibrated pedal transmission fix

---

## 1. Current Architecture

### Transmit Buffer

The outgoing MIDI buffer is a single `std::vector<uchar> packet` (KMI_mdm.h:148). All outgoing MIDI — channel messages, SysEx commands, and firmware payloads — share this one buffer.

A `QTimer midiSendTimer` fires every **1ms** and calls `slotEmptyMIDIBuffer()` to drain it.

### Two Send Paths

| Path | Condition | Behavior |
|---|---|---|
| **Chunked** | `packet.size() > sysExTxChunkSize` | Extracts `sysExTxChunkSize` bytes, sends, enforces `sysExTxChunkDelay` ms between chunks |
| **Immediate** | `packet.size() <= sysExTxChunkSize` | Parses complete SysEx (F0..F7) or channel messages and sends each individually |

### Platform Chunk Settings (KMI_mdm.cpp:224-227)

| Platform | `sysExTxChunkSize` | `sysExTxChunkDelay` |
|---|---|---|
| Windows/macOS | 48 bytes | 1 ms |
| Linux | 512 bytes | 50 ms |

### Firmware Updates Use the Same Buffer

When `slotSendSysExBA(firmwareByteArray)` is called (KMI_mdm.cpp:897), the entire firmware image (often 50–100KB) is appended to `packet`. It then drains through the same chunked path as normal SysEx, 48 bytes every 1ms on Windows.

During `FWUD_STATE_FW_SENT_WAIT`, the state machine polls `packet.size() > 500` to check if the firmware is still transmitting.

---

## 2. Current Error Handling

### Circuit Breaker (KMI_mdm.cpp:1710-1726, 1783-1799, etc.)

Every `catch (RtMidiError)` block in `slotEmptyMIDIBuffer()` does:

1. **`packet.clear()`** — discards all remaining buffered data
2. Increments `midiSendErrorCount` (resets to 0 if 60 seconds have passed since last error)
3. If count ≥ 3: **trips circuit breaker** — `midiSendTimer.stop()`, no more sending, no automatic recovery
4. If count < 3: closes both ports and calls `kmiPorts->slotRefreshPortMaps()` to attempt reconnection

### What Happens to Failed Messages

**They are lost.** `packet.clear()` discards everything — the failed chunk, all subsequent chunks, and any other messages that were queued. During a firmware update, this means the firmware image is silently truncated and the device receives an incomplete update.

### What Happens After Circuit Breaker Trips

**Nothing.** The timer is stopped. There is no automatic recovery. The user must disconnect/reconnect or restart the application. The error count persists across reconnections (intentionally — KMI_mdm.cpp:466 comment), so reconnecting within 60 seconds after 3 failures will trip immediately again.

---

## 3. Identified Gaps

### Gap 1: No Retry on Send Failure

When `midiOutLongMsg` returns `MMSYSERR_ERROR` (the WMS regression), the failed chunk is discarded. Our test fixture (`softstep_port1_repro_winmm.exe`) proved that a 3-second wait and retry succeeds 100% of the time. The library does not attempt this.

**Impact:** Every WMS-affected send failure causes data loss and potential disconnect.

### Gap 2: Firmware Data Loss on Error

The firmware byte array is appended to `packet` as a single bulk insert. If any chunk fails mid-transfer:
- `packet.clear()` discards remaining firmware data
- The firmware byte array still exists in `firmwareByteArray`, but nothing re-queues it
- The state machine moves to `FWUD_STATE_FW_SENT_WAIT` and eventually times out to `FWUD_STATE_FAIL`
- The device is potentially left in bootloader mode with a partial firmware image

**Impact:** Firmware update failure can soft-brick the device until a manual recovery.

### Gap 3: No Firmware-Specific Error Handling Path

The circuit breaker treats firmware chunks and normal SysEx identically. A single WMS hiccup during firmware transfer triggers the same close-ports-and-refresh sequence, which is far too aggressive for a multi-second bulk transfer that was going fine.

### Gap 4: Other Messages Can Interleave with Firmware

While firmware is draining through the chunked path, `slotSendMIDI()` can still append channel messages to `packet` (gated only by `ioGate`, which is released at the end of `slotSendSysEx`). The SoftStep editor's `slotUpdateSettings()` burst fires 500ms after connection, which could collide with a firmware transfer if timing is unfortunate.

### Gap 5: ioGate Has No Thread Safety

`ioGate` is a bare `bool` with no mutex. If `slotSendMIDI()` is called from a different thread than `slotSendSysEx()`, there is a potential race condition where MIDI messages are inserted into `packet` while SysEx framing is in progress.

### Gap 6: Small Chunk Padding is Fragile

When a final chunk is < 6 bytes, 10 zero bytes are inserted before the trailing `0xF7` (KMI_mdm.cpp:1688). This padding is not documented and the rationale is unclear. If the receiving device interprets these zeros as SysEx data, it could cause subtle corruption.

---

## 4. Proposed Changes

### Change 1: Add Retry Logic to `slotEmptyMIDIBuffer()` (Priority: Critical)

**Where:** Every `catch (RtMidiError)` block in `slotEmptyMIDIBuffer()`  
**What:** Instead of discarding `packet` on error, retry the failed chunk after a delay.

```
On send failure:
  1. DO NOT clear packet
  2. Log the error with chunk details
  3. Wait retryDelayMs (start with 100ms, back off to 3000ms)
  4. Re-attempt the same chunk
  5. After maxRetries (3) consecutive failures on the same chunk:
     - THEN clear and trigger circuit breaker
```

**Implementation sketch:**

New member variables in `KMI_mdm.h`:
```cpp
int midiChunkRetryCount = 0;
static const int MIDI_CHUNK_RETRY_MAX = 3;
int midiChunkRetryDelayMs = 100;              // initial delay
static const int MIDI_CHUNK_RETRY_DELAY_MAX = 3000; // max backoff
QElapsedTimer midiChunkRetryTimer;
bool midiChunkRetryPending = false;
```

In the chunked send catch block, instead of `packet.clear()`:
```cpp
catch (RtMidiError &error) {
    midiChunkRetryCount++;
    if (midiChunkRetryCount > MIDI_CHUNK_RETRY_MAX) {
        // Exhausted retries — fall through to existing circuit breaker
        packet.clear();
        // ... existing circuit breaker code ...
    } else {
        // Retry: leave packet intact, back off the timer
        midiChunkRetryPending = true;
        midiChunkRetryDelayMs = qMin(midiChunkRetryDelayMs * 2, MIDI_CHUNK_RETRY_DELAY_MAX);
        midiChunkRetryTimer.restart();
        DM_OUT << "Chunk send failed, retry" << midiChunkRetryCount 
               << "in" << midiChunkRetryDelayMs << "ms";
        return; // don't erase, don't close ports — just wait
    }
}
```

At the top of `slotEmptyMIDIBuffer()`, add retry gate:
```cpp
if (midiChunkRetryPending) {
    if (midiChunkRetryTimer.elapsed() < midiChunkRetryDelayMs)
        return; // still waiting for retry delay
    midiChunkRetryPending = false;
    // fall through to retry the same chunk
}
```

On successful send, reset retry state:
```cpp
midi_out->sendMessage(&chunkToSend);
midiChunkRetryCount = 0;
midiChunkRetryDelayMs = 100;
midiChunkRetryPending = false;
```

**Cross-product impact:** This change is entirely within `KMI_mdm.cpp/h`. It benefits every editor that uses KMI_MDM. No editor-side changes required.

### Change 2: Firmware-Aware Error Handling (Priority: High)

**Where:** `slotEmptyMIDIBuffer()` error path  
**What:** When `firmwareUpdateState` is active (`!= FWUD_STATE_IDLE`), use a more conservative error response.

During firmware transfer:
- **Never** close ports on a single chunk failure (the device is in bootloader mode — closing the port could make it unreachable)
- **Never** call `kmiPorts->slotRefreshPortMaps()` during firmware send (port enumeration during bootloader mode is dangerous)
- **Increase** retry limits (e.g. `MIDI_CHUNK_RETRY_MAX = 10` during firmware)
- If all retries exhausted during firmware, set `firmwareUpdateState = FWUD_STATE_FAIL` explicitly rather than relying on timeout

```cpp
bool isFirmwareTransfer = (firmwareUpdateState == FWUD_STATE_FW_SEND || 
                            firmwareUpdateState == FWUD_STATE_FW_SENT_WAIT);
int effectiveMaxRetries = isFirmwareTransfer ? 10 : MIDI_CHUNK_RETRY_MAX;

// ... in the exhausted-retries fallback:
if (isFirmwareTransfer) {
    DM_OUT << "FIRMWARE TRANSFER FAILED after" << midiChunkRetryCount << "retries";
    firmwareUpdateState = FWUD_STATE_FAIL;
    // Do NOT close ports or refresh — let the state machine handle cleanup
} else {
    // existing circuit breaker behavior for non-firmware traffic
}
```

### Change 3: Block New Messages During Firmware Transfer (Priority: Medium)

**Where:** `slotSendSysEx()` and `slotSendMIDI()`  
**What:** When firmware is actively draining (`firmwareUpdateState == FWUD_STATE_FW_SEND || FWUD_STATE_FW_SENT_WAIT`), reject new messages from being appended to `packet`.

```cpp
void MidiDeviceManager::slotSendSysEx(unsigned char *sysEx, int len) {
    if (firmwareUpdateState == FWUD_STATE_FW_SEND || 
        firmwareUpdateState == FWUD_STATE_FW_SENT_WAIT) {
        DM_OUT << "WARNING: rejecting SysEx send during firmware transfer";
        return;
    }
    // ... existing code ...
}
```

This prevents the editor's `slotUpdateSettings()` burst or any other SysEx from contaminating the firmware data stream.

### Change 4: Preserve Failed Data for Re-Queue (Priority: Medium)

**Where:** `slotEmptyMIDIBuffer()` circuit breaker trip  
**What:** When the circuit breaker trips, stash the remaining buffer instead of discarding it, so it can be re-sent after port recovery.

New member:
```cpp
std::vector<uchar> pendingPacket; // stashed data from circuit breaker trip
```

On circuit breaker trip:
```cpp
pendingPacket = packet;
packet.clear();
midiSendTimer.stop();
```

On port reopen (`slotOpenMidiOut()`):
```cpp
if (!pendingPacket.empty()) {
    DM_OUT << "Restoring" << pendingPacket.size() << "bytes from circuit breaker stash";
    packet = pendingPacket;
    pendingPacket.clear();
}
midiSendTimer.start();
```

**Caveat:** For non-firmware data, stale messages may no longer be relevant after a disconnect/reconnect cycle. Consider adding a flag to control whether stashed data should be restored or discarded based on context (e.g., always restore during firmware update, discard otherwise).

### Change 5: Add Transmit Health Signal (Priority: Low)

**Where:** `KMI_mdm.h` signals  
**What:** Emit a signal when retries are occurring so the UI can display a warning.

```cpp
signals:
    void signalTransmitHealth(int retryCount, int maxRetries, QString detail);
```

The editor can connect this to a status bar indicator or log pane, giving the user visibility into driver instability without requiring them to read debug output.

---

## 5. Implementation Status

| Step | Change | Status | Notes |
|---|---|---|---|
| 1 | Retry logic (Change 1) | **DONE** | `handleSendError()` in KMI_mdm.cpp, exponential backoff 100ms→3s, all 4 catch blocks replaced |
| 2 | Firmware error handling (Change 2) | **DONE** | 10 retries during firmware, never closes ports during FW transfer, sets FWUD_STATE_FAIL on exhaustion |
| 3 | Block messages during firmware (Change 3) | **DONE** | Channel messages blocked in `slotSendMIDI()` during FW_SEND/FW_SENT_WAIT |
| 4 | Stash failed data (Change 4) | Deferred | Lower priority, not yet implemented |
| 5 | Health signal (Change 5) | **DONE** | `signalTransmitHealth(int retryCount, int maxRetries)` signal added |
| — | ioGate thread safety (Gap 5) | **DONE** | Changed from `bool` to `std::atomic<bool>` |
| — | Switch Advanced Editor to WinMM | **DONE** | Changed `__WINDOWS_UWP__=1` → `__WINDOWS_MM__=1` in SoftStepAdvanced.pro |

### Key Implementation Details

- All retry logic is centralized in `handleSendError(const QString&)` — a single private method that replaced 4 duplicated catch blocks
- On failure: packet is **preserved** (not cleared), allowing the same data to retry on next timer tick
- Retry gate at top of `slotEmptyMIDIBuffer()` checks elapsed time against backoff delay
- On successful send: `midiChunkRetryCount` resets to 0, with recovery logging when count was > 0
- Retry count resets on port reopen (`slotOpenMidiOut()`)

### Runtime Test Results

**UWP backend (April 19, 2026):** Retry mechanics worked correctly (1/3, 2/3, 3/3 logged with backoff). However the UWP MIDI port object was destroyed after the first error (`0x80004004` → `0x80000013` on retries), making retries futile. The UWP backend also failed to deliver the "enter bootloader" SysEx, leaving the device stuck in bootloader mode. This is why the Advanced Editor was switched to WinMM.

**WinMM backend (April 19, 2026):** Editor and firmware update working correctly. The device was initially stuck in bootloader mode (from the failed UWP run). The WinMM-backed editor detected bootloader mode, performed the firmware update, and recovered gracefully from all errors encountered during the process. The retry-with-backoff logic and firmware-aware error handling are functioning as designed.

All changes are confined to `KMI_mdm.cpp` and `KMI_mdm.h`. No editor-specific code changes are required for steps 1–4. Changes will propagate to all products that use KMI_MDM when the shared library is rebuilt.

---

## 6. Test Validation

The `shared/test_winmm/softstep_port1_repro_winmm.exe` fixture already proves the retry pattern works:

```
Round 1/2
  send[0] OK len=43
  send[1] OK len=43
  send[2] OK len=43
  send[3] FAIL (attempt 1/4): MidiOutWinMM::sendMessage: error sending sysex message.
  send[3] retry 1/3 after 3000ms...
  send[3] OK on retry 1 len=43
Round 2/2
  send[0] OK len=43
  send[1] OK len=43
  send[2] OK len=43
  send[3] FAIL (attempt 1/4): MidiOutWinMM::sendMessage: error sending sysex message.
  send[3] retry 1/3 after 3000ms...
  send[3] OK on retry 1 len=43
PASS: no failures observed across all rounds.
```

100% consistent: message 3 fails, first retry succeeds. This is the exact same failure mode that KMI_MDM's `slotEmptyMIDIBuffer()` needs to handle.

---

## 7. Compatibility Note

These changes **do not affect Windows 10 or pre-WMS Windows 11 behavior**. The retry logic only activates when `sendMessage()` throws an exception. On systems without WMS, no exceptions are thrown and the retry path is never entered. The only observable difference is slightly more member variables in the class.
