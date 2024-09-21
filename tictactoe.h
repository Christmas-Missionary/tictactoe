#ifndef _TICTACTOE_BACKEND
    #define _TICTACTOE_BACKEND

#include "typedefs.h"

enum ttt_error: uchar {
    TTT_NONE, TTT_OUT_OF_BOUNDS, TTT_INDEX_USED_ALREADY, TTT_NOT_X_OR_O,
};

#define TTT_BOARD_LAYOUT_SIZE 31

/* external variables, in order, needs tictactoe.c */
/* end of external variables */

enum ttt_error ttt_add_to_board(const uchar index, const char val);
void ttt_reset_board();
char * ttt_board_as_str(char * dest);


#endif // _TICTACTOE_BACKEND
