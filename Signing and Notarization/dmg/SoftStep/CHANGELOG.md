#### SoftStep Editor and Firmware Changelog

### Editor 2.1.0, Firmware 1.0.0 (2021-04-06)
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
