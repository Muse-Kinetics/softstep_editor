# Mission

The SoftStep Editor repository contains the Basic and Advanced Qt editors used to configure SoftStep hardware, manage presets, troubleshoot device connectivity, and deliver firmware updates.

## Goals

- Ship stable Basic and Advanced editor builds on Windows and macOS.
- Keep firmware update behavior reliable across bootloader mode, application mode, and device reconnects.
- Preserve shared MIDI/device-manager behavior in `shared/KMI_MDM` without regressing existing products or transport paths.
- Keep embedded firmware assets and updater logic aligned with the actual firmware packaging pipeline.
- Run reliably on Windows machines both with and without the Windows MIDI Services (WMS) runtime installed, via automatic WinMM fallback.

## Current Architecture Direction

- Basic editor lives under `standalone/ezpz`; Advanced editor lives under `standalone/advanced`.
- Shared transport, firmware-update orchestration, diagnostics, and device-port handling live in `shared/KMI_MDM`.
- SoftStep firmware payloads are embedded from `shared/firmware/` and referenced from editor startup code.
- The packetized SysEx transport in `KMI_MDM` is the standing path for firmware updates; the legacy generic-SysEx transport remains available for non-firmware traffic.
- MIDI backend selection is dual: both editors probe Windows MIDI Services (WMS) at startup and fall back to WinMM automatically. `KMI_MIDI_BACKEND=winmm` forces WinMM for testing on machines with WMS installed. The same selection ladder is mirrored in `shared/rtmidi` (fork, `WMS` branch) and in the standalone `shared/sendsysex` CLI tool.
- `shared/rtmidi` is no longer off-limits — it now carries WMS support (push-based device watcher, SysEx UMP reassembly) plus a `isWindowsMidiServicesAvailable()` check that lets consumers compile both backends and choose at runtime.
- `shared/sendsysex` is a separate command-line MIDI SysEx / firmware-update utility (own family/device JSON database, own dual-backend probe) used for hardware validation and bring-up outside the Qt editors. It is not linked into either editor.
- Devices reporting firmware `< 1.0.0` are treated as unsupported: both editors show a blocking dialog, point the user to `https://support.musekinetics.com`, and quit rather than attempting an update. The old "trojan-horse" bootloader-install path for pre-1.0.0 firmware has been removed from `KMI_MDM`.

## Constraints

- Keep the packetized updater inside `KMI_MDM`; editor applications should select and consume it, not reimplement transport logic.
- Use prebuilt chunk-safe firmware SysEx assets instead of rebuilding PID headers inside the editor.
- Validate changes against real hardware when transport behavior or bootloader timing changes.
- When touching backend-selection logic, keep `KMI_ports.cpp` (KMI_MDM), `RtMidi.cpp` (rtmidi), and `midiBackend.cpp` (sendsysex) consistent — they independently implement the same WMS-probe/WinMM-fallback pattern and have drifted before.
