lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/main.o ./src/main.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/board.o ./src/board.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/font.o ./src/font.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/screens.o ./src/screens.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/utils.o ./src/utils.c
lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -o ./gameoflife.gb ./build/main.o ./build/board.o ./build/font.o ./build/screens.o ./build/utils.o