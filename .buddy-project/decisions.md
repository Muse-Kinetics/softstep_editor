# Decisions

## Packetized updater stays in `KMI_MDM`

The packetized SoftStep firmware transport lives in `shared/KMI_MDM`, not in editor-specific code. The editors select and feed the shared updater rather than implementing product-specific transport logic on their own.

## Split responsibilities between orchestration and parsing

`KMI_mdm` owns the state machine, readiness checks, send gating, and verification flow. `KMI_fwupdate` owns parsing a prebuilt firmware `.syx` into complete SysEx packets and exposing progress counters.

## Use prebuilt chunk-safe firmware assets

The editor consumes a prebuilt `-cs512` SysEx file rather than building PID headers or chunking ad hoc inside the app. This keeps firmware packet boundaries aligned with the converter output and flash-page-safe packaging.

## Block queued SysEx during packetized transfer

Normal queued/chunked SysEx must not interleave with packetized firmware transfer. During active packetized update, generic queued SysEx is blocked until the firmware chunk is sent and the updater advances state.

## WMS + WinMM dual-backend runtime selection

Both `__WINDOWS_MIDI_SERVICES__` and `__WINDOWS_MM__` are compiled into every Windows build. `KMI_Ports` probes `RtMidi::isWindowsMidiServicesAvailable()` at startup and picks WMS when the runtime is installed, WinMM otherwise. `kmiSelectMidiApi()` in `KMI_mdm.cpp` mirrors this so `midi_in`/`midi_out` always use the same backend as the enumerator.

Set `KMI_MIDI_BACKEND=winmm` in the environment to force WinMM on a machine where WMS is installed (used for testing the WinMM path without uninstalling WMS).

## WM_DEVICECHANGE hot-plug detection for WinMM

`KmiDeviceChangeFilter` (a `QAbstractNativeEventFilter`) intercepts `WM_DEVICECHANGE` Win32 messages and starts a 400 ms single-shot debounce timer. On expiry the timer calls `slotPollDevices` (incremental diff), not `slotRefreshPortMaps` (full wipe), so already-connected ports are not spuriously disconnected. The filter is installed only on the WinMM path because WMS has its own push-based watcher.

## Firmware bootloader wait timeout set to 90 s

`FW_UPDATE_TIMEOUT_INTERVAL` was increased from 35 s to 90 s. On a VM with USB passthrough, the WinMM MIDI driver for the bootloader device can take >35 s to appear in `midiInGetNumDevs()` after USB connect. On real hardware the update completes in <10 s so the extra headroom is invisible.

## Block pre-1.0.0 firmware at the UI

When a connected device reports firmware version < 1.0.0, both editors show a blocking dialog, open the support URL, and quit. Pre-bootloader firmware cannot be updated through this editor; proceeding would leave the device unrecoverable.

## Console debug builds removed

The separate console-subsystem executable build (`BUILD_CONSOLE`) is no longer maintained. Log output goes to the diagnostic log file (`DiagnosticLogger`), which is accessible from the Help menu. This removed four VS Code build tasks and the `ConsoleExe` installer step.