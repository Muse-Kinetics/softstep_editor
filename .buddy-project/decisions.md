# Decisions

## Packetized updater stays in `KMI_MDM`

The packetized SoftStep firmware transport lives in `shared/KMI_MDM`, not in editor-specific code. The editors select and feed the shared updater rather than implementing product-specific transport logic on their own.

## Split responsibilities between orchestration and parsing

`KMI_mdm` owns the state machine, readiness checks, send gating, and verification flow. `KMI_fwupdate` owns parsing a prebuilt firmware `.syx` into complete SysEx packets and exposing progress counters.

## Use prebuilt chunk-safe firmware assets

The editor should consume a prebuilt `-cs512` SysEx file rather than building PID headers or chunking ad hoc inside the app. This keeps firmware packet boundaries aligned with the converter output and flash-page-safe packaging. `sendsysex` follows the same convention for its own payloads (e.g. BopPad's `-cs128`).

## Block queued SysEx during packetized transfer

Normal queued/chunked SysEx must not interleave with packetized firmware transfer. During active packetized update, generic queued SysEx is blocked until the firmware chunk is sent and the updater advances state. The legacy generic-SysEx transport itself remains available for non-firmware traffic — the packetized path is additive, not a replacement.

## Add diagnostics where the transport actually changes state

The current diagnostic strategy is to log packetized phase transitions in the firmware console and to tag raw SysEx capture notes with phase and packet counters, rather than adding a separate UI-specific debugger.

## WMS is primary, WinMM is the runtime fallback — mirrored in three places

`KMI_MDM`, `rtmidi`, and `sendsysex` each independently probe Windows MIDI Services (WMS) availability at startup and fall back to WinMM if it isn't installed. `KMI_MIDI_BACKEND=winmm` (or `--midi-backend winmm` in `sendsysex`) forces WinMM for testing on machines that do have WMS. This is deliberately duplicated logic (`kmiSelectMidiApi()` in KMI_MDM, `isWindowsMidiServicesAvailable()` in rtmidi, `midiBackend.cpp` in sendsysex) rather than a shared library, so any backend-selection change must be applied in all three places to avoid port-index/name-matching mismatches between enumeration and open.

## Pre-1.0.0 firmware devices are unsupported, not auto-recovered

`KMI_MDM` removed its legacy "trojan-horse" bootloader-install path for devices reporting firmware `< 1.0.0` (that firmware predates the bootloader and cannot be safely updated through this editor). Both editors now show a blocking "not supported" dialog, open `https://support.musekinetics.com`, and quit, rather than attempting recovery.

## `.buddy-project/` is meant to be an untracked agent workspace, but the gitignore doesn't fully accomplish that yet

`.buddy-project/` was added to `.gitignore` (`/.buddy-project/`) with intent to stop treating it as project source. In practice this has **no effect on the files already tracked** — `.gitignore` only suppresses newly-untracked paths, so all `.buddy-project/*.md` files remain tracked and show as `modified` in `git status` on every edit. This is exactly what caused the accidental-inclusion incident (commit `4e60119f` bundled staged `.buddy-project`/`.github` edits into an unrelated sendsysex-pointer commit; reverted in `0f78d86b`, re-cleaned in `65893872`). Until someone runs `git rm --cached -r .buddy-project` (a deliberate, explicit action — not something to do unprompted) and commits that removal, treat `.buddy-project/*.md` changes as tracked files: check `git status` before any commit and exclude them explicitly if they weren't meant to be part of that change. See blockers.md.
