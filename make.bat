@echo off
setlocal enabledelayedexpansion

set GAME_NAME=gameoflife
set CC=lcc
set CFLAGS=-Wa-l -Wl-m -debug -c
set LDFLAGS=-Wa-l -Wl-m -debug -Z -Wm-yoA -Wm-yn"%GAME_NAME%"
set BUILD_DIR=build
set OUT=%GAME_NAME%.gb

if not exist %BUILD_DIR% mkdir %BUILD_DIR%

echo Compiling %GAME_NAME%
rem Auto-discover all .c files under src\ (recursive)
set OBJ_FILES=
for /R src %%f in (*.c) do (
    rem Strip everything up to "src\" to get relative path
    set "rel=%%f"
    set "rel=!rel:*src\=!"
    set "obj=%BUILD_DIR%\!rel:.c=.o!"

    rem Create subdirectory if needed
    for %%d in (!obj!) do if not exist %%~dpd mkdir %%~dpd

    echo Compiling %%f -^> !obj!
    %CC% %CFLAGS% -o !obj! %%f

    set OBJ_FILES=!OBJ_FILES! !obj!
)

if "%OBJ_FILES%"=="" (
    echo No .c files found under src\!
    exit /b 1
)

echo.
echo Linking...
%CC% %LDFLAGS% -o %OUT% %OBJ_FILES%

echo Done: %OUT%
