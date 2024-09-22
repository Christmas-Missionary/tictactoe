#ifndef _TICTACTOE_BACKEND
    #define _TICTACTOE_BACKEND

#include "typedefs.h"

enum ttt_error: uchar {
    TTT_NONE, TTT_OUT_OF_BOUNDS, TTT_INDEX_USED_ALREADY, TTT_NOT_X_OR_O,
};

#define TICTACTOE_BOARD_LAYOUT_SIZE 31
#define TICTACTOE_BOARD_AREA 9

/* external variables, in order, needs tictactoe.c */
extern const char ttt_board_layout [TICTACTOE_BOARD_LAYOUT_SIZE];
/* end of external variables */


enum ttt_error ttt_add_to_board(const int32_t index, const char val);


void ttt_reset_board();

// Formats the dest (and returns its pointer) with the board to be printed.
// You must use a `char [TICTACTOE_BOARD_LAYOUT_SIZE]` for a proper format.
char * ttt_board_as_str(char * dest);


#endif // _TICTACTOE_BACKEND
