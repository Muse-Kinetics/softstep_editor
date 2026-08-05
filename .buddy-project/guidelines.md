# Guidelines

- Keep canonical project state in `.buddy-project/` and update it when the firmware-update plan or validation state changes. `.buddy-project/` has a `.gitignore` entry, but the files were already tracked before that was added, so it does not actually stop them from showing as `modified` — check `git status` before staging/committing anything else so unrelated commits don't accidentally sweep in `.buddy-project`/`.github` changes (this already happened once; see decisions.md).
- Treat `Documentation/FIRMWARE_CHUNKING.md` as the design baseline for the packetized updater until the next follow-up commit replaces it with finalized behavior docs.
- Keep editor-specific UI changes separate from shared transport changes in `shared/KMI_MDM` whenever possible.
- Use the prebuilt `-cs512` firmware payload; do not reintroduce ad hoc PID-header creation inside the editor.
- When debugging updater failures, collect both firmware console output and raw SysEx capture so packet/phase context is preserved.
- Do not expand scope into unrelated cleanup just because the repos are already dirty.
- MIDI backend selection (WMS probe / WinMM fallback / `KMI_MIDI_BACKEND` override) is intentionally duplicated across `shared/KMI_MDM`, `shared/rtmidi`, and `shared/sendsysex` rather than shared — when changing the pattern in one, check the other two.