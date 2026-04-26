#pragma once
#include <gb/gb.h>
#include "board.h"
#include "config.h"
#include "font.h"

enum game_states { TITLE, PLAYING, TUTORIAL };
extern enum game_states state;

extern const unsigned char logo_data[];
extern const unsigned char logo_map[];
extern const unsigned char block_tiles[];

void show_title_screen(void);
void show_play_screen(void);
void show_tutorial(void);
void clear_screen(void);
