#### SoftStep Editor and Firmware Changelog

### Editor 3.0.5, Firmware 2.0.5 (2025-03-05)
- New Features:
	- Hardware
		- New "Foot On (Single)" and "Foot Off (Single)" modlined sources (see advanced editor)
		- When loading a preset > 9, the 1 LED now flashes
		- Standalone preset name now displays on SoftStep hardware when exiting hosted mode
	- Advanced editor: 
		- Added "Foot On (Single)" and "Foot Off (Single)" modlined sources to standalone and hosted. Not available for Nav Pad
			- "Foot On" and "Foot Off" have always been a boolean representing the state of the key
			- The "(Single)" variations now only trigger once (value 127), either when the key turns on or when it turns off. 
		- Added File->Reset Presets to Default
		- Added "Banks" default hosted and standalone presets to demonstrate how to send Bank MSB/LSB messages
		- Added "Tutorials..." to help menu
	- Basic Editor: 
		- Added File->Open Editor Preset Directory
		- Added File->Reset Presets to Default
- Bug Fixes:
	- Hardware:
		- Fixed an overindexing bug that caused the nav pad to crash when presets 15 or 16 were loaded 
		- Added better bounds check when presets load, fixes edge cases where presets would seem to dissapear
		- Both Bank MSB and LSB messages are now properly sent
	- Advanced Editor: 
		- FixedHosted/Standalone mode correctly retained when app closes/reopens
		- Exiting pedal calibration during hosted mode no longer puts hardware in standalone (out of sync with editor)
		- Fixed Hosted Mode Smoothing bug that would cause bad data to get caught in a loop
	- Basic Editor: 
		- Fixed a bug where the app would crash (not open) if the presets json file wasn't found.
		- Added "Tutorials..." to help menu

### Editor 3.0.4, Firmware 2.0.4 (2024-12-13)
- Bug Fixes:
	- Basic editor now updates to the correct firmware 2.0.4 instead of 2.0.3
	- Basic editor backlight checkbox now works

### Editor 3.0.3, Firmware 2.0.4 (2024-10-01)
- New Features/Changes - Advanced Editor Only
	- Added "Reset Settings to Default" to hardware menu, also updates settings.json and settings tab ui
	- Added "Reset to Default" to settings Keys tab
	- Updated Settings defaults to less sensitive values
	- Fixed settings SysEx update timer to a single update per second
	- Misc. bug fixes and improvements

### Editor 3.0.2, Firmware 2.0.3 (2024-04-26)
- New Features/Changes
	- Complete overhaul of USB MIDI driver. SoftStep now uses the same driver as KMI's latest products.
		- SoftStep3 uses new USB MIDI port names: "Softstep Control Surface", "SoftStep TRS MIDI Out", "SoftStep CV Out"
		- Legacy hardware (SoftStep1/2) uses port names "SoftStep Control Surface" and "SoftStep Expander"
	- Improved key scanning, gain (sensitivity adjustments), and sensor calibration. 
	- Added per device serial numbers which will the OS to differentiate between multiple SoftSteps
	- Faster device boot time
	- Improvements to firmware update process:
		- Bootloader flash memory is now LOCKED
		- Firmware updates have been slowed down to accomodate older systems
	- Presets are now stored in the OS Application Data Directory rathern than the application directory/package. 
	- Basic Editor:
		- Fixes to the UI, ie you can now browse different presets when a factory preset is selected
	- Advanced Editor:
		- SoftStep 3 UI additions:
			- Added CV Out routing controls to main window
			- Added Backlight Brightness control to Settings
		- Added Expression Pedal Calibration to the Editor Hardware menu
			- User can define min/max values to scale expression pedal input to output
			- Added table assignment (linear, exponential, log, etc). This is a global setting that will always be applied to the expression pedal before preset modlines.
		- Added CV Calibration to the Editor Hardware Menu
			- User can calibrate Octaves (6 values per CV out for 0/1/2/3/4/5V), or Notes (calibrate every note individually)
		- Added RANDOM as a modline source and table (user feature request)
		- Added diatonic scales/modes to tables
		- Note Live now has a transpose option, useful when using quantized scale tables
		- Added Program Change Preset Control dropdown to Settings tab (user feature request)
			- This is a global setting for all presets that determines which MIDI channel SoftStep listens to for Program Chance, CC, and NRPN commands. 
		- Added an experimental/advanced feature where the editor can talk to devices with older firmware. 
		- Key LED backlights can now be dimmed rather than just set to on/off (user feature request)
		- Modline LEDs can now set both red and green to ON, making amber
		- Updated factory presets
		- The editor now remembers and loads the last preset that was being edited in both hosted and standalone mode (user feature request)
- Bug Fixes:
	- Fixed a bug where adding expression pedal modlines to the Nav Pad could corrupt key states, causing erratic behavior
	- Fixed a bug in key slewing (delay) that could temporarily crash the device
	- Fixed a bug where sending presets to the device would sometimes cause it to hang
	- Lots of memory optimizations and code cleanup
	- Lots of UI fixes, tweaks, and improvements



### Editor 2.1.1, Firmware 1.0.4 (2022-10-12)
- Public release

### Editor 2.1.0H, Firmware 1.0.4 (2022-07-08)
- Bug Fixes:
	- Fixed note_set bug that didn't set velocity or channel correctly
	- Fixed combobox and UI issues
	- Fixed missing preset file errors
	- Fixed a bug where certain standalone presets would trigger hosted mode messaging

### Editor 2.1.0E, Firmware 1.0.3 (2022-05-16)
- New Features/Changes:
	- MacOS now supports Apple Silicon (M1) and legacy Intel devices, MacOS versions 10.11 to 12.3.1
	- Added Connection Troubleshooter (Help -> Troubleshoot Connection)
- Bug Fixes:
	- Firmware 1.0.3
		- Fixed a bug that would cause a bootloader/application loop on load
		- Fixed a bug that would reset factory settings to defaults after power cycle 

### Editor 2.1.0, Firmware 1.0.0 (2022-04-06)
- New Features/Changes:
	- The editor will install a new bootloader into firmware before upgrading to 1.0.0. This change is permanent and protects firmware from getting corrupted, but breaks compatibility with older editors on older operating systems (ie MacOS High Sierra or earlier). More details and extra firmware images can be found in the "Extras\Firmware SysEx Files" folder.
	- Overhauled editor MIDI backend using RtMidi, now builds/runs on modern operating systems.
	- Application scaled up 1.5x, added support for high dpi (4k) monitors.
	- Hosted mode now responds to program changes sent to SoftStep Share vitrual MIDI port on channel 16.
	- The Windows editor now detects and alerts you when attempting to open a MIDI port that is being used by another application. Users should keep bugging Microsoft to upgrade their MIDI drivers to support multi-client access. 
- Bug Fixes:
	- Replaced old low-res UI images with vector fonts.

### Editor 2.0.1, Firmware 0.9.3 (2014-04-03)
- Bug Fixes:
	- Crashing issues stabilized
	- Windows 8 compatibility issues stabilized
	- Fixed X and Y increment sources in Hosted mode

SoftStep Team:
Keith McMillen, Eric Bateman, Conner Lacy, Chuck Carlson, Evan Adams, Evan Bogonia, Diane Douglas, Tom Ferguson, Jay Fields, Matt Hettich, David Hishinuma, Sarah Howe, Daniel McAnulty, Dennis Saputelli, Dustin Schultz, Barry Threw, Nick Wang, Carson Whitley, Steve Wright, and Darren Gibbs.
