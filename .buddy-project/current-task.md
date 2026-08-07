# Current Task

## macOS release — COMPLETE (2026-08-06)

Windows was already published (v3.0.7). The macOS build is now **hardware-validated by Eric**, and the signed + notarized universal DMG is published to the GitHub release.

- Built on macOS with **Qt 6.9.2** (universal x86_64+arm64) via the new `.vscode` **SoftStep Mac Build** task. One Qt-6.9.2/Apple-clang fix was required (`-Wno-error=implicit-function-declaration` for `qyieldcpu.h`), applied in `.vscode/run-qmake-task.sh`.
- Packaged via **SoftStep Mac Make DMG**: macdeployqt → codesign (Developer ID: Kesumo, LLC) → create-dmg (Basic+Advanced apps + CHANGELOG + Content (15M) in a SoftStep folder, drag-to-Applications) → notarize (notarytool profile "Andrej") → staple.
- Deployed via **SoftStep Mac Deploy**: `gh release upload v3.0.7` → `Muse-Kinetics/softstep_editor`. Asset: `SoftStep Mac v3.0.7.dmg`.

The `.vscode` tooling now carries unified cross-platform tasks named `[Product] [OS] [Action]` (SoftStep Win Build / SoftStep Mac Build / SoftStep Mac Launch (Console) / SoftStep Mac Make DMG / SoftStep Mac Deploy). "Deploy" = attach the DMG to the matching GitHub release (moved off self-hosted webpage).

**Status: shipped on both Windows and macOS.** Everything below predates this and is kept for history.

---

The packetized firmware-update work is complete and hardware-validated. Active work since then has been the WMS/WinMM dual-backend rollout across `KMI_MDM`, `rtmidi`, and the standalone `sendsysex` tool, editor-side hardening (pre-1.0.0 firmware blocking), and — most recently — the version 3.0.7 release prep: firmware 2.0.7, an installer fix ported from the 12 Step Editor project, and updated docs. **Editor version bumped from the beta `3.0.6.C` → non-beta `3.0.6` → `3.0.7`** (the second bump was an explicit user request after the first, made before anything was committed) — `3.0.7` is intended to be the actual public release, not another beta.

## Priority Order

1. Keep dual-backend behavior (WMS primary, WinMM fallback, `KMI_MIDI_BACKEND` override) consistent across `KMI_MDM`, `rtmidi`, and `sendsysex` as any of the three change.
2. Validate hot-plug detection (`KmiDeviceChangeFilter`, WinMM path) and the 90s bootloader timeout on real hardware, including VM/slow-enumeration scenarios.
3. Decide on release packaging / runtime DLL deployment for both editors (see blockers.md) — `sendsysex` now has a working `package-release.ps1` pattern that could inform this.
4. Resolve the untracked `.github/` directory left at the repo root (see blockers.md).

## Current State

Dual-backend rollout hardware-validated (2026-07-27/28).

- Packetized firmware updater confirmed working on real hardware (2026-07-08): 289 chunks, ~110 ms/chunk, per-packet ACKs, clean bootloader → firmware reboot.
- `shared/KMI_MDM` (branch `main`, commit `c5c549b`): WinMM hot-plug detection (`KmiDeviceChangeFilter`, 400ms debounce) + dual-backend port consistency (`kmiSelectMidiApi()`, 90s bootloader timeout on WinMM). Legacy pre-1.0.0 "trojan-horse" bootloader-install path removed in favor of an explicit unsupported-firmware error.
- `shared/rtmidi` (branch `WMS`, commit `b79b83e`): push-based watcher, `openPort()` cache refresh, SysEx reassembly (from 2026-07-08), plus `isWindowsMidiServicesAvailable()` (2026-07-27) so consumers can compile both backends and probe at runtime.
- `shared/sendsysex` (new submodule, `v0.9.0`, commit `503451a`): standalone CLI companion tool with its own dual-backend probe, family/device JSON database, chunk-aware SysEx/firmware-update sending, and release packaging (`package-release.ps1`, `RELEASING.md`). Validated on real BopPad and SoftStep hardware over both backends.
- Both editors (Basic + Advanced): block connected devices reporting firmware `< 1.0.0` with a blocking "not supported" dialog + support-URL launch + quit; minor dialog-centering cleanup. Both editors point at the chunk-safe `-cs512` embedded SoftStep firmware asset.
- VS Code tooling: "Force WinMM" launch configs added for both editors (sets `KMI_MIDI_BACKEND=winmm`) to test the WinMM path on WMS-equipped machines; console-build tasks/variants removed as unmaintained.
- `.buddy-project/` has a `.gitignore` entry but the files were already tracked before that was added, so edits here still show as `modified` in `git status` and still need to be handled deliberately at commit time (see blockers.md and decisions.md — this gap already caused one accidental-inclusion incident).

