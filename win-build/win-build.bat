:: ##############################################################################################
:: app specific variables - adjust these to match your needs and the script should do the rest
:: ##############################################################################################

set app_name=SoftStep Editors
set app_version=2.1.0B

set build_dir_1=..\standalone\build-SoftStepAdvanced-Desktop_Qt_6_2_4_MSVC2019_64bit-Release\release
set build_dir_2=..\standalone\build-softstepezpz-Desktop_Qt_6_2_4_MSVC2019_64bit-Release\release

set binary_1=SoftStep Advanced Editor.exe
set binary_2=SoftStep Basic Editor.exe
set debug_binary_1=SoftStep Advanced Editor (debug console).exe
set debug_binary_2=SoftStep Basic Editor (debug console).exe

set package_root=.\SoftStep
set package_dir_1=.\SoftStep\SoftStepAdvancedEditor
set package_dir_2=.\SoftStep\SoftStepBasicEditor

set path_to_qml_files_1="..\standalone\advanced"
set path_to_qml_files_2="..\standalone\ezpz"

set path_to_changelog="..\CHANGELOG.md"

set path_to_ssl=.\ssl
set path_to_qt=C:\Qt6\6.2.4

set path_to_vcvarsall="c:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat"
set path_to_signtool="C:\Program Files (x86)\Windows Kits\10\bin\10.0.22000.0\x64\signtool.exe"

:: ##############################################################################################
:: end user defined variables
:: ##############################################################################################

set output_zip="%app_name% WIN v%app_version%"
set binary_src_1="%build_dir_1%\%binary_1%"
set binary_src_2="%build_dir_2%\%binary_2%"
set debug_binary_src_1="%build_dir_1%\%debug_binary_1%"
set debug_binary_src_2="%build_dir_2%\%debug_binary_2%"
set binary_dest_1="%package_dir_1%\%binary_1%"
set binary_dest_2="%package_dir_2%\%binary_2%"
set path_to_qtwindeploy="%path_to_qt%\msvc2019_64\bin\windeployqt.exe"

:: ##############################################################################################
:: end compound variables
:: ##############################################################################################


@echo off

set "current_dir=%cd%"

cls
@echo ##############################################################################################
@echo %output_zip% package builder
@echo:
@echo Please pause dropbox sync before continuing (avoids zip errors)
@echo ##############################################################################################
@echo: 

pause

@echo ##############################################################################################
echo Setting up environment for Qt usage...
@echo ##############################################################################################
@echo:

set PATH=%path_to_qt%\msvc2019_64\bin;%PATH%
cd /D %path_to_qt%\msvc2019_64
call %path_to_vcvarsall% x86_amd64

@echo on

cd %current_dir%

@echo ##############################################################################################
@echo Cleaning folders...
@echo ##############################################################################################
@echo:

del /Q %package_dir_1%\*.*
del /Q %package_dir_2%\*.*
::pause

@echo ##############################################################################################
@echo Copying Changelog...
@echo ##############################################################################################
@echo:

xcopy /Y %path_to_changelog% %package_root%
::pause

@echo ##############################################################################################
@echo Running qtwindeploy...
@echo ##############################################################################################
@echo:

%path_to_qtwindeploy% --release --verbose 2 --force --qmldir %path_to_qml_files_1% --dir %package_dir_1%\ %binary_src_1%
%path_to_qtwindeploy% --release --verbose 2 --force --qmldir %path_to_qml_files_2% --dir %package_dir_2%\ %binary_src_2%
::pause

@echo ##############################################################################################
@echo Copying application executables...
@echo ##############################################################################################
@echo:

xcopy /Y %binary_src_1% %package_dir_1%
xcopy /Y %debug_binary_src_1% %package_dir_1%

xcopy /Y %binary_src_2% %package_dir_2%
xcopy /Y %debug_binary_src_2% %package_dir_2%

::pause

@echo ##############################################################################################
@echo Copying OpenSSL DLLs
@echo ##############################################################################################
@echo:

:: contents of the ssl folder need to be present in the same dir as the executable
xcopy /Y %path_to_ssl%\*.* %package_dir_1%
xcopy /Y %path_to_ssl%\*.* %package_dir_2%
::pause

@echo ##############################################################################################
@echo Signing executables...
@echo ##############################################################################################
@echo:

%path_to_signtool% sign /debug /a /tr http://timestamp.globalsign.com/tsa/advanced /td SHA256 /fd certHash %binary_dest_1%
%path_to_signtool% sign /debug /a /tr http://timestamp.globalsign.com/tsa/advanced /td SHA256 /fd certHash %binary_dest_2%
::pause

@echo ##############################################################################################
@echo "Wait 5 seconds for dropbox to catch up"
@echo ##############################################################################################
@echo:

TIMEOUT 5

@echo ##############################################################################################
@echo "Creating zip package..."
@echo ##############################################################################################
@echo:

powershell compress-archive "'%package_root%' '%output_zip%.zip'" 
::pause

@echo ##############################################################################################
@echo "Finished!"
@echo ##############################################################################################
@echo:

pause





