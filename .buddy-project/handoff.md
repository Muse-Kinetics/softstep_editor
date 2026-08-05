# Handoff

## Summary

The SoftStep packetized firmware-update path is complete and hardware-validated, and the follow-on WMS/WinMM dual-backend rollout is also complete and hardware-validated.

- The updater uses a packetized transport in `shared/KMI_MDM` with per-chunk readiness ACKs.
- The packet parser/progress tracker lives in the `KMI_fwupdate` helper.
- Generic queued SysEx is blocked while packetized firmware transfer is active; the legacy generic-SysEx transport itself remains available for non-firmware traffic.
- Both editors point at the chunk-safe `-cs512` embedded SoftStep firmware asset.
- MIDI backend selection is dual everywhere it matters: `shared/KMI_MDM`, `shared/rtmidi` (`WMS` branch), and the standalone `shared/sendsysex` tool all probe Windows MIDI Services (WMS) at startup and fall back to WinMM automatically. `KMI_MIDI_BACKEND=winmm` forces WinMM for testing on WMS-equipped machines.
- `shared/KMI_MDM` adds WinMM hot-plug detection (`KmiDeviceChangeFilter` + 400ms debounce on `WM_DEVICECHANGE`) and a 90s bootloader-appearance timeout (was 35s) to cover slow VM enumeration.
- Both editors now block devices reporting firmware `< 1.0.0` with a blocking "unsupported" dialog + support-URL launch + quit, replacing the old bootloader-install recovery attempt for that case.
- `shared/sendsysex` is a new standalone-tool submodule (own device/family JSON database, chunk-aware sending, release packaging) used for hardware bring-up/validation independent of the Qt editors — not linked into either editor build.

## Build Status

- Advanced debug build: validated after packetized transport and `-cs512` resource changes.
- Basic debug build: validated after restoring `softstepezpz.pro` and rebuilding.
- Release build tooling exists in the repo, but hardware validation should use the currently known-good debug builds unless release runtime packaging is being tested intentionally.
- VS Code: "Force WinMM" launch configs added for both editors (Release variants; sets `KMI_MIDI_BACKEND=winmm` via `launch-and-tail.ps1 -MidiBackend winmm`) for testing the WinMM fallback path on WMS-equipped dev machines. Console-build tasks/variants removed as unmaintained.

## Worktree Notes

- All submodules are committed and the superproject points to the correct HEADs as of 2026-07-28.
- `shared/KMI_MDM` (branch `main`, commit `c5c549b`): packetized updater, `portNameFix` WMS early return, WinMM hot-plug detection + dual-backend port consistency, pre-1.0.0 legacy install path removed.
- `shared/rtmidi` (branch `WMS`, commit `b79b83e`): push-based watcher cache, `openPort()` cache refresh, SysEx reassembly, `isWindowsMidiServicesAvailable()` dual-backend compile support.
  - Has leftover Dropbox conflict-copy files in `android/` — do not stage or commit them (see blockers.md).
- `shared/sendsysex` (new submodule, `v0.9.0`, commit `503451a`): dual-backend CLI tool, validated on real BopPad and SoftStep hardware over both WMS and WinMM.
- `.buddy-project/` has a `.gitignore` entry, but the files were already tracked when it was added, so they still show as `modified` in `git status` on every edit — this incomplete detachment is what caused the earlier accidental-inclusion incident (commit `4e60119f`, reverted in `0f78d86b`). See blockers.md.
- Untracked `.github/copilot-instructions.md` at repo root — was added then untracked again across two cleanup commits; still present on disk, needs a final decision (see blockers.md).

## Hardware Validation — COMPLETE

- **2026-07-08 — packetized firmware update:** Bootloader detected and port opened correctly after `midi_in` recreation on Windows. 289 chunks sent at ~110 ms/chunk with per-packet readiness ACK. Device rebooted into application firmware and reconnected as `SoftStep Control Surface`. Editor reported `Firmware Update Successful!`.
- **2026-07-27/28 — WMS/WinMM dual-backend rollout:** BopPad and SoftStep firmware updates completed successfully over both WMS and WinMM (WinMM forced via `--midi-backend`/`KMI_MIDI_BACKEND`) using `sendsysex`. Editor-side dual-backend and hot-plug detection changes point at the same validated `KMI_MDM`/`rtmidi` commits.

## Pickup Guidance

The firmware-update path and the dual-backend MIDI rollout are both complete. Next work is likely release packaging (see `shared/sendsysex/RELEASING.md` for a reference pattern) or the small `.github/` cleanup decision in blockers.md. Read `Documentation/FIRMWARE_CHUNKING.md` before touching the packetized updater.
