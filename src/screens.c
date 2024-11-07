#include "screens.h"

/**
 * @brief Display main title screen
 *
 */
void show_title_screen() {
    state = TITLE;
    clear_screen();
    set_bkg_data(0, 64, logo_data);
    set_bkg_tiles(0, 0, LOGO_WIDTH, LOGO_HEIGHT, logo_map);
    move_win(WIN_X, SPLASH_WIN_Y);
    print_text(5, 2, "PRESS START", WIN, 0);
    print_text(5, 5, "CREATED BY", WIN, 0);
    print_text(3, 6, "WYATT FERGUSON", WIN, 0);
    delay(SCREEN_DELAY);
}

/**
 * @brief Display gameover screen
 *
 */
void show_tutorial() {
    state = TUTORIAL;
    clear_screen();
    move_win(WIN_X, TUT_WIN_Y);
    print_text(6, 1, "CONTROLS", WIN, 0);
    print_text(4, 3, "UP > STEP", WIN, 50);
    print_text(4, 5, "DOWN > RESET", WIN, 50);
    print_text(4, 7, "SELECT > AUTO", WIN, 50);
    print_text(5, 12, "PRESS START", WIN, 0);
    delay(SCREEN_DELAY);
}

/**
 * @brief Display main gameplay screen
 *
 */
void show_play_screen() {
    clear_screen();
    set_bkg_data(0, BLOCK_TILES, block_tiles);
    state = PLAYING;
    steps = 0;
    move_win(WIN_X, PLAY_WIN_Y);
    print_number(WIN_LEFT, WIN_BOTTOM, steps, "GEN ", WIN);
    print_text(WIN_RIGHT, WIN_TOP, "MODE STEP", WIN, 0);
    setup_board(*pboard);
    display_board(*pboard);
}

/**
 * @brief Clear screen and window
 *
 */
void clear_screen() {
    wait_vbl_done();
    DISPLAY_OFF;

    for (UINT8 line = 0; line < GRID_HEIGHT + 1; line++) {
        set_bkg_tiles(0, line, 120, 1, 0);
        set_win_tiles(0, line, 120, 1, 0);
    }

    DISPLAY_ON;
}
