# Mission

The SoftStep Editor repository contains the Basic and Advanced Qt editors used to configure SoftStep hardware, manage presets, troubleshoot device connectivity, and deliver firmware updates.

## Goals

- Ship stable Basic and Advanced editor builds on Windows and macOS.
- Keep firmware update behavior reliable across bootloader mode, application mode, and device reconnects.
- Preserve shared MIDI/device-manager behavior in `shared/KMI_MDM` without regressing existing products or transport paths.
- Keep embedded firmware assets and updater logic aligned with the actual firmware packaging pipeline.

## Current Architecture Direction

- Basic editor lives under `standalone/ezpz`; Advanced editor lives under `standalone/advanced`.
- Shared transport, firmware-update orchestration, diagnostics, and device-port handling live in `shared/KMI_MDM`.
- SoftStep firmware payloads are embedded from `shared/firmware/` and referenced from editor startup code.
- The new SoftStep firmware path uses a packetized SysEx transport in `KMI_MDM` while preserving the legacy transport for compatibility.

## Constraints

- Do not touch `shared/rtmidi` as part of the current firmware-update work.
- Keep the packetized updater inside `KMI_MDM`; editor applications should select and consume it, not reimplement transport logic.
- Use prebuilt chunk-safe firmware SysEx assets instead of rebuilding PID headers inside the editor.
- Validate changes against real hardware when transport behavior or bootloader timing changes.