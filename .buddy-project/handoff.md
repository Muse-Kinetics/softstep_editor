# Handoff

## Summary

Editors are stable at v3.0.6.C. Firmware update, dual-backend MIDI, and WinMM hot-plug detection are complete and shipped.

- Packetized firmware updater: hardware-validated, shipping. 289 chunks, ~110 ms/chunk, per-packet ACKs.
- WMS + WinMM dual-backend: both compiled in; runtime selects WMS if available, else WinMM.
- WinMM hot-plug detection: `KmiDeviceChangeFilter` intercepts `WM_DEVICECHANGE`; 400 ms debounce to `slotPollDevices`.
- Firmware bootloader wait timeout: 90 s (up from 35 s) to handle slow VM MIDI driver registration.
- Pre-1.0.0 firmware blocked at the UI level with a support-URL dialog.
- Console debug builds removed; log output goes to the diagnostic log file.

## Submodule HEADs

- `shared/KMI_MDM`: branch `main`, commit `c5c549b` — "WinMM hot-plug detection + dual-backend port consistency".
- `shared/rtmidi`: branch `WMS`, commit `b79b83e` — merged with KMI_RtMIDI/WMS, pushed 2026-07-27.

## Superproject

- HEAD: `e571c2c3` — "Update deployment, commit rtmidi fork". Pushed to `github/main`.
- `shared/rtmidi` working tree is dirty due to Dropbox conflict files in `android/` — see blockers.md. The `-dirty` suffix does not affect builds.

## Build Status

- Windows release builds: v3.0.6.C, clean. WMS + WinMM dual-backend builds validated on Win11 24H2 (WMS) and Win11 21H2 VM (WinMM).
- macOS release build: Qt 6.9.2 universal binary; not recently re-validated after 2026-07 changes.
- Debug builds: working. Release builds preferred for hardware testing.

## Pickup Guidance

- Read `Documentation/FIRMWARE_CHUNKING.md` before touching the packetized updater.
- `KMI_MIDI_BACKEND=winmm` env var forces WinMM for testing on a WMS machine; use the "Force WinMM" VS Code launch configs.
- The `shared/rtmidi` WMS branch has untracked Dropbox conflict copies in `android/` — do not stage or commit them.