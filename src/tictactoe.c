#include <string.h>

#include "typedefs.h"
#include "tictactoe.h"

static char board [TICTACTOE_BOARD_AREA + 1] =
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};

/* external variables, in order, from tictactoe.h */
const char ttt_board_layout [TICTACTOE_BOARD_LAYOUT_SIZE] =
    "1|2|3\n-----\n4|5|6\n-----\n7|8|9\n";

const char ttt_both_boards_layout [65] =
    "1|2|3  q|w|e\n-----  -----\n4|5|6  a|s|d\n-----  -----\n7|8|9  z|x|c\n";

/* end of external variables */

enum ttt_error ttt_add_to_board(const int32_t index, const char val){
    if (index < 0 || index > TICTACTOE_BOARD_AREA){
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
    const uchar dest_indices [TICTACTOE_BOARD_AREA] = {0, 2, 4, 12, 14, 16, 24, 26, 28};
    for (uchar i = 0; i < TICTACTOE_BOARD_AREA; i++){
        dest[dest_indices[i]] = board[i];
    }
    return dest;
}

ttt_winner_indices ttt_check_for_winner(const char val){
    const ttt_winner_indices all [10] = {
        // First 8 are winning indicies forming a straight line of 3
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6},
        {-1, -1, -1}, // none, continue playing
        {-2, -2, -2} // draw
    };
    for (uchar i = 0; i < TICTACTOE_BOARD_AREA - 1; i++){
        if (val == board[all[i].one] && val == board[all[i].two] && val == board[all[i].three]){
            return all[i];
        }
    }

    const char * const ptr_to_space = strchr(board, ' ');
    return (ptr_to_space == NULL) ? all[9] : all[8];
}

int32_t input_to_index(const int32_t input, const bool is_left_pad_enabled){
    if (is_left_pad_enabled){
        switch (input){
            case 'q': return 0;
            case 'w': return 1;
            case 'e': return 2;
            case 'a': return 3;
            case 's': return 4;
            case 'd': return 5;
            case 'z': return 6;
            case 'x': return 7;
            case 'c': return 8;
        }
    }
    return (input >= '1' && input <= '9') ? (input - '1') : -1;
    // ttt_add_to_board(-1, ...) immediately returns TTT_OUT_OF_BOUNDS
}
