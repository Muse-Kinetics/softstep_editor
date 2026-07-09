# Guidelines

- Keep canonical project state in `.buddy-project/` and update it when the firmware-update plan or validation state changes.
- Treat `Documentation/FIRMWARE_CHUNKING.md` as the design baseline for the packetized updater until the next follow-up commit replaces it with finalized behavior docs.
- Keep editor-specific UI changes separate from shared transport changes in `shared/KMI_MDM` whenever possible.
- Use the prebuilt `-cs512` firmware payload; do not reintroduce ad hoc PID-header creation inside the editor.
- When debugging updater failures, collect both firmware console output and raw SysEx capture so packet/phase context is preserved.
- Do not expand scope into unrelated cleanup just because the repos are already dirty.