#pragma once

#include <gb/gb.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

/* FONT SIZE 46 */
extern const unsigned char font_tiles[];

// print desinations
#define WIN 0
#define BKG 1

// font settings
#define FONT_MEMORY_START 64
#define FONT_SIZE 38
#define FONT_CHAR_START (1 + FONT_MEMORY_START)
#define FONT_NUM_START (27 + FONT_MEMORY_START)
#define FONT_EXTRA (36 + FONT_MEMORY_START)
#define FONT_BLANK (0 + FONT_MEMORY_START)

void setup_font(void);
void print_text(uint8_t print_x, uint8_t print_y, const char *string, UBYTE surface, uint8_t text_delay);
void print_number(uint8_t x, uint8_t y, uint8_t value, const char *string, UBYTE surface);
void clear_text(uint8_t x, uint8_t y, uint8_t w, UBYTE surface);