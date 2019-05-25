@echo off
echo ~~~~~~~~~~~~~~~~~~~~~~~
echo   Building project...
echo ~~~~~~~~~~~~~~~~~~~~~~~

rem // Path of the parent directory to this script
set DIR=%~dp0
cd /D %DIR%

rem // Command line parameters for CL build tool
set OUTPUT=debug
set TARGET=main
set PLATFORM=x64

rem // Build, compilation, and link variables
set FLAGS=/Od /W4 /Gm /EHsc /ZI /MDd
set INCLUDES=/I include /I include/SDL2
set SOURCES=source/**
set EXTLIBPATH=libraries
set LIBRARIES=SDL2main.lib SDL2.lib

rem Find build variables from Visual Studio installation
for /F "tokens=* usebackq" %%I IN (`vswhere -latest -find **\vcvarsall.bat`) do set VARS="%%I"

rem // Additional variables
set RESOURCES=resources

rem // Create the output directory if it does not exist
if not exist %OUTPUT%\nul mkdir %OUTPUT%

rem // Copy necessary files to where they belong
echo Copying resource files...
robocopy %RESOURCES% %OUTPUT% /S >nul

rem // Load build variables from vcvarsall.bat
echo Loading build variables...
call %VARS% %PLATFORM% 1>nul

echo.

rem // Build project
echo Building project...
call cl %FLAGS% %INCLUDES% ^
	/Fo:%OUTPUT%\ /Fd:%OUTPUT%\ %SOURCES% ^
	/link /LIBPATH:%EXTLIBPATH% ^
	/OUT:%OUTPUT%\%TARGET%.exe /PDB:%OUTPUT%\%TARGET%.pdb ^
	/INCREMENTAL /SUBSYSTEM:CONSOLE ^
	%LIBRARIES% ^
	2>&1

echo ~~~~~~~~~~~~~~~~~~~
if %errorlevel% == 0 (
	echo   Build complete!
) else (
	echo    Build failed!
)
echo ~~~~~~~~~~~~~~~~~~~
