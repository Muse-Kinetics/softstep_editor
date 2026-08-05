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
        console.log("StartMenuDir: " + startMenuDir);
        
        var exePath = targetDir + "/" + displayName + "/" + displayName + ".exe";
        var shortcutPath = startMenuDir + "/" + displayName + ".lnk";
        var workingDir = targetDir + "/" + displayName;
        var iconPath = targetDir + "/Content/Icons/ADVappicon.ico"; // Specify the path to your icon, if you have one for the folder
        var uninstallShortcutPath = targetDir + "/Uninstall " + displayName + ".lnk";

        console.log("EXE Path: " + exePath);
        console.log("Shortcut Path: " + shortcutPath);
        console.log("Working Directory: " + workingDir);
        console.log("Icon Path: " + iconPath);
        console.log("Uninstall Shortcut Path: " + uninstallShortcutPath);

        // Create a shortcut for the application
        component.addOperation("CreateShortcut", 
                                exePath,
                                shortcutPath,
                                "workingDirectory=" + workingDir,
                                "iconPath=" + iconPath,
                                "description=" + description);

        // Create a shortcut to the maintenance tool for uninstallation
        component.addOperation("CreateShortcut",
                                targetDir + "/maintenancetool.exe",
                                uninstallShortcutPath,
                                "workingDirectory=" + targetDir,
                                "description=Uninstall " + displayName);

        // Run the bundled VC++ Redistributable so MSVCP140/VCRUNTIME140 are
        // actually registered on the target machine, not just sitting next
        // to the exe (windeployqt bundles it but never executes it).
        var vcRedistPath = workingDir + "/vc_redist.x64.exe";
        component.addOperation("Execute",
                                "{0,3010,1638,5100}",
                                vcRedistPath,
                                "/install", "/quiet", "/norestart");
    }

    console.log("createOperations completed.");
}
