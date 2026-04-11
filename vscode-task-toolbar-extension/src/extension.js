const vscode = require('vscode');

const HAS_TASKS_CONTEXT = 'workspaceTaskToolbar.hasTasksJson';

async function activate(context) {
  const refreshContext = async () => {
    const hasTasksJson = await workspaceHasTasksJson();
    await vscode.commands.executeCommand('setContext', HAS_TASKS_CONTEXT, hasTasksJson);
  };

  const watcher = vscode.workspace.createFileSystemWatcher('**/.vscode/tasks.json');

  context.subscriptions.push(
    watcher,
    watcher.onDidCreate(refreshContext),
    watcher.onDidChange(refreshContext),
    watcher.onDidDelete(refreshContext),
    vscode.workspace.onDidChangeWorkspaceFolders(refreshContext),
    vscode.commands.registerCommand('workspaceTaskToolbar.refresh', async () => {
      await refreshContext();
      vscode.window.setStatusBarMessage('Workspace Task Toolbar refreshed', 2000);
    }),
    vscode.commands.registerCommand('workspaceTaskToolbar.runDefaultBuild', async () => {
      const tasks = await vscode.tasks.fetchTasks();
      const defaultBuild = tasks.find((task) => isTaskInGroup(task, vscode.TaskGroup.Build) && Boolean(task.group && task.group.isDefault));

      if (defaultBuild) {
        await vscode.tasks.executeTask(defaultBuild);
        return;
      }

      const buildTasks = filterTasks(tasks, 'build');
      if (buildTasks.length === 1) {
        await vscode.tasks.executeTask(buildTasks[0]);
        return;
      }

      await chooseAndRunTask('build');
    }),
    vscode.commands.registerCommand('workspaceTaskToolbar.runBuildQuickPick', async () => {
      await chooseAndRunTask('build');
    }),
    vscode.commands.registerCommand('workspaceTaskToolbar.runTestQuickPick', async () => {
      await chooseAndRunTask('test');
    }),
    vscode.commands.registerCommand('workspaceTaskToolbar.runCleanQuickPick', async () => {
      await chooseAndRunTask('clean');
    }),
    vscode.commands.registerCommand('workspaceTaskToolbar.runTaskQuickPick', async () => {
      await chooseAndRunTask('all');
    })
  );

  await refreshContext();
}

function deactivate() {}

async function workspaceHasTasksJson() {
  if (!vscode.workspace.workspaceFolders || vscode.workspace.workspaceFolders.length === 0) {
    return false;
  }

  const tasksFiles = await vscode.workspace.findFiles('**/.vscode/tasks.json', '**/{node_modules,.git}/**', 1);
  return tasksFiles.length > 0;
}

async function chooseAndRunTask(mode) {
  const tasks = filterTasks(await vscode.tasks.fetchTasks(), mode);

  if (tasks.length === 0) {
    vscode.window.showInformationMessage(messageForEmptyMode(mode));
    return;
  }

  const picked = await vscode.window.showQuickPick(
    tasks.map(toQuickPickItem),
    {
      placeHolder: placeHolderForMode(mode),
      matchOnDescription: true,
      matchOnDetail: true
    }
  );

  if (!picked) {
    return;
  }

  await vscode.tasks.executeTask(picked.task);
}

function filterTasks(tasks, mode) {
  switch (mode) {
    case 'build':
      return tasks.filter((task) => isTaskInGroup(task, vscode.TaskGroup.Build) || /build/i.test(task.name));
    case 'test':
      return tasks.filter((task) => isTaskInGroup(task, vscode.TaskGroup.Test) || /test/i.test(task.name));
    case 'clean':
      return tasks.filter((task) => /clean/i.test(task.name) || hasGroupId(task, 'clean') || hasGroupId(task, 'rebuild'));
    case 'all':
    default:
      return Array.from(tasks);
  }
}

function toQuickPickItem(task) {
  const scopeName = getScopeName(task);

  return {
    label: task.name,
    description: task.source,
    detail: scopeName ? `Workspace: ${scopeName}` : undefined,
    task
  };
}

function getScopeName(task) {
  const scope = task.scope;

  if (scope && typeof scope === 'object' && typeof scope.name === 'string') {
    return scope.name;
  }

  return undefined;
}

function isTaskInGroup(task, group) {
  return Boolean(task.group) && task.group.id === group.id;
}

function hasGroupId(task, groupId) {
  return Boolean(task.group) && task.group.id === groupId;
}

function placeHolderForMode(mode) {
  switch (mode) {
    case 'build':
      return 'Select a build task';
    case 'test':
      return 'Select a test task';
    case 'clean':
      return 'Select a clean task';
    case 'all':
    default:
      return 'Select a task to run';
  }
}

function messageForEmptyMode(mode) {
  switch (mode) {
    case 'build':
      return 'No build tasks were found in this workspace.';
    case 'test':
      return 'No test tasks were found in this workspace.';
    case 'clean':
      return 'No clean tasks were found in this workspace.';
    case 'all':
    default:
      return 'No tasks were found in this workspace.';
  }
}

module.exports = {
  activate,
  deactivate
};