# SoftStep Workspace Baseline

This document is the working baseline for AI agents and assistants operating in this workspace. It is meant to reduce wrong assumptions before editing code, adding tooling, or changing build logic.

## Purpose

This repository contains the released SoftStep desktop editors for Keith McMillen SoftStep hardware. The active product is a pair of Qt desktop applications:

- SoftStep Basic Editor
- SoftStep Advanced Editor

Both apps are mature, shipping products and share a substantial amount of device, MIDI, firmware, and SysEx infrastructure.

## What Is Active Product Code

The main active source areas are:

- `standalone/ezpz/`
  - Basic editor Qt app.
  - qmake project: `softstepezpz.pro`
  - Target name: `SoftStep Basic Editor`
  - Version in project file: `3.0.5`

- `standalone/advanced/`
  - Advanced editor Qt app.
  - qmake project: `SoftStepAdvanced.pro`
  - Target name: `SoftStep Advanced Editor`
  - Version in project file: `3.0.5`

- `shared/`
  - Shared code used by both editors.
  - This is the most important dependency area outside the two app folders.

- `Content/`
  - Shipped content and resources such as presets, extras, icons, and firmware-related assets.

- `win-deploy/`
  - Windows installer packaging layout.

- `Signing and Notarization/`
  - macOS signing, packaging, and notarization assets and scripts.

## What Is Not Primary Product Source

These areas should not be treated as normal edit targets unless there is a specific reason:

- `standalone/build-*/`
  - Generated build output directories.
  - Useful for understanding prior Qt Creator kit names, but not authoritative source.

- `xx_archive/`
  - Historical or archived material.
  - Contains older externals, libraries, and experiments.

- `shared/xx_archive/`
  - Archived dependencies and old support code.

The default assumption should be: do not wire new tooling against archive folders unless explicitly required.

## Build System Reality

The active build system is qmake, not CMake.

Key facts:

- The authoritative app entry points are the two `.pro` files in `standalone/ezpz/` and `standalone/advanced/`.
- The workspace has some `CMakeLists.txt` files, but they belong to bundled third-party code such as RtMidi and are not the top-level application build system.
- The current product has been built historically in Qt Creator.
- Both app projects include deployment logic directly inside the `.pro` files.

Qt usage by app:

- Basic editor uses Qt widgets, svg, and network.
- Advanced editor uses Qt widgets plus qml, quick, and quickwidgets.

The advanced editor is the more complex target and includes hosted-mode logic, more dialogs, more forms, and a QML file named `CalibrationTable.qml`.

## Validated VS Code Setup On Windows

This workspace is now configured to build and launch both editors from VS Code on a Windows machine accessed over Remote SSH.

This setup is not theoretical. It was validated end-to-end against the current workspace.

### Toolchain That Actually Worked

The working Windows toolchain on this machine is:

- Qt root: `C:\qt6`
- Active Qt kit: `C:\qt6\6.3.2\msvc2019_64`
- qmake: `C:\qt6\6.3.2\msvc2019_64\bin\qmake.exe`
- windeployqt: `C:\qt6\6.3.2\msvc2019_64\bin\windeployqt.exe`
- OpenSSL: `C:\qt6\Tools\OpenSSL\Win_x64`
- Compiler environment: Visual Studio 2019 Community `vcvars64.bat`

Important consequence:

- A working Qt install alone was not enough.
- The MSVC environment had to be initialized before qmake and nmake were usable.

### Build Directory Convention That Mattered

The working VS Code tasks do not build in arbitrary scratch folders.

They use the existing Qt Creator-style build directory names already expected by the project:

- `standalone/build-softstepezpz-Desktop_Qt_6_3_2_MSVC2019_64bit-Debug`
- `standalone/build-SoftStepAdvanced-Desktop_Qt_6_3_2_MSVC2019_64bit-Debug`

This mattered because deployment logic and existing workflow assumptions were already aligned with those names.

### Why The VS Code Tasks Use Wrapper Scripts

The working VS Code build tasks are defined in `.vscode/tasks.json`, but the real command logic lives in `.vscode/run-msvc-qmake-task.cmd`.

That wrapper exists for a reason:

- Inline `cmd.exe /c ...` task commands were fragile when launched through VS Code terminals.
- Using `type: shell` caused quoting issues when PowerShell wrapped the command.
- Paths under `C:\Program Files (x86)\...` broke unless quoting was handled very carefully.

The stable pattern for this workspace was:

1. Use `type: process` tasks instead of shell tasks.
2. Point those tasks at a checked-in `.cmd` wrapper.
3. Let the wrapper call `vcvars64.bat`, then run qmake, then optionally run nmake.

That wrapper currently supports three actions:

- `configure`
- `build`
- `clean`

For other Windows qmake projects, this is the main pattern worth reusing.

### Current VS Code Build Model

The current workspace provides:

- configure task for Basic editor
- build task for Basic editor
- clean task for Basic editor
- configure task for Advanced editor
- build task for Advanced editor
- clean task for Advanced editor
- aggregate `Build SoftStep Editors` task

