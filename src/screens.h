#pragma once
#include <gb/gb.h>
#include "board.h"
#include "config.h"
#include "font.h"
#include "sprites/block-tiles.c"
#include "sprites/logo_data.c"
#include "sprites/logo_map.c"

enum game_states { TITLE, PLAYING, TUTORIAL } state = TITLE;

void show_title_screen(void);
void show_play_screen(void);
void show_tutorial(void);
void clear_screen(void);
