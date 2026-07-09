# Decisions

## Packetized updater stays in `KMI_MDM`

The packetized SoftStep firmware transport lives in `shared/KMI_MDM`, not in editor-specific code. The editors select and feed the shared updater rather than implementing product-specific transport logic on their own.

## Split responsibilities between orchestration and parsing

`KMI_mdm` owns the state machine, readiness checks, send gating, and verification flow. `KMI_fwupdate` owns parsing a prebuilt firmware `.syx` into complete SysEx packets and exposing progress counters.

## Use prebuilt chunk-safe firmware assets

The editor should consume a prebuilt `-cs512` SysEx file rather than building PID headers or chunking ad hoc inside the app. This keeps firmware packet boundaries aligned with the converter output and flash-page-safe packaging.

## Preserve the legacy updater path

The packetized transport is additive. Legacy firmware-update behavior remains available so the shared transport can still serve products or flows that do not use the new packetized approach.

## Block queued SysEx during packetized transfer

Normal queued/chunked SysEx must not interleave with packetized firmware transfer. During active packetized update, generic queued SysEx is blocked until the firmware chunk is sent and the updater advances state.

## Add diagnostics where the transport actually changes state

The current diagnostic strategy is to log packetized phase transitions in the firmware console and to tag raw SysEx capture notes with phase and packet counters, rather than adding a separate UI-specific debugger.