#include "utils.h"

/**
 * @brief Convert string to tiles and print to window
 * 
 * @param print_x window x coordinate
 * @param print_y window y coordinate
 * @param string string to be printed
 */
void print_text(UINT8 print_x, UINT8 print_y, const char *string){
    unsigned char c;

    //wipe_win_line(print_y);
    
    while(*string) {
        if(*string >= 'A' && *string <= 'Z'){
            c = FONT_CHAR_START + (unsigned char)(*string - 'A');
        } else if(*string >= '0' && *string <= '9') {
            c = FONT_NUM_START + (unsigned char)(*string - '0');
        } else {
            c = FONT_BLANK;
        }

        set_win_tiles(print_x, print_y, 1, 1, &c);

        print_x++;
        string++;
    }
}


/**
 * @brief Print a string and number to window
 * 
 * @param x window x coordinate
 * @param y window y coordinate
 * @param value number to print
 * @param string string to prepend the value
 */
void print_number(UINT8 x, UINT8 y, INT8 value, const char *string){
    unsigned char value_text[16];
    unsigned char char_buffer[16];
    strcpy(value_text, string);
    strcat(value_text,itoa(value,char_buffer,8));
    set_win_tiles(x,y,WIN_RIGHT,1,0); // clear that section of window
    print_text(x, y, value_text);
}


/**
 * @brief Genereate random unsigned 8 bit integer
 * 
 * @param low minimum 8 bit value
 * @param high max 8 bit value
 * @return UINT8 
 */
UINT8 rand_num(UINT8 low, UINT8 high){
    return low + rand() % (high + 1 - low) ;
}
