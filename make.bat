if not exist build mkdir build

lcc -Wa-l -Wl-m -debug -c -o build\main.o src\main.c
lcc -Wa-l -Wl-m -debug -c -o build\board.o src\board.c
lcc -Wa-l -Wl-m -debug -c -o build\font.o src\font.c
lcc -Wa-l -Wl-m -debug -c -o build\screens.o src\screens.c
lcc -Wa-l -Wl-m -debug -c -o build\utils.o src\utils.c

lcc -debug -Z -Wa-l -Wl-m -Wm-yoA -Wm-yn"GameOfLife" -o gameoflife.gb build\main.o build\board.o build\font.o build\screens.o build\utils.o