## Version 3.0.7 / Firmware 2.0.7 release prep (2026-08-01)

Picked up after finishing the equivalent work on the 12 Step Editor this session — same pattern applied here.

- **`shared/sendsysex` updated**: to commit `0896497` (past the `v0.10.0` tag — that commit isn't tagged yet), which carries `Softstep_Firmware_v2.0.7-cs512.syx`. Firmware 2.0.7 (per `data/families/softstep.json` and the firmware repo's own `system.h`/commit history in `00_Firmware/SoftStep/Softstep2`): adds a 1-second boot-time tare capture for key sensors (margined +25%, clamped) to reduce stuck-key false triggers, and enforces `off_sense >= on_sense/2` for all keys and the nav pad. Confirmed on hardware to fix an occasional sticking-key issue. (2.0.6, bundled in the same release, separately fixed Hosted-mode expression pedal calibration.)
- **`shared/KMI_MDM` fast-forwarded** to `origin/main` (`0630904`, the 12 Step Editor's firmware 1.0.9 commit from earlier this session — unrelated to SoftStep but the same shared repo) before bumping `_fw_ver_softstep` to `2,0,7`, to keep that shared repo's history linear rather than branching a second commit off the older `c5c549b`.
- Copied `Softstep_Firmware_v2.0.7-cs512.syx` into `shared/firmware/` and added it to `shared/firmware/firmware.qrc`. Both editors build the firmware filename from `_fw_ver_softstep` at runtime (`Softstep_Firmware_v%1.%2.%3-cs512.syx`), so no further code change was needed — same version-driven pattern as 12 Step.
- **Version bumped 3.0.6.C → 3.0.6** in both `standalone/advanced/SoftStepAdvanced.pro` and `standalone/ezpz/softstepezpz.pro` (`.B`/`.C` were beta iterations during the WMS migration — commit `562ab3f1` explicitly calls `.B` "beta"; `3.0.6` with no letter suffix is the real release). **Then bumped again to 3.0.7** per explicit user request (before anything was committed) — also updated in `win-deploy/config/config.xml` and all three `meta/package.xml` files (normally auto-synced by `make-installer.ps1` on next build, but kept consistent by hand here since nothing's been built/committed since).
- **Both editors rebuilt clean** (`qmake` + `nmake`, Release config) with the version bump and new firmware resource — confirmed via full build output, not just assumed.
- **`.vscode/make-installer.ps1` signing bug fixed**: this is the *original* template 12 Step's own `make-installer.ps1` was copied from — it had the same `/fd certHash` (invalid digest algorithm) + redundant `/v /debug` bug that caused signing failures on 12 Step, but the fix was never backported here. Fixed to `/fd sha256` (no `/v /debug`), matching the proven-working pattern.
- **Installer existing-install fix ported from 12 Step**: `win-deploy/config/controller.qs` (new file) implements `Controller.prototype.TargetDirectoryPageCallback` — detects an existing install via `maintenancetool.exe`, offers to remove it (`purge -c --am`) before the native `TargetDirectoryInUse` hard-block would otherwise fire. Wired via `<ControlScript>controller.qs</ControlScript>` in `win-deploy/config/config.xml`, replacing the same stale commented-out `<!-- <ControlScript>pre-install2.qs</ControlScript> -->` line 12 Step also had (confirming this `config.xml` is the template 12 Step's was copied from). `win-deploy/config/pre-install.qs` (pre-existing dead code — defines `preInstall()`, not a real QtIFW callback name) left untouched, same as 12 Step. Built a real (unsigned, `-DisableSigning`) installer to confirm `controller.qs` is correctly picked up and embedded by `binarycreator` — it is. **Not yet exercised end-to-end via a real GUI install-over-existing-install run on SoftStep specifically** (unlike 12 Step, where that full flow — including the purge self-deletion race fix — was validated live). The logic is identical to 12 Step's already-validated version, and SoftStep's installer has 3 packages instead of 1, but that shouldn't matter since the check operates on the whole target directory, not per-package — still worth a real run before shipping. See SOP §4.9 for the full writeup of this pattern, including the gotchas (self-deletion race, `-t` being CLI-only, headless CLI not exercising the fix at all).
- **`CHANGELOG.md`**: added a `3.0.7, Firmware 2.0.7` entry covering everything since the last real entry (3.0.5) — WMS/WinMM migration, chunked firmware, pre-1.0.0 guard, firmware 2.0.6/2.0.7 changes, the installer fix, and the batch of Hosted-mode/Basic-editor bug fixes from the `3.0.6.B` beta commit that were never previously published in a changelog.
- **`README.md`**: fixed several stale sections — Building from Source referenced nonexistent placeholder paths (`basic-editor-directory`, `SoftStep_Basic.pro`); the Windows Deployment section described a manual Qt-Creator `DEPLOY=1`/`BUILD_CONSOLE=1` toggling workflow that no longer exists (console builds were removed in commit `0aa001e9`, deploy is now entirely `make-installer.ps1`-driven); Project Structure still listed the retired `KMI_Ports`/`KMI_Updates` submodules. Added WMS/firmware-update mentions to Features and a version line.
- **`.vscode/release-github.ps1` (new)**: see next section.
- **Nothing has been committed or pushed** — same "don't commit without review" pattern used on 12 Step this session. Also: `shared/sendsysex` is sitting at commit `0896497`, past the `v0.10.0` tag but not itself tagged — if the sendsysex repo maintainer wants a clean tag boundary, `v0.10.1` (or similar) should probably be cut there at some point, not urgent.

## GitHub Release packaging script — built, dry-run validated, blocked on office/signing

`.vscode/release-github.ps1` (new): reads the version from `SoftStepAdvanced.pro`, locates the installer `make-installer.ps1` produces, verifies it has a valid Authenticode signature (hard-fails otherwise, unless `-AllowUnsigned` for dry-run testing), extracts that version's section out of `CHANGELOG.md` for release notes, writes a `.sha256` checksum, tags `vX.Y.Z`, pushes the tag to the `github` remote, and runs `gh release create` against `Muse-Kinetics/softstep_editor` with the installer + checksum attached. Unlike `sendsysex`'s `package-release.ps1` (which stops at "ready to attach to a release, do the rest by hand"), this one does the full tag→push→publish sequence in one command, since the user asked for a ready-to-go release script specifically.

**`-DryRun` validated** (with `-AllowUnsigned`, against a real unsigned test build of the 3.0.6 installer): version parsing, installer-path resolution, changelog-section extraction, and checksum computation all work correctly. Found and fixed one real bug in the process — `Get-Content` without an explicit encoding mangled the "≥" character from the changelog (read as ANSI instead of UTF-8), which would have corrupted the actual published release notes; fixed with `-Encoding UTF8`. The tag/push/`gh release create` path itself has **not** been exercised for real — that requires an actually-signed installer, which requires being at the office. Test installer artifacts were deleted after validation, not left behind.

Note: SoftStep has no online-update repository (unlike 12 Step's new GitHub Pages one built this session) — this script only publishes the installer as a downloadable release asset, it doesn't set up a `maintenancetool`-discoverable update repo. Not asked for here; flagging so it's a deliberate scope decision, not an oversight, if it comes up later.

## Immediate Next Step

Same shape as the 12 Step Editor's remaining work this session: everything is done except what requires being physically at the office.

1. Get sign-off to commit this session's changes (submodule pointer bumps, `.pro` version bumps, `firmware.qrc`/asset, `controller.qs`/`config.xml`, `make-installer.ps1` fix, `release-github.ps1`, `CHANGELOG.md`, `README.md`).
2. Once at the office: build + sign the real installer (`.vscode\make-installer.ps1`, no `-DisableSigning`), then validate the `controller.qs` existing-install fix with a real GUI install-over-existing-install run (SoftStep-specific validation still outstanding — see previous section).
3. Run `.vscode\release-github.ps1` for real (tags `v3.0.7`, pushes it, publishes the GitHub Release with the signed installer attached).
4. Older candidates, still open:
   - Clean up the untracked `.github/` directory (currently just an untracked, previously-reverted `copilot-instructions.md`) — decide whether to keep, gitignore, or delete.
   - Delete the leftover Dropbox conflict-copy files in `shared/rtmidi/android/` (see blockers.md).
   - Validate hot-plug detection and the 90s bootloader timeout on real hardware, including VM/slow-enumeration scenarios.
