# Blockers

## No active functional blockers

All work from 2026-07 sessions is committed and pushed. Editors ship at v3.0.6.C.

## `shared/rtmidi` dirty working tree (cosmetic only)

Dropbox left conflict copies of android source files in `shared/rtmidi/android/` (e.g. `RtMidi (Eric Bateman's conflicted copy ...).cpp`). The originals are also staged as deleted. This makes the submodule appear dirty (`-dirty` suffix in `git submodule status`) but does not affect Windows or macOS builds. The conflict copies can be deleted manually when convenient; do not stage or commit them.

## macOS release build not recently re-validated

The macOS Qt 6.9.2 universal binary build has not been re-validated since the 2026-07 changes (dual-backend build, WM_DEVICECHANGE filter, timeout increase). macOS does not use WinMM so the behavioural risk is low, but a clean macOS build run is warranted before the next macOS release.