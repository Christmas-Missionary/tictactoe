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

ttt_winner_indices ttt_check_for_winner(const char val){
    const ttt_winner_indices all [9] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6},
        {-1, -1, -1}
    };
    for (uchar i = 0; i < 8; i++){
        if (val == board[all[i].one] && val == board[all[i].two] && val == board[all[i].three]){
            return all[i];
        }
    }
    return all[8];
}
