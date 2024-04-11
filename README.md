# README #

Git repo (converted from SVN) with source for Easy and Advanced SoftStep editor.

Builds against Qt 6.3.2.

Deployment for macOS:

1. Build the Release version of the Basic and Advanced apps with Qt
2. Run SoftStep - build sign package mac qt6 universal.sh in the "Signing and Notarization" folder 

Deployment for Windows:

Basic editor (do this first):
1. Open the basic editor qt project. 
2. Update the VERSION variable at the top of the file.
3. Delete all executables in the release build dir. 
4. In the "Projects" setup tab you have to add a second build/make step with the argument "deploy" (no quotes)
5. Comment the "DEPLOY = 1" line and Uncomment the "BUILD_CONSOLE = 1" line in the qt .pro file and build. 
6. Rename the built executable, adding "(debug console)" to the end of the name. 
7. Re-comment the "BUILD_CONSOLE = 1" line and uncomment the "DEPLOY = 1" line in the qt .pro file, and build. This will copy both executables to the installer package directory, run qtdeploy to add the dlls, and sign the executables.

Advanced editor (do this second):
1. Open the advanced editor qt project. 
2. Update the VERSION variable at the top of the file.
3. Delete all executables in the release build dir. 
4. In the "Projects" setup tab you have to add a second build/make step with the argument "deploy" (no quotes)
5. Comment the "DEPLOY = 1" line and Uncomment the "BUILD_CONSOLE = 1" line in the qt .pro file and build. 
6. Rename the built executable, adding "(debug console)" to the end of the name. 
7. Re-comment the "BUILD_CONSOLE = 1" line and uncomment the "DEPLOY = 1" line in the qt .pro file, and build. This will copy both executables to the installer package directory, run qtdeploy to add the dlls, and sign the executables. This will also copy the changelog and root repo Content directory to the installer package directory, and then build the installer. 
