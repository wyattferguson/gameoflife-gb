#include "board.h"

uint8_t row = 0;
uint8_t col = 0;
uint8_t total_alive = 0;

/**
 * @brief Generate random board state
 *
 */
void setup_board(Board board) {
    print_text(WIN_RIGHT, WIN_BOTTOM, "STAT GEN", WIN, 0);
    for(row = 0; row < BOARD_HEIGHT; row++) {
        for(col = 0; col < BOARD_WIDTH; col++) {
            board[row][col] = rand_num(0, 1);
            total_alive += board[row][col];
        }
    }
}

/**
 * @brief Print board to screen using background tiles
 *
 */
void display_board(Board board) {
    for(row = 0; row < BOARD_HEIGHT; row++) {
        for(col = 0; col < BOARD_WIDTH; col++) {
            set_tile_xy(col + BOARD_X_OFFSET, row + BOARD_Y_OFFSET, board[row][col]);
        }
    }
    print_number(WIN_LEFT, WIN_TOP, total_alive, "ALIVE ", WIN);
    print_text(WIN_RIGHT, WIN_BOTTOM, "STAT DONE", WIN, 0);
}

/**
 * @brief Run the current board through the standard game of life rules
 *
 * Rules: https://conwaylife.com/wiki/Conway%27s_Game_of_Life
 *
 */
void update_board(Board board, Board next) {
    uint8_t alive = 0;
    total_alive = 0;
    print_text(WIN_RIGHT, WIN_BOTTOM, "STAT CALC", WIN, 0);
    for(row = 0; row < BOARD_HEIGHT; row++) {
        for(col = 0; col < BOARD_WIDTH; col++) {
            alive = alive_neighbours(*pboard, row, col);

            if(board[row][col] == 0 && alive == 3) {
                next[row][col] = 1;
            } else if(board[row][col] == 1 && (alive < 2 || alive > 3)) {
                next[row][col] = 0;
            } else {
                next[row][col] = board[row][col];
            }

            total_alive += next[row][col];
        }
    }

    copy_boards();
    display_board(*pboard);
}

/**
 * @brief Copy next board into current board
 *
 */
void copy_boards(void) {
    Board *temp = pboard;
    pboard = pnext;
    pnext = temp;
}

/**
 * @brief Count number of alive cells surround a given row/col cell
 *
 * @return uint8_t - Alive Cell Count
 */
uint8_t alive_neighbours(Board board, uint8_t i, uint8_t j) {
    uint8_t alive = 0;
    const uint8_t down = i - 1;
    const uint8_t right = j + 1;
    const uint8_t left = j - 1;
    const uint8_t up = i + 1;

    // Check row below cell
    if(i > 0) {
        alive += board[down][j];

        if(j > 0) {
            alive += board[down][left];
        }

        if(right < BOARD_WIDTH) {
            alive += board[down][right];
        }
    }

    if(j > 0) {
        alive += board[i][left];
    }

    if(right < BOARD_WIDTH) {
        alive += board[i][right];
    }

    // Check row above cell
    if(up < BOARD_HEIGHT) {
        alive += board[up][j];

        if(j > 0) {
            alive += board[up][left];
        }

        if(right < BOARD_WIDTH) {
            alive += board[up][right];
        }
    }

    return alive;
}
