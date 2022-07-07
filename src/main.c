
#include <gb/gb.h>
#include <stdlib.h>

#include "config.h"
#include "board.c"
#include "screen.c"
#include "utils.c"

#include "sprites/font-tiles.c"
#include "sprites/block-tiles.c"
#include "sprites/logo_data.c"
#include "sprites/logo_map.c"

void setup(void);
void show_title_screen(void);
void show_play_screen(void);
void show_tutorial(void);


enum game_states {
    TITLE,
    PLAYING,
    TUTORIAL
} state = TITLE;


UINT16 steps = 0;


/**
 * @brief Init sound, display, and enable bg/sprites/window
 * 
 */
void setup(){
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    show_title_screen();
}

/**
 * @brief Display main title screen 
 * 
 */
void show_title_screen(){
    state = TITLE;
    clear_screen();
    set_bkg_data(0,64, logo_data);    
    set_bkg_tiles(0,0,LOGO_WIDTH, LOGO_HEIGHT,logo_map);
    set_bkg_data(LOGO_SIZE, FONT_SIZE, font_tiles);
    move_win(WIN_X, SPLASH_WIN_Y);
    print_text(5, 1, "PRESS START");
    delay(SCREEN_DELAY);
}



/**
 * @brief Display gameover screen
 * 
 */
void show_tutorial(){
    state = TUTORIAL;
    clear_screen();
    move_win(WIN_X, TUT_WIN_Y);
    print_text(6, 0, "CONTROLS");
    print_text(4, 2, "UP -    STEP");
    print_text(4, 4, "DOWN -  RESET");
    print_text(4, 6, "SELECT  AUTO");
    print_text(5, 12, "PRESS START");
    delay(SCREEN_DELAY);
}


/**
 * @brief Display main gameplay screen
 * 
 */
void show_play_screen(){
    clear_screen();
    set_bkg_data(0, BLOCK_TILES, block_tiles);
    state = PLAYING;
    steps = 0;
    move_win(WIN_X, PLAY_WIN_Y);
    print_number(WIN_LEFT,WIN_BOTTOM,steps, "GEN ");
    print_text(WIN_RIGHT,WIN_TOP, "MODE STEP");
    setup_board(*pboard);
    display_board(*pboard);
}


/**
 * @brief Main game loop
 * 
 */
void main() {
    UINT8 button_pressed = 0;
    UBYTE auto_play = 0;

    setup();
    
    while(1) {
        button_pressed = joypad();
        switch (state){
            case TITLE:
                if(button_pressed & J_START) {
                    show_tutorial();
                }
                break;

            case TUTORIAL:
                if(button_pressed & J_START) {
                    show_play_screen();
                }
                break;

            case PLAYING:
                // Change play mode from step to auto
                if(button_pressed & J_SELECT){
                    auto_play = !auto_play;
                    if(auto_play){
                        print_text(WIN_RIGHT,WIN_TOP, "MODE AUTO");
                    }else{
                        print_text(WIN_RIGHT,WIN_TOP, "MODE STEP");
                    }
                    
                    delay(SCREEN_DELAY);
                }
                
                // Run next step in board
                if((button_pressed & J_UP) || auto_play){
                    update_board(*pboard, *pnext);
                    steps++;
                    print_number(WIN_LEFT,WIN_BOTTOM,steps, "GEN ");
                }
                // Reset board 
                else if(button_pressed & J_DOWN){
                    print_text(WIN_RIGHT, WIN_BOTTOM, "STAT RESET");
                    show_play_screen();
                }
                break;
        }
        wait_vbl_done();
    }
}