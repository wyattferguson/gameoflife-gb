set PROJECTNAME=gameoflife
set BUILD_DIR=build
set SRC=src\main.c src\board.c src\font.c src\screens.c src\utils.c

if not exist %BUILD_DIR% mkdir %BUILD_DIR%

for %%f in (%SRC%) do (
    lcc -Wa-l -Wl-m -debug -c -o %BUILD_DIR%\%%~nf.o %%f
)

lcc -debug -Z -Wa-l -Wl-m -Wm-yoA -Wm-yn"GameOfLife" -o %BUILD_DIR%\%PROJECTNAME%.gb %BUILD_DIR%\main.o %BUILD_DIR%\board.o %BUILD_DIR%\font.o %BUILD_DIR%\screens.o %BUILD_DIR%\utils.o
