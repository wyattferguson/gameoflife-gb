#pragma once

#include <gb/gb.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include <rand.h>

void print_text(UINT8 print_x, UINT8 print_y, const char *string);
void print_number(UINT8 x, UINT8 y, INT8 value, const char *string);
UINT8 rand_num(UINT8 low, UINT8 high);
void clear_screen(void);
void wipe_win_line(UINT8 y);
