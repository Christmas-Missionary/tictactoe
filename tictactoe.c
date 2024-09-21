#include <string.h>

#include "typedefs.h"
#include "tictactoe.h"

#define TICTACTOE_BOARD_AREA 9

static char board [TICTACTOE_BOARD_AREA] =
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

const char * const ttt_board_layout = "1|2|3\n-----\n4|5|6\n-----\n7|8|9\n";
/*
1|2|3
-----
4|5|6
-----
7|8|9

*/

static const uint64_t board_length = strlen(ttt_board_layout);

enum ttt_error ttt_add_to_board(const uchar index, const char val){
    if (index >= TICTACTOE_BOARD_AREA){
        return TTT_OUT_OF_BOUNDS;
    }
    if (val != 'X' && val != 'O'){
        return TTT_NOT_X_OR_O;
    }
    if (board[index] == 'X' || board[index] == 'O'){
        return TTT_INDEX_USED_ALREADY;
    }
    board[index] = val;
    return TTT_NONE;
}

void ttt_reset_board(){
    memset(board, ' ', TICTACTOE_BOARD_AREA);
}
