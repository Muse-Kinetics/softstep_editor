# Blockers

## No active blockers

Hardware validation completed 2026-07-08 (packetized firmware updater) and 2026-07-27/28 (WMS/WinMM dual-backend rollout, both BopPad and SoftStep hardware).

## Dropbox conflict files in `shared/rtmidi`

Dropbox left conflict copies of the android source files (`RtMidi (Eric Bateman's conflicted copy 2026-06-11).cpp` etc.) in the `shared/rtmidi` working tree, alongside the original files showing as locally deleted. These are untracked/uncommitted local working-tree noise and should not be staged or committed. They can be deleted manually when convenient. Still present as of 2026-07-29.

## Untracked `.github/` directory at repo root

`.github/copilot-instructions.md` was added, then untracked again (`git rm --cached`) across two cleanup commits (`4e60119f` → `0f78d86b` → `65893872`) after an unrelated commit accidentally bundled it in with `.buddy-project` changes. The file still exists on disk, untracked. Decide whether it should be kept (and re-added to `.gitignore` or genuinely tracked) or deleted outright — it's currently just loose working-tree state.

## `.buddy-project/` is gitignored but still tracked

`/.buddy-project/` was added to `.gitignore`, but that only suppresses *new* untracked files — it did not untrack the `.buddy-project/*.md` files that were already committed, so every edit here still shows as `modified` in `git status` and can get swept into an unrelated commit if staging isn't checked carefully (this already happened once — see decisions.md). Completing the detachment requires an explicit `git rm --cached -r .buddy-project` + commit, which hasn't been done. Flag to the user before doing this rather than doing it unprompted, since it changes what future sessions see as "current" state in a fresh clone.

## Release-runtime packaging remains a separate concern

Editor release builds and runtime DLL deployment have been a recurring source of friction. Do not conflate runtime packaging issues with MIDI transport behavior. `shared/sendsysex` now has a working example pattern for this (`package-release.ps1` + `RELEASING.md`: build/stage/zip outside the Dropbox-synced tree since Dropbox locks freshly-copied files mid-zip, signing as a documented manual step, only the finished zip + sha256 land in a gitignored `dist/`) — worth referencing if/when the editors' release packaging gets revisited, but it has not been applied to the editors themselves.