The verified build flow is:

1. Start in the intended build directory.
2. Initialize MSVC with `vcvars64.bat`.
3. Run qmake against the target `.pro` file.
4. Run `nmake /NOLOGO` for build or `nmake /NOLOGO clean` for clean.

### Why Normal Debug Launch Was Wrong Over Remote SSH

The initial `cppvsdbg` launch configurations did start the applications, but they started them in the Remote SSH host session, not on the Windows machine's visible desktop.

Observed behavior:

- VS Code could show a call stack.
- The app process existed.
- Nothing appeared on the remote machine's display.

The root cause was Windows session separation:

- The VS Code Remote SSH server and terminal were running in session `0`.
- The physically visible Windows desktop was session `1`.
- A GUI app launched from the SSH-hosted debug session stayed bound to the non-interactive session.

This is a general Windows remote-development constraint, not a SoftStep-specific bug.

### Current VS Code Launch Model

The current workspace intentionally separates launching from debugging.

There are now two kinds of launch configurations in `.vscode/launch.json`:

- `Launch SoftStep Basic Editor`
- `Launch SoftStep Advanced Editor`
- `Debug SoftStep Basic Editor (SSH Session)`
- `Debug SoftStep Advanced Editor (SSH Session)`

The meaning is different:

- `Launch ...` means: run the GUI app on the remote machine's visible desktop.
- `Debug ... (SSH Session)` means: run under the debugger inside the SSH-hosted session.

This distinction should be preserved if these configs are copied to other Windows GUI projects used over Remote SSH.

### Why The Launch Config Uses A Console-Session Helper

The normal `Launch ...` entries do not use `cppvsdbg`.

They use `type: node-terminal` and call `.vscode/launch-on-console.cmd`.

That helper:

- creates a temporary helper batch file
- sets Qt runtime environment variables
- creates an interactive scheduled task with `schtasks.exe`
- runs the program in the active interactive desktop session

This pattern was validated by launching GUI processes into Windows session `1`.

Two details mattered:

- `node-terminal` sends the command to the default shell, which was PowerShell in this environment
- PowerShell required the call operator `&` before a quoted `.cmd` path

So the working command form was:

- `& "${workspaceFolder}\.vscode\launch-on-console.cmd" ...`

Without the leading `&`, PowerShell treated the quoted path as a string instead of invoking it.

### What This Means For Other Qt Projects

If another Windows Qt project needs equivalent VS Code support, the reusable pattern is:

1. Confirm the real build system first.
  - qmake projects should be driven from `.pro` files.
  - Do not assume CMake just because bundled dependencies contain `CMakeLists.txt`.
2. Locate the exact Qt kit and compiler bootstrap script.
  - qmake path
  - Qt runtime bin path
  - OpenSSL path if needed
  - `vcvars64.bat` or equivalent MSVC environment script
3. Use checked-in wrapper scripts for Windows build tasks.
  - Avoid long inline command chains in `tasks.json`.
  - Prefer `type: process` tasks that call a `.cmd` file.
4. Keep build directories explicit.
  - Reuse the project's established out-of-source directory naming if one already exists.
5. Separate visible launch from debugger launch for GUI apps over Remote SSH.
  - Use a normal launcher that targets the interactive desktop session.
  - Keep debugger-specific launch configs separate and name them clearly.
6. Expect shell-specific quoting problems.
  - PowerShell and `cmd.exe` do not parse quoted commands the same way.
  - Test the exact invocation path that VS Code will use.

### Files That Encode The Working Pattern

The current validated VS Code setup is primarily captured in:

- `.vscode/tasks.json`
- `.vscode/launch.json`
- `.vscode/run-msvc-qmake-task.cmd`
- `.vscode/launch-on-console.cmd`
- `.vscode/dedicated-tasks.json`

If similar functionality needs to be added to another Qt project, these files are the best starting reference in this repository.

## Shared Modules That Matter

These shared modules are core to both editors:

- `shared/KMI_MDM/`
  - Device communication layer.
  - Firmware update support.
  - Port discovery and MIDI device management.
  - Troubleshooting and calibration UI support.
  - Update checking support.

- `shared/sysexcomposition/`
  - Legacy C-based SysEx composition and parsing code.
  - High-risk area because both editors depend on it for hardware communication.

- `shared/rtmidi/`
  - Bundled RtMidi source compiled directly into the apps.
  - Platform-specific MIDI backend support.

- `shared/firmware/`
  - Bundled firmware SysEx payloads and related qrc packaging.

- `shared/sysexmessages.h`
- `shared/tables.h`

If a change affects SoftStep communication, firmware update flow, MIDI port handling, or preset transmission, expect it to cross app boundaries through `shared/`.

## UI Structure

Both apps use Qt Designer `.ui` files and Qt resource collections.

Patterns to expect:

- macOS and Windows often have separate form variants.
  - Examples: `mainwindow.ui` and `mainwindowWin.ui`
