all:
	lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -c -o ./build/game.o ./src/main.c
	lcc -Wa-l -Wl-m -Wf--debug -Wl-y -Wl-w -o ./build/game.gb ./build/game.o
