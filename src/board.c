#include "board.h"

UINT8 row = 0;
UINT8 col = 0;
UINT8 total_alive = 0;

/**
 * @brief Generate random board state
 *
 */
void setup_board(Board board) {
    print_text(WIN_RIGHT, WIN_BOTTOM, "STAT GEN", WIN, 0);
    for (row = 0; row < BOARD_HEIGHT; row++) {
        for (col = 0; col < BOARD_WIDTH; col++) {
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
    for (row = 0; row < BOARD_HEIGHT; row++) {
        for (col = 0; col < BOARD_WIDTH; col++) {
            set_tile_xy(col + BOARD_X_OFFSET, row + BOARD_Y_OFFSET,
                        board[row][col]);
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
    UINT8 alive = 0;
    total_alive = 0;
    print_text(WIN_RIGHT, WIN_BOTTOM, "STAT CALC", WIN, 0);
    for (row = 0; row < BOARD_HEIGHT; row++) {
        for (col = 0; col < BOARD_WIDTH; col++) {
            alive = alive_neighbours(*pboard, row, col);

            if (board[row][col] == 0 && alive == 3) {
                next[row][col] = 1;
            } else if (board[row][col] == 1 && (alive < 2 || alive > 3)) {
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
void copy_boards() {
    Board *temp = pboard;
    pboard = pnext;
    pnext = temp;
}

/**
 * @brief Count number of alive cells surround a given row/col cell
 *
 * @return UINT8 - Alive Cell Count
 */
UINT8 alive_neighbours(Board board, UINT8 i, UINT8 j) {
    UINT8 alive = 0;
    const UINT8 down = i - 1;
    const UINT8 right = j + 1;
    const UINT8 left = j - 1;
    const UINT8 up = i + 1;

    // Check row below cell
    if (i > 0) {
        alive += board[down][j];

        if (j > 0) {
            alive += board[down][left];
        }

        if (right < BOARD_WIDTH) {
            alive += board[down][right];
        }
    }

    if (j > 0) {
        alive += board[i][left];
    }

    if (right < BOARD_WIDTH) {
        alive += board[i][right];
    }

    // Check row above cell
    if (up < BOARD_HEIGHT) {
        alive += board[up][j];

        if (j > 0) {
            alive += board[up][left];
        }

        if (right < BOARD_WIDTH) {
            alive += board[up][right];
        }
    }

    return alive;
}
