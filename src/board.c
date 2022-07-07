#include "board.h"

UINT8 row = 0;
UINT8 col = 0;
UINT8 total_alive = 0;

Board current_board;
Board next_board;

Board *pboard = &current_board;
Board *pnext = &next_board;

/**
 * @brief Generate random board state
 * 
 */
void setup_board(Board board){
    print_text(WIN_RIGHT, WIN_BOTTOM, "STAT GEN");
    for(row = 0;row<BOARD_HEIGHT;row++){
        for(col=0;col<BOARD_WIDTH;col++){
            board[row][col] = rand_num(0,1);
            total_alive += board[row][col];
        }
    }
}


/**
 * @brief Print board to screen using background tiles
 * 
 */
void display_board(Board board){
    for(row = 0;row<BOARD_HEIGHT;row++){
        for(col=0;col<BOARD_WIDTH;col++){
            set_tile_xy(col + BOARD_X_OFFSET, row + BOARD_Y_OFFSET, board[row][col]);
        }
    }
    print_number(WIN_LEFT,WIN_TOP,total_alive, "ALIVE ");
    print_text(WIN_RIGHT, WIN_BOTTOM, "STAT DONE");
}


/**
 * @brief Run the current board through the standard game of life rules
 * 
 * Rules: https://conwaylife.com/wiki/Conway%27s_Game_of_Life
 * 
 */
void update_board(Board board, Board next){
    UINT8 alive = 0;
    total_alive = 0;
    print_text(WIN_RIGHT, WIN_BOTTOM, "STAT CALC");
    for(row = 0;row < BOARD_HEIGHT;row++){
        for(col=0;col < BOARD_WIDTH;col++){
            alive = alive_neighbours(*pboard, row,col);
            

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
void copy_boards(){
    Board *temp = pboard;
	pboard = pnext;
	pnext = temp;
}


/**
 * @brief Count number of alive cells surround a given row/col cell
 * 
 * @return UINT8 
 */
UINT8 alive_neighbours(Board board, UINT8 x, UINT8 y){
    UINT8 alive = 0;
    UINT8 a, b = 0;
    for(INT8 i = -1; i < 2; i++){
        for(INT8 j = -1; j < 2; j++){

            a = (x + i + BOARD_HEIGHT) % BOARD_HEIGHT;
			b = (y + j + BOARD_WIDTH) % BOARD_WIDTH;

            alive += board[a][b];
        }
    }
    alive -= board[x][y];
    return alive;
}

