# Workspace Task Toolbar

This extension adds a `Tasks` dropdown to the VS Code editor title area whenever the current workspace contains a `.vscode/tasks.json` file.

The dropdown is intended to be generic and reusable across projects.

## Commands

- Build Default Task
- Choose Build Task
- Choose Test Task
- Choose Clean Task
- Choose Any Task
- Refresh Task Toolbar Context

## How It Works

- The extension watches the workspace for `.vscode/tasks.json` files.
- If one exists, it sets a context key that enables the toolbar dropdown.
- Commands use the VS Code task API to fetch and execute tasks instead of invoking shells directly.

## Packaging And Install

1. Run `./package-vsix.ps1` from PowerShell to create a local `.vsix`
2. Install it with `code --install-extension .\local.workspace-task-toolbar-0.0.1.vsix --force`

Once installed, the extension can be enabled globally and will work in any workspace that has a `.vscode/tasks.json`.