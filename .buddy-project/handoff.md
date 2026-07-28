# Handoff

## Summary

The SoftStep packetized firmware-update path is complete and hardware-validated.

- The updater uses a packetized transport in `shared/KMI_MDM` with per-chunk readiness ACKs.
- The packet parser/progress tracker lives in the new `KMI_fwupdate` helper.
- Generic queued SysEx is blocked while packetized firmware transfer is active.
- Both editors point at the chunk-safe `-cs512` embedded firmware asset.
- `shared/rtmidi` uses the Windows MIDI Services (WMS) backend on the `WMS` branch.
- A push-based `MidiEndpointDeviceWatcher` replaces polling; ports are cached statically and refreshed live in `openPort()` to handle the `midi_in` recreate-after-close timing gap.

## Build Status

- Advanced debug build: validated after packetized transport and `-cs512` resource changes.
- Basic debug build: validated after restoring `softstepezpz.pro` and rebuilding.
- Release build tooling exists in the repo, but hardware validation should use the currently known-good debug builds unless release runtime packaging is being tested intentionally.

## Worktree Notes

- All submodules are committed and the superproject points to the correct HEADs.
- `shared/KMI_MDM` (branch `main`): packetized updater + `portNameFix` WMS early return.
- `shared/rtmidi` (branch `WMS`): push-based watcher cache, `openPort()` cache refresh, SysEx reassembly.
- The `shared/rtmidi` WMS branch has Dropbox conflict files (android/) left unstaged intentionally — do not stage or commit them.

## Hardware Validation — COMPLETE (2026-07-08)

Full firmware update confirmed on real hardware:
- Bootloader detected and port opened correctly after `midi_in` recreation on Windows.
- 289 chunks sent at ~110 ms/chunk with per-packet readiness ACK.
- Device rebooted into application firmware and reconnected as `SoftStep Control Surface`.
- Editor reported `Firmware Update Successful!`.

## Pickup Guidance

The firmware update path is complete. Next work is likely release packaging or Basic Editor parity. Read `Documentation/FIRMWARE_CHUNKING.md` before touching the packetized updater.