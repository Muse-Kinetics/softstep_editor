# SoftStep Editor

A cross-platform Qt6 application suite for configuring the SoftStep MIDI foot controller hardware. This editor provides both Basic and Advanced interfaces for customizing MIDI mappings, adjusting sensitivity, updating firmware, and managing presets for the SoftStep device.

## Features

- **Dual Interface Options**: Basic editor for simple configurations, Advanced editor for complex setups
- **MIDI Configuration**: Customize MIDI CC mappings, channels, and velocity curves for all SoftStep controls
- **Preset Management**: Save, load, and organize custom presets
- **Firmware Updates**: Update SoftStep firmware directly through the editor, using a packetized, chunk-safe transfer
- **Windows MIDI Services (WMS)**: Uses WMS when available, with automatic fallback to WinMM on machines without the WMS runtime installed
- **Hardware Testing**: Test pad sensitivity and foot switch responsiveness
- **Cross-Platform**: Supports Windows, macOS (Intel/Apple Silicon), and possibly Linux
- **Template Library**: Includes templates for popular DAWs and performance setups

Current version: **3.0.7** (Editor), **2.0.7** (Firmware). See [CHANGELOG.md](CHANGELOG.md) for release notes.

## System Requirements

### Minimum Requirements
- **Qt 6.3.2 or later** (Qt 6.9.2 recommended)
- **Windows**: Windows 10 or later
- **macOS**: macOS 10.15 (Catalina) or later
- **Linux**: ALSA-compatible system

### Build Requirements
- Qt6 development environment
- C++ compiler with C++17 support
- Platform-specific MIDI libraries (automatically linked)

## Building from Source

### Prerequisites
1. Install Qt 6.3.2 or compatible version
2. Clone this repository with submodules:
   ```bash
   git clone --recursive <repository-url>
   cd SoftStep
   ```
3. Ensure you have the required development tools for your platform

### Building
```bash
# Build Basic Editor
cd standalone/ezpz
qmake softstepezpz.pro
make

# Build Advanced Editor
cd standalone/advanced
qmake SoftStepAdvanced.pro
make
```

Installer creation is handled separately by `.vscode/make-installer.ps1` (see Windows Deployment below) — the `.pro` files themselves have no deploy-related build steps.

### Qt Creator
1. Open the Basic editor `.pro` file (`standalone/ezpz/softstepezpz.pro`) in Qt Creator
2. Configure your kit for the target platform
3. Build the project
4. Repeat for the Advanced editor (`standalone/advanced/SoftStepAdvanced.pro`)

## Deployment

### Windows Deployment

The project includes an automated Windows deployment system that creates signed installers for both Basic and Advanced editors. All deployment logic lives in `.vscode/make-installer.ps1`, driven by VS Code tasks — the `.pro` files have no deploy-related qmake targets.

#### Prerequisites
- Windows SDK (for signtool.exe)
- Qt Installer Framework (QtIFW)
- Code signing certificate configured in Windows certificate store

#### Steps
1. Build both editors in Release configuration (VS Code tasks "Build SoftStep Basic Editor Release" / "Build SoftStep Advanced Editor Release", or the qmake/make commands above).
2. Run the VS Code task **"Deploy SoftStep Windows Installer"** (chains the Release builds → `make-installer.ps1`), or **"Deploy SoftStep Windows Installer (No Signing)"** for an unsigned dry run.

`make-installer.ps1` will:
- Read the installer version from `SoftStepAdvanced.pro`'s `VERSION` line and sync it into `win-deploy/config/config.xml` and each package's `meta/package.xml`.
- Copy both editor executables into their installer package staging directories, sign them, run `windeployqt`, and copy the OpenSSL runtime DLLs.
- Refresh the installer's Content package from the repo's `Content/` directory and `CHANGELOG.md`.
- Build the installer with `binarycreator.exe` and sign it.

The resulting installer detects an existing SoftStep Editors installation at the target directory and offers to remove it before proceeding, rather than failing outright.

### macOS Deployment

macOS deployment creates universal binaries for both Intel and Apple Silicon.

