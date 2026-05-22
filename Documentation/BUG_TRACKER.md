# SoftStep Bug Tracker

## Current Focus (Handoff)

Current validation and bug-fix focus areas are:

- Continue monitoring editor/device comms stability, especially in Hosted mode
- Resolve Hosted mode port access and availability issues
- Validate the full Hosted-mode expression pedal path after the latest firmware-side calibration fix
- Continue general bug fixing and regression validation across Basic and Advanced editors

Notes for incoming AI/LLM sessions:

- Prefer the Release `Launch SoftStep ... Editor` configurations plus the matching `Tail ... Log` task when GUI behavior must be correlated with logs on the visible Windows desktop
- Prefer file-based app logging over the older console-build launch path unless a task explicitly requires the console variant
- Correlate observed behavior in editors with shared MIDI/transport code in `shared/`
- Correlate pedal issues across both repositories: editor-side Hosted scaling/state in this repo, raw-vs-calibrated pedal transmission in `00_Firmware/SoftStep`
- Use temporary fixtures in `shared/test_winmm/` for backend investigation when useful
- The shared `KMI_MDM` logger rollout is intended to remove packaged `(... Debug Console)` editor binaries, but that packaging cleanup is a later commit
- Firmware chunking is the next planned firmware-update commit; treat `Documentation/FIRMWARE_CHUNKING.md` as design baseline, not implemented behavior

## Open Bugs

- **TRACK-001: Hosted mode comms monitoring**
	- **Editor:** Advanced (primary), Basic (secondary checks)
	- **Severity:** Medium
	- **Status:** In Progress
	- **Description:** Continue monitoring and validating comms reliability while addressing Hosted mode issues.

- **TRACK-002: Hosted mode port access issues**
	- **Editor:** Advanced
	- **Severity:** High
	- **Status:** In Progress
	- **Description:** Investigate and fix cases where expected ports are missing, unavailable, or unstable in Hosted mode workflows.

- **TRACK-003: Expression pedal usage in Hosted mode**
	- **Editor:** Advanced
	- **Severity:** High
	- **Status:** In Progress
	- **Description:** Continue validation of expression pedal calibration persistence and runtime pedal mapping/behavior in Hosted mode. The editor-side calibration initialization bug is fixed, and the firmware now applies standalone-style pedal calibration before sending Hosted-mode pedal CC data. Hardware validation is still pending.

## Resolved Bugs

### BUG-001: Expression pedal loses calibration in Hosted mode
- **Editor:** Advanced
- **Severity:** Medium
- **Reported:** 2026-04-20
- **Status:** Fixed
- **Description:** In Hosted mode, the expression pedal doesn't have the full range unless calibrated each time. Calibration must be performed every time Hosted mode is entered. Works correctly in Standalone mode.
- **Root Cause:** Two-part system: firmware gets calibration min/max via sysex (works), but the editor-side `Pedal` class (which scales CC#86 in Hosted mode) was never initialized with saved calibration values on startup. The old file-based `slotLoadTableOnStartup()` in settings.cpp was gutted, and the `signalInitPedalTable` connection to `key[0]->dataCooker->pedal` was commented out. On each launch, `slotResetCalibrate()` set a default linear 0-127 table, overwriting any saved calibration. A separate firmware-side issue also existed later in the pipeline: Hosted mode was transmitting raw pedal sensor values instead of the calibrated value used in Standalone mode.
- **Fix:** In `mainwindow.cpp`: (1) After `slotResetCalibrate()`, load `pedal_calibration_min`/`max` from settings JSON and apply directly to `key[0]->dataCooker->pedal->pedalValueListMin/Max`. (2) Added lambda on `pedalCal::signalSaveCalibration` to update Pedal min/max immediately when the user saves new calibration. In the firmware repo, the Hosted-mode pedal path now reuses the same calibration helper as Standalone mode before sending the expected Hosted pedal CC. End-to-end hardware validation should still be treated as pending.

### BUG-002: Crash when sending empty setlist to SoftStep
- **Editor:** Advanced
- **Severity:** High
- **Reported:** 2026-04-20
- **Status:** Fixed
- **Description:** If the setlist is empty and the user sends it to the SoftStep, the Advanced Editor crashes.
- **Root Cause:** When setlist is empty, `send_standalone_image()` in download.c returns early (count==0), so the global `image` pointer is never allocated. Back in sysexcomposer.cpp, `slotSettingsSent()` calls `free(settings)` (OK), then sends and frees `image` — which is uninitialized, causing a crash.
- **Fix:** Added guard in `MainWindow::slotUpdatePresets()` — if `setlistMapList` is empty, show a `QMessageBox::warning` and return early before calling `slotComposeAttributeListFromSetlist`.
