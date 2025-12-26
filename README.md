# SoftStep Editor

A cross-platform Qt6 application suite for configuring the SoftStep MIDI foot controller hardware. This editor provides both Basic and Advanced interfaces for customizing MIDI mappings, adjusting sensitivity, updating firmware, and managing presets for the SoftStep device.

## Features

- **Dual Interface Options**: Basic editor for simple configurations, Advanced editor for complex setups
- **MIDI Configuration**: Customize MIDI CC mappings, channels, and velocity curves for all SoftStep controls
- **Preset Management**: Save, load, and organize custom presets
- **Firmware Updates**: Update SoftStep firmware directly through the editor
- **Hardware Testing**: Test pad sensitivity and foot switch responsiveness
- **Cross-Platform**: Supports Windows, macOS (Intel/Apple Silicon), and possibly Linux
- **Template Library**: Includes templates for popular DAWs and performance setups

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
cd basic-editor-directory
qmake SoftStep_Basic.pro
make

# Build Advanced Editor  
cd advanced-editor-directory
qmake SoftStep_Advanced.pro
make

# For deployment builds (Windows installer creation)
make deploy
```

**Note**: The `make deploy` step is required for Windows deployment and installer creation when `DEPLOY=1` is set in the .pro files.

### Qt Creator
1. Open the Basic editor `.pro` file in Qt Creator
2. Configure your kit for the target platform
3. Build the project
4. Repeat for Advanced editor

## Deployment

### Windows Deployment

The project includes an automated Windows deployment system that creates signed installers for both Basic and Advanced editors.

#### Prerequisites
- Windows SDK (for signtool.exe)
- Qt Installer Framework (QtIFW)
- Code signing certificate configured in Windows certificate store

#### Basic Editor Deployment (Do First)
1. **Open Basic Editor project** (`softstepezpz.pro`) and update VERSION variable
2. **Delete all executables** in the release build directory
3. **Add deploy build step** in Qt Creator Projects tab:
   - Add "Make" step with target: `deploy`
4. **Build console version**:
   - Comment `DEPLOY = 1` line
   - Uncomment `BUILD_CONSOLE = 1` line
   - Build project
   - Rename executable from `"SoftStep Basic Editor.exe"` to `"SoftStep Basic Editor (debug console).exe"`
5. **Build release version**:
   - Comment `BUILD_CONSOLE = 1` line
   - Uncomment `DEPLOY = 1` line
   - Build project (triggers deployment process)

#### Advanced Editor Deployment (Do Second)
1. **Open Advanced Editor project** (`SoftStepAdvanced.pro`) and update VERSION variable
2. **Delete all executables** in the release build directory
3. **Add deploy build step** in Qt Creator Projects tab:
   - Add "Make" step with target: `deploy`
4. **Build console version**:
   - Comment `DEPLOY = 1` line
   - Uncomment `BUILD_CONSOLE = 1` line
   - Build project
   - Rename executable from `"SoftStep Advanced Editor.exe"` to `"SoftStep Advanced Editor (debug console).exe"`
5. **Build release version**:
   - Comment `BUILD_CONSOLE = 1` line
   - Uncomment `DEPLOY = 1` line
   - Build project (creates final installer)

The Advanced editor deployment process will:
- Copy both Basic and Advanced executables to installer package
- Run `windeployqt` to include Qt dependencies
- Sign both executables with your certificate
- Copy changelog and Content directory to installer package
- Create and sign the final installer using Qt Installer Framework

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
├── [Basic Editor Directory]/     # Basic SoftStep Editor Qt project
├── [Advanced Editor Directory]/  # Advanced SoftStep Editor Qt project
├── shared/                       # Shared libraries and components
│   ├── KMI_Ports/               # KMI device communication (submodule)
│   ├── KMI_MDM/                 # MIDI Device Manager (submodule)
│   ├── rtmidi/                  # RtMidi library (submodule)
│   └── KMI_Updates/             # Update system (submodule)
├── Content/                     # Application content and resources
│   ├── Documentation/           # User manuals and guides
│   ├── Presets/                # Factory presets
│   └── Templates/              # Performance templates
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
