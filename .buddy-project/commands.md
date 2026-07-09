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

## Notes

- Packetized firmware diagnostics live in `shared/KMI_MDM/KMI_mdm.cpp`.
- Use `Documentation/FIRMWARE_CHUNKING.md` as the design baseline for expected runtime behavior.
- Avoid changing `shared/rtmidi` during the current firmware-update work.