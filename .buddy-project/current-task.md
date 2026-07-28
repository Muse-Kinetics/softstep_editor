# Current Task

No active development task. The editors are stable and shipped at v3.0.6.C.

## Current State

All major work from 2026-07 sessions is committed and pushed.

- Packetized firmware updater: hardware-validated (2026-07-08), shipping.
- WMS + WinMM dual-backend: both compile in; runtime selects WMS if available, else WinMM. `KMI_MIDI_BACKEND=winmm` forces WinMM.
- WinMM hot-plug detection: `KmiDeviceChangeFilter` intercepts `WM_DEVICECHANGE`; debounced 400 ms to `slotPollDevices`. Tested on Win11 21H2 VM.
- Bootloader wait timeout: increased to 90 s to accommodate slow VM MIDI driver registration.
- Console debug builds removed from both editors and deployment tooling.
- Pre-1.0.0 firmware: blocked at the UI with a support-URL dialog.
- `shared/KMI_MDM`: branch `main`, commit `c5c549b`.
- `shared/rtmidi`: branch `WMS`, commit `b79b83e` (merged with KMI_RtMIDI/WMS, pushed 2026-07-27).
- Superproject: `e571c2c3` — deployment versions updated, rtmidi pointer updated.

## Next Candidates

- macOS release build validation (Qt 6.9.2 universal binary).
- Windows installer smoke-test with the current v3.0.6.C release exes.
- Clean up Dropbox conflict files in `shared/rtmidi/android/` (see blockers.md).