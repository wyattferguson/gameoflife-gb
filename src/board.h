#pragma once
#include <gb/gb.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "screens.h"
#include "utils.h"

typedef uint8_t Board[BOARD_HEIGHT][BOARD_WIDTH];

extern Board current_board;
extern Board next_board;

extern Board *pboard;
extern Board *pnext;

extern uint16_t steps;

extern uint8_t total_alive;

extern uint8_t board_frozen;

void setup_board(Board grid);
void update_board(Board board, Board next);
void display_board(Board board);
void copy_boards(void);
uint8_t alive_neighbours(Board board, uint8_t r, uint8_t c);
