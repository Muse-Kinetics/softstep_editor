# Blockers

## No active blockers

Hardware validation completed 2026-07-08. The packetized firmware updater works end-to-end on real hardware.

## Dropbox conflict files in `shared/rtmidi`

Dropbox left conflict copies of the android source files (`RtMidi (Eric Bateman's conflicted copy ...).cpp` etc.) in the `shared/rtmidi` working tree. These are untracked and should not be staged or committed. They can be deleted manually when convenient.

## Release-runtime packaging remains a separate concern

Editor release builds and runtime DLL deployment have been a recurring source of friction. Do not conflate runtime packaging issues with MIDI transport behavior.