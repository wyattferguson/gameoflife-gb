#pragma once
#include <gb/gb.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "screens.h"
#include "utils.h"

typedef uint8_t Board[BOARD_HEIGHT][BOARD_WIDTH];

Board current_board;
Board next_board;

Board *pboard = &current_board;
Board *pnext = &next_board;

uint16_t steps = 0;

void setup_board(Board grid);
void update_board(Board board, Board next);
void display_board(Board board);
void copy_boards(void);
uint8_t alive_neighbours(Board board, uint8_t r, uint8_t c);
