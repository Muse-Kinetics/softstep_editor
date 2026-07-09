# Current Task

The active work is the SoftStep packetized firmware-update integration and the editor-side switch to the chunk-safe embedded firmware payload.

## Priority Order

1. Validate the packetized SoftStep firmware updater on hardware end-to-end using the current editor builds.
2. Use the new diagnostics to confirm packet phase transitions, identity replies, and raw SysEx packet numbering during update runs.
3. Keep both editor targets wired to the same shared updater surfaces and firmware resource names.
4. Separate releasable editor changes from any cleanup or follow-on work that is not required for the firmware-update path.

## Current State

Hardware-validated and committed (2026-07-08).

- Packetized firmware updater confirmed working on real hardware: 289 chunks, ~110 ms/chunk, per-packet ACKs, clean bootloader → firmware reboot.
- `shared/KMI_MDM` (branch `main`, commit `2447556`): portNameFix WMS early return committed.
- `shared/rtmidi` (branch `WMS`, commit `4c35e8d`): push-based watcher, openPort cache refresh, SysEx reassembly committed.
- Superproject updated to correct submodule pointers.
- Both editors build clean against `:/firmware/Softstep_Firmware_v%1.%2.%3-cs512.syx`.

## Immediate Next Step

No urgent blockers. Candidates:
- Release packaging and runtime DLL deployment for the Advanced Editor.
- Basic Editor parity (firmware update UI, WMS MIDI backend).
- Push `shared/KMI_MDM` and `shared/rtmidi` WMS branch commits to remote if desired.