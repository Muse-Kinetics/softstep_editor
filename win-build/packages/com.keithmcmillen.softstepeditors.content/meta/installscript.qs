function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
    console.log("Starting createOperations...");

    var targetDir = installer.value("TargetDir");

    // Create the basic operations for the component
    component.createOperations();

    var displayName = component.displayName;
    var description = component.description;

    console.log("DisplayName: " + displayName);
    console.log("Description: " + description);

    if (systemInfo.productType === "windows") {
        var startMenuDir = installer.value("StartMenuDir");
        var contentPath = targetDir + "/Content"; // Assuming 'Content' is the directory where manuals and presets are stored
        var shortcutPath = startMenuDir + "/" + displayName + ".lnk";
        var iconPath = targetDir + "/Content/Icons/ADVappicon.ico"; // Specify the path to your icon, if you have one for the folder

        console.log("Content Path: " + contentPath);
        console.log("Shortcut Path: " + shortcutPath);

        // Create a shortcut that opens the content directory
        component.addOperation("CreateShortcut",
                                contentPath,
                                shortcutPath,
                                "iconPath=" + iconPath,
                                "description=" + description);

        // Optionally, you can create a shortcut for the uninstallation as well, similar to before
        var uninstallShortcutPath = targetDir + "/Uninstall " + displayName + ".lnk";
        component.addOperation("CreateShortcut",
                                targetDir + "/maintenancetool.exe",
                                uninstallShortcutPath,
                                "workingDirectory=" + targetDir,
                                "description=Uninstall " + displayName);
    }

    console.log("createOperations completed.");
}
