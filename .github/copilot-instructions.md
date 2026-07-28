# Copilot Instructions

This file is a wrapper, not a source of truth.

Read these repository docs first and treat them as authoritative:

1. `README.md`
2. `.buddy-project/mission.md`
3. `.buddy-project/decisions.md`
4. `.buddy-project/current-task.md`
5. `.buddy-project/handoff.md`
6. `.buddy-project/blockers.md`
7. `.buddy-project/commands.md`

## What this repository is

This repository is **SoftStep Editor**. It contains the Basic and Advanced Qt editors for configuring SoftStep hardware, embedding firmware assets, and running firmware updates through shared transport code in `shared/KMI_MDM`.

Buddy's canonical operational state lives in `.buddy-project/`.

## How to work in this repository

- Treat `.buddy-project/` as the canonical operational context.
- Use `Documentation/FIRMWARE_CHUNKING.md` and the Buddy docs before changing the packetized updater.
- Keep shared transport logic in `shared/KMI_MDM`; do not move updater logic into editor UI code.
- Preserve the use of prebuilt chunk-safe firmware assets in `shared/firmware/`.
- Do not assume chat history is authoritative when repo state or Buddy docs disagree.