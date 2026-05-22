@echo off
setlocal EnableExtensions

if "%~1"=="" exit /b 2
if "%~2"=="" exit /b 2
if "%~3"=="" exit /b 2

set "PROGRAM=%~1"
set "WORKDIR=%~2"
set "LOGFILE=%~3"
set "TASK_NAME=SoftStep-ConsoleLaunch-%RANDOM%%RANDOM%"
set "RUNNER=%TEMP%\softstep-console-launch-%RANDOM%%RANDOM%.cmd"
set "QTBIN=C:\qt6\6.3.2\msvc2019_64\bin"
set "OPENSSLBIN_QT6=C:\Qt6\Tools\OpenSSL\Win_x64\bin"
set "OPENSSLBIN_QT=C:\Qt\Tools\OpenSSL\Win_x64\bin"
set "QTPLUGINS=C:\qt6\6.3.2\msvc2019_64\plugins"
set "QTQML=C:\qt6\6.3.2\msvc2019_64\qml"

for %%I in ("%LOGFILE%") do set "LOGDIR=%%~dpI"
if not exist "%LOGDIR%" mkdir "%LOGDIR%"
break > "%LOGFILE%"

for /f %%I in ('powershell -NoProfile -Command "(Get-Date).AddMinutes(5).ToString('HH:mm')"') do set "START_TIME=%%I"

>"%RUNNER%" echo @echo off
>>"%RUNNER%" echo set "PATH=%QTBIN%;%OPENSSLBIN_QT6%;%OPENSSLBIN_QT%;%%PATH%%"
>>"%RUNNER%" echo set "QT_PLUGIN_PATH=%QTPLUGINS%"
>>"%RUNNER%" echo set "QML2_IMPORT_PATH=%QTQML%"
>>"%RUNNER%" echo set "QML_IMPORT_PATH=%QTQML%"
>>"%RUNNER%" echo cd /d "%WORKDIR%"
>>"%RUNNER%" echo "%PROGRAM%" 1^>^> "%LOGFILE%" 2^>^&1
>>"%RUNNER%" echo del "%%~f0"

schtasks.exe /Create /TN "%TASK_NAME%" /TR "cmd.exe /c %RUNNER%" /SC ONCE /ST %START_TIME% /F /IT /RL LIMITED >nul
if errorlevel 1 exit /b %errorlevel%

schtasks.exe /Run /TN "%TASK_NAME%" >nul
set "RUN_ERROR=%errorlevel%"
schtasks.exe /Delete /TN "%TASK_NAME%" /F >nul 2>nul

if not "%RUN_ERROR%"=="0" exit /b %RUN_ERROR%
exit /b 0
