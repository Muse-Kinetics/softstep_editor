# Commands

Operational commands for building, validating, and maintaining the SoftStep Editor repository.

## Project State

```powershell
Set-Location "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep"
git status --short
Set-Location .\shared\KMI_MDM
git status --short
```

## Build Editors

```powershell
Set-Location "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep"

# Advanced editor debug build
.\.vscode\run-msvc-qmake-task.cmd ..\advanced\SoftStepAdvanced.pro build "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep\standalone\build-SoftStepAdvanced-Desktop_Qt_6_3_2_MSVC2019_64bit-Debug"

# Basic editor debug build
.\.vscode\run-msvc-qmake-task.cmd ..\ezpz\softstepezpz.pro build "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep\standalone\build-softstepezpz-Desktop_Qt_6_3_2_MSVC2019_64bit-Debug"
```

## Validate Touched Files

```powershell
Set-Location "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep"
git diff -- shared/firmware/firmware.qrc standalone/advanced/mainwindow.cpp standalone/ezpz/mainwindow.cpp standalone/advanced/SoftStepAdvanced.pro standalone/ezpz/softstepezpz.pro

Set-Location .\shared\KMI_MDM
git diff -- KMI_mdm.cpp KMI_mdm.h KMI_fwupdate.cpp KMI_fwupdate.h
```

## Firmware Asset Sync

```powershell
# Generate firmware artifacts in the firmware repo first
Set-Location "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Firmware\SoftStep\Sysex\Hex to SysEx"
.\make_sysex.ps1

# Copy the chunk-safe asset into the editor repo
Copy-Item -LiteralPath "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Firmware\SoftStep\Sysex\Hex to SysEx\Softstep_Firmware_v2.0.6-cs512.syx" -Destination "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep\shared\firmware\Softstep_Firmware_v2.0.6-cs512.syx" -Force
```

## Hardware-Debug Logging

```powershell
# Raw SysEx capture defaults to sysex-capture.log in the current working directory.
# Override if needed before launching the editor.
$env:KMI_SYSEX_CAPTURE_FILE = "C:\temp\softstep-sysex-capture.log"
```

## Force the WinMM Backend (test the fallback path on a WMS-equipped machine)

```powershell
# Editors: use the VS Code launch configs
# "Launch SoftStep Basic Editor (Force WinMM)" / "Launch SoftStep Advanced Editor (Force WinMM)"
# — these set KMI_MIDI_BACKEND=winmm via .vscode/launch-and-tail.ps1 -MidiBackend winmm.

# Equivalent manual override for any editor or sendsysex invocation:
$env:KMI_MIDI_BACKEND = "winmm"

# sendsysex also accepts a direct CLI override:
.\sendsysex.exe --midi-backend winmm ...
```

## sendsysex (standalone CLI validation tool, `shared/sendsysex`)

```powershell
Set-Location "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep\shared\sendsysex"
cmake -B build
cmake --build build
# Binary lands in build/ (or build/Debug|Release on MSVC). See README.md for --fw-update usage
# and RELEASING.md for the packaged-release build/sign/zip flow.
```

## Notes

- Packetized firmware diagnostics live in `shared/KMI_MDM/KMI_mdm.cpp`.
- Use `Documentation/FIRMWARE_CHUNKING.md` as the design baseline for expected runtime behavior.
- `shared/rtmidi`, `shared/KMI_MDM`, and `shared/sendsysex` each independently implement the WMS-probe/WinMM-fallback pattern — keep backend-selection changes consistent across all three (see decisions.md).
- `.buddy-project/` has a `.gitignore` entry, but the files were already tracked when it was added, so they still show as `modified` in `git status` on every edit — check staging before any commit (see blockers.md).