#### Prerequisites
- Apple Developer account and certificates
- Environment variables configured:
  ```bash
  export DEVELOPER_ID="Developer ID Application: Your Name (TEAMID)"
  export APPLE_KEYCHAIN_PROFILE="YourKeychainProfile"
  export APPLE_TEAM_ID="TEAMID"
  export APPLE_ID="your-apple-id@email.com"
  export APPLE_APP_PASSWORD="app-specific-password"
  ```

#### Steps
1. Build both Basic and Advanced applications in Qt Creator
2. Navigate to the signing directory:
   ```bash
   cd "Signing and Notarization"
   ```
3. Run the deployment script:
   ```bash
   ./SoftStep\ -\ build\ sign\ package\ mac\ qt6\ universal.sh
   ```

The script will:
- Create universal binaries for both editors (Intel + Apple Silicon)
- Sign both applications with your Developer ID
- Create DMG installers
- Notarize the packages with Apple
- Provide ready-to-distribute signed packages

## Project Structure

```
SoftStep/
├── standalone/
│   ├── ezpz/                    # Basic SoftStep Editor Qt project
│   └── advanced/                # Advanced SoftStep Editor Qt project
├── shared/                      # Shared libraries and components
│   ├── KMI_MDM/                 # MIDI Device Manager (submodule)
│   ├── rtmidi/                  # RtMidi library (submodule)
│   ├── sendsysex/               # Standalone SysEx/firmware CLI tool (submodule)
│   └── firmware/                # Firmware .syx assets embedded into both editors
├── Content/                     # Application content and resources
│   ├── Documentation/           # User manuals and guides
│   ├── Presets/                # Factory presets
│   └── Templates/              # Performance templates
├── win-deploy/                  # Windows installer configuration (QtIFW)
└── Signing and Notarization/   # macOS deployment scripts
```

## Contributing

Pull requests are welcome! However, all updates should be thoroughly tested with actual SoftStep hardware on both macOS and Windows platforms before submission.

### Testing Requirements
- Test all MIDI functionality with connected SoftStep hardware
- Verify preset loading/saving works correctly in both editors
- Test firmware update process (if applicable)
- Ensure UI responsiveness across different screen sizes
- Validate on both macOS and Windows
- Test both Basic and Advanced editor functionality

### Hardware Requirements for Contributors
Contributors need access to SoftStep hardware for testing. If you're interested in contributing but don't have hardware access, you can contact us about discount hardware availability:

**Email**: contact@musekinetics.com

## Support

SoftStep3 is currently available for sale through Muse Kinetics with a one year warranty that includes customer support, however this source code is provided as-is with no warranty. For product support please visit https://support.musekinetics.coml. For feature requests, or bug reports, please create an issue in this repository and encourage other open source developers to assist you.

## License
The SoftStep Advanced and Basic editors are distributed under the Mozilla Public License 2.0 (MPL-2.0). You may use, modify, and redistribute the source as long as each modified source file continues to carry the MPL notice and the file is made available under the MPL. See [LICENSE](LICENSE) for the complete terms.

Unless otherwise noted, all contributions are accepted under the MPL-2.0 with the header:

```
// Copyright (c) 2025 KMI Music, Inc.
// This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
// If a copy of the MPL was not distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
```

## Third-Party Licenses

### Qt Framework

This application is built using the Qt framework, which is available under the GNU Lesser General Public License (LGPL) v3.

- **Qt Website**: https://www.qt.io/
- **Qt Open Source License**: LGPL v3
- **Qt Source Code**: https://www.qt.io/download-open-source
- **Qt License Details**: https://www.qt.io/licensing/open-source-lgpl-obligations

The SoftStep Editor applications dynamically link with Qt libraries and do not modify the Qt framework source code. Users have the right to obtain, modify, and redistribute the Qt libraries under the terms of the LGPL v3 license.

### Qt LGPL v3 Summary

The Qt framework is licensed under LGPL v3, which allows:
- Use in both open source and commercial applications
- Dynamic linking without affecting your application's license
- Distribution of Qt libraries alongside your application

For complete LGPL v3 license terms, see: https://www.gnu.org/licenses/lgpl-3.0.html

## Version History

See [CHANGELOG.md](CHANGELOG.md) for detailed version history and release notes. 
