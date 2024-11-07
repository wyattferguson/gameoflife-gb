
#include <gb/gb.h>
#include <stdlib.h>
#include "board.c"
#include "config.h"
#include "font.c"
#include "screens.c"
#include "utils.c"

/**
 * @brief Init sound, display, and enable bg/sprites/window
 *
 */
void setup(void) {
    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;
    setup_font();
    show_title_screen();
}

/**
 * @brief Main game loop
 *
 */
void main(void) {
    uint8_t button_pressed = 0;
    UBYTE auto_play = 0;

    setup();

    while(1) {
        button_pressed = joypad();
        switch(state) {
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
                if(button_pressed & J_SELECT) {
                    auto_play = !auto_play;
                    if(auto_play) {
                        print_text(WIN_RIGHT, WIN_TOP, "MODE AUTO", WIN, 0);
                    } else {
                        print_text(WIN_RIGHT, WIN_TOP, "MODE STEP", WIN, 0);
                    }

                    delay(SCREEN_DELAY);
                }

                // Run next step in board
                if((button_pressed & J_UP) || auto_play) {
                    update_board(*pboard, *pnext);
                    steps++;
                    print_number(WIN_LEFT, WIN_BOTTOM, steps, "GEN ", WIN);
                }
                // Reset board
                else if(button_pressed & J_DOWN) {
                    print_text(WIN_RIGHT, WIN_BOTTOM, "STAT RESET", WIN, 0);
                    show_play_screen();
                }
                break;
        }
        wait_vbl_done();
    }
}