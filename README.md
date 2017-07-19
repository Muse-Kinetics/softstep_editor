# README #

Git repo (converted from SVN) with source for Easy and Advanced SoftStep editor.

Builds against Qt 5.9.1.

Deployment for macOS:

You need to manually copy resources into the app package.  There's now a folder in the repo called macOS_AppPkgRsrcs which contains all the expected files

To deploy with proper libraries and code-signing, do this:
~/Dev/BeBop/Qt/5.9.1/clang_64/bin/macdeployqt  SoftStep\ Advanced\ Editor.app/ 
-qmldir=../Dev/BeBop/SoftStepEditor/softstep_editor/standalone/advanced/ 
-codesign="Developer ID Application: Kesumo, LLC (***REMOVED***)"

To check code signing if there's a failure: 
codesign --verbose=4 --deep --strict  SoftStep\ Advanced\ Editor.app/

also:
Assess an application or tool
spctl --assess --type execute myTool
 
Assess an installer package
spctl --assess --type install myInstallerPackage.pkg