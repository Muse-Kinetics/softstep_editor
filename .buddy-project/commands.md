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

# Advanced editor — debug
.\.vscode\run-msvc-qmake-task.cmd ..\advanced\SoftStepAdvanced.pro build "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep\standalone\build-SoftStepAdvanced-Desktop_Qt_6_3_2_MSVC2019_64bit-Debug"

# Advanced editor — release
.\.vscode\run-msvc-qmake-task.cmd ..\advanced\SoftStepAdvanced.pro build "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep\standalone\build-SoftStepAdvanced-Desktop_Qt_6_3_2_MSVC2019_64bit-Release"

# Basic editor — debug
.\.vscode\run-msvc-qmake-task.cmd ..\ezpz\softstepezpz.pro build "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep\standalone\build-softstepezpz-Desktop_Qt_6_3_2_MSVC2019_64bit-Debug"

# Basic editor — release
.\.vscode\run-msvc-qmake-task.cmd ..\ezpz\softstepezpz.pro build "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep\standalone\build-softstepezpz-Desktop_Qt_6_3_2_MSVC2019_64bit-Release"
```

## Force WinMM Backend (for testing on a WMS machine)

```powershell
# Set before launching the editor, or use the "Force WinMM" VS Code launch configs.
$env:KMI_MIDI_BACKEND = "winmm"
```

## Validate Touched Files

```powershell
Set-Location "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep"
git diff -- standalone/advanced/mainwindow.cpp standalone/ezpz/mainwindow.cpp `
           standalone/advanced/SoftStepAdvanced.pro standalone/ezpz/softstepezpz.pro `
           .vscode/launch.json .vscode/tasks.json .vscode/make-installer.ps1

Set-Location .\shared\KMI_MDM
git diff -- KMI_mdm.cpp KMI_ports.cpp KMI_ports.h KMI_fwupdate.cpp KMI_fwupdate.h
```

## Firmware Asset Sync

```powershell
# Generate firmware artifacts in the firmware repo first
Set-Location "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Firmware\SoftStep\Sysex\Hex to SysEx"
.\make_sysex.ps1

# Copy the chunk-safe asset into the editor repo
Copy-Item -LiteralPath "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Firmware\SoftStep\Sysex\Hex to SysEx\Softstep_Firmware_v2.0.6-cs512.syx" `
          -Destination "c:\Users\eric\KMI Dropbox\Eric Bateman\00_Editors\SoftStep\shared\firmware\Softstep_Firmware_v2.0.6-cs512.syx" -Force
```

## Notes

- Packetized firmware diagnostics live in `shared/KMI_MDM/KMI_mdm.cpp`.
- Use `Documentation/FIRMWARE_CHUNKING.md` as the design baseline for expected runtime behavior.
- Diagnostic log files are written to `%APPDATA%\Keith McMillen Instruments\<Editor Name>\logs\`. Open via Help → Open Log File Location.