- Resource collections are important build inputs.
  - Basic: `Resources.qrc` plus font resources
  - Advanced: `resources.qrc`, image resources, and font resources

Changing resources, forms, or qrc inputs can affect build behavior even if the C++ code is untouched.

## Runtime Data Model

Both apps store user-editable preset data in the OS application data location, not in-place inside the repository.

Observed behavior:

- Basic editor copies default preset JSON from embedded resources to `QStandardPaths::AppDataLocation`.
- Advanced editor does the same for its preset files, including hosted and standalone preset JSON.
- Both editors expose menu actions for opening the editor preset directory.

This matters because:

- Editing repo-side preset JSON files does not automatically affect an already-running installed/editor session.
- Bugs involving presets may require checking the per-user app data directory rather than the workspace copy.

## Settings and Identity

Each application sets a Qt application name and organization name in code.

Observed values:

- Organization: `Keith McMillen Instruments`
- App names:
  - `SoftStep Basic Editor`
  - `SoftStep Advanced Editor`

Qt `QSettings` is used by both apps for persisted application state.

## Update Check Behavior

Both apps integrate software update checks using the shared `KMI_updates` module.

Observed remote URL:

- `https://files.keithmcmillen.com/products/softstep/editor/softwareVersionCheck.json`

Implications:

- Network-linked update behavior is part of normal startup/application behavior.
- Tooling or debugging that assumes the apps are fully offline can be misleading.

## Platform-Specific Build Notes

The `.pro` files contain explicit platform logic.

Windows:

- Uses WinMM for MIDI.
- Links OpenSSL libraries from Qt tool directories.
- Contains deploy commands using `windeployqt`.
- Contains signing commands using `signtool.exe`.

macOS:

- Uses CoreMIDI, CoreAudio, and CoreFoundation.
- Contains logic for universal builds.
- Deployment is handled by the script in `Signing and Notarization/SoftStep - sign notarize package mac qt6 universal.sh`.

Linux:

- There is ALSA-related logic in the qmake files.
- Linux appears to be supported at the code/build-definition level, but the mature deployment paths in this workspace are clearly Windows and macOS.

Remote Windows note:

- Building over Remote SSH worked reliably after switching VS Code tasks to process-based wrappers.
- Launching a GUI app to the visible desktop required an interactive-session bridge and could not be solved by a normal debugger launch alone.

## Deployment Model

Windows deployment is packaged under `win-deploy/packages/` with three package roots:

- `com.keithmcmillen.softstepeditors.basic`
- `com.keithmcmillen.softstepeditors.advanced`
- `com.keithmcmillen.softstepeditors.content`

The `.pro` files include custom `deploy` targets guarded by the `DEPLOY` variable.

Important conventions in the qmake files:

- `BUILD_CONSOLE` is used to build a console variant first.
- `DEPLOY` enables packaging/signing behavior.
- The existing workflow assumes these are toggled intentionally rather than always on.

macOS deployment assets live under `Signing and Notarization/` and include:

- app icon assets
- entitlement plist
- DMG staging assets
- notarization/signing script

## Known High-Risk Areas

Agents should treat these as high-risk and avoid casual refactors:

- `shared/KMI_MDM/`
- `shared/sysexcomposition/`
- firmware `.syx` files in `shared/firmware/`
- deployment logic inside the `.pro` files
- installer package layout under `win-deploy/packages/`

Why these are risky:

- They affect both editors at once.
- They affect hardware communication and firmware behavior.
- They affect release packaging, signing, and installer generation.

## Practical Editing Guidance For Agents

Before making changes, assume the following:

1. Source of truth for app builds is qmake project configuration, not README prose.
2. Build output folders under `standalone/build-*` are disposable artifacts, not source.
3. Runtime presets live under the user app data location and may diverge from repo defaults.
4. Shared code changes likely impact both editors.
5. Windows and macOS each have nontrivial packaging requirements already encoded in project files and scripts.
6. Any version bump should be checked in both app `.pro` files.

## Suggested Orientation Path For Future Agents

If you need to work in this repository, orient in this order:

1. Read `standalone/ezpz/softstepezpz.pro` and `standalone/advanced/SoftStepAdvanced.pro`.
2. Inspect the relevant app `main.cpp` and `mainwindow.*` files.
3. Identify whether the task lives in app-specific code or in `shared/`.
4. Check whether the task also touches packaging or runtime content under `Content/`, `win-deploy/`, or `Signing and Notarization/`.
5. Ignore archive and generated build folders unless the task explicitly calls for historical comparison or artifact inspection.

## Verified Baseline At Time Of Writing

This summary is based on direct inspection of the workspace structure and representative source/build files, including:

- root `README.md`
- `CHANGELOG.md`
- both active `.pro` files
- both app `main.cpp` files
- both app `mainwindow.h` files
- both app `presetinterface.cpp` files
- shared `KMI_updates` module
- `.vscode/tasks.json`
- `.vscode/launch.json`
- `.vscode/run-msvc-qmake-task.cmd`
- `.vscode/launch-on-console.cmd`

If this document and the code disagree, trust the code.