@echo off
setlocal

if "%~1"=="" exit /b 2
if "%~2"=="" exit /b 2

set "PROJECT_FILE=%~1"
set "ACTION=%~2"
set "VCVARS=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
set "QMAKE=C:\qt6\6.3.2\msvc2019_64\bin\qmake.exe"

call "%VCVARS%"
if errorlevel 1 exit /b %errorlevel%

if /i "%ACTION%"=="configure" (
    "%QMAKE%" "%PROJECT_FILE%"
    exit /b %errorlevel%
)

if /i "%ACTION%"=="build" (
    "%QMAKE%" "%PROJECT_FILE%"
    if errorlevel 1 exit /b %errorlevel%
    nmake /NOLOGO
    exit /b %errorlevel%
)

if /i "%ACTION%"=="clean" (
    nmake /NOLOGO clean
    exit /b %errorlevel%
)

echo Unsupported action: %ACTION%
exit /b 2