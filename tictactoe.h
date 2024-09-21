#ifndef _TICTACTOE_BACKEND
    #define _TICTACTOE_BACKEND

#include "typedefs.h"

enum ttt_error: uchar {
    TTT_NONE, TTT_OUT_OF_BOUNDS, TTT_INDEX_USED_ALREADY, TTT_NOT_X_OR_O
};

extern const char * const ttt_board_layout;

enum ttt_error ttt_add_to_board(const uchar index, const char val);
void ttt_reset_board();



#endif // _TICTACTOE_BACKEND
