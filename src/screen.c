#include "screen.h"

/**
 * @brief Clear screen and window
 * 
 */
void clear_screen(){
    wait_vbl_done();
    DISPLAY_OFF;

    UINT8 line = 0;
    for (line = 0; line < GRID_HEIGHT + 1; line++) {
        set_bkg_tiles(0,line,120,1,0);
        set_win_tiles(0,line,120,1,0);
    }

    DISPLAY_ON;
}


/**
 * @brief wipe all tiles from a window row
 * 
 * @param y line number
 */
void wipe_win_line(UINT8 y){
    set_win_tiles(0,y,GRID_WIDTH,1,0); 
}