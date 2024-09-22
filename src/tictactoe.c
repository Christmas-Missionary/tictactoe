#include <string.h>

#include "typedefs.h"
#include "tictactoe.h"

static char board [TICTACTOE_BOARD_AREA] =
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

/* external variables, in order, from tictactoe.h */
const char ttt_board_layout [TICTACTOE_BOARD_LAYOUT_SIZE] =
    "1|2|3\n-----\n4|5|6\n-----\n7|8|9\n";
/* end of external variables */

enum ttt_error ttt_add_to_board(const int32_t index, const char val){
    if (index < 0 || index >= TICTACTOE_BOARD_AREA){
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

char * ttt_board_as_str(char * dest){
    strcpy(dest, ttt_board_layout);
    const uchar dest_indices [9] = {0, 2, 4, 12, 14, 16, 24, 26, 28};
    for (uchar i = 0; i < 9; i++){
        dest[dest_indices[i]] = board[i];
    }
    return dest;
}
