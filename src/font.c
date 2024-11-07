
#include "font.h"

/**
 * @brief load font tiles into memory after logo tiles
 *
 */
void setup_font() { set_bkg_data(FONT_MEMORY_START, FONT_SIZE, font_tiles); }

/**
 * @brief Convert string to tiles and print to window
 *
 * @param print_x window x coordinate
 * @param print_y window y coordinate
 * @param string string to be printed
 * @param surface 0 = win / 1 = bkg
 * @param text_delay time between printing each char
 */
void print_text(UINT8 print_x, UINT8 print_y, const char *string, UBYTE surface,
                UINT8 text_delay) {
    unsigned char c;

    while (*string) {
        if (*string >= 'A' && *string <= 'Z') {
            c = FONT_CHAR_START + (unsigned char)(*string - 'A');
        } else if (*string >= '0' && *string <= '9') {
            c = FONT_NUM_START + (unsigned char)(*string - '0');
        } else if (*string == '>') {
            c = FONT_EXTRA + 1U;
        } else {
            c = FONT_BLANK;
        }

        if (surface) {
            set_bkg_tiles(print_x, print_y, 1, 1, &c);
        } else {
            set_win_tiles(print_x, print_y, 1, 1, &c);
        }

        print_x++;
        string++;

        if (text_delay) {
            delay(text_delay);
        }
    }
}

/**
 * @brief Print a string and number to window
 *
 * @param x window x coordinate
 * @param y window y coordinate
 * @param value number to print
 * @param string string to prepend the value
 * @param surface WIN / BKG
 */
void print_number(UINT8 x, UINT8 y, INT8 value, const char *string,
                  UBYTE surface) {
    unsigned char value_text[16];
    unsigned char char_buffer[16];
    strcpy(value_text, string);
    strcat(value_text, itoa(value, char_buffer, 8));
    clear_text(x, y, 10, surface);
    print_text(x, y, value_text, surface, 0);
}

/**
 * @brief Clear all tiles in a given area
 *
 * @param x window x coordinate
 * @param y window y coordinate
 * @param w width of section to erase
 * @param surface WIN / BKG
 */
void clear_text(UINT8 x, UINT8 y, UINT8 w, UBYTE surface) {
    if (surface) {
        set_bkg_tiles(x, y, w, 1,
                      &font_tiles[FONT_BLANK]);  // clear entire bkg row
    } else {
        set_win_tiles(x, y, w, 1,
                      &font_tiles[FONT_BLANK]);  // clear that section of window
    }
}