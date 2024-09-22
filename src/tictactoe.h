#ifndef _TICTACTOE_BACKEND
    #define _TICTACTOE_BACKEND

#include "typedefs.h"

enum ttt_error: uchar {
    TTT_NONE, TTT_OUT_OF_BOUNDS, TTT_INDEX_USED_ALREADY, TTT_NOT_X_OR_O,
};

typedef struct {
    schar one;
    schar two;
    schar three;
} ttt_winner_indices;

#define TICTACTOE_BOARD_LAYOUT_SIZE 31
#define TICTACTOE_BOARD_AREA 9

/* external variables, in order, needs tictactoe.c */
extern const char ttt_board_layout [TICTACTOE_BOARD_LAYOUT_SIZE];
/* end of external variables */

// Adds a char to the board, returns an `ttt_error`.
enum ttt_error ttt_add_to_board(const int32_t index, const char val);

// Resets the board to spaces in the nine slots.
void ttt_reset_board();

// Formats the dest (and returns its pointer) with the board to be printed.
// You must use a `char [TICTACTOE_BOARD_LAYOUT_SIZE]` for a proper format.
char * ttt_board_as_str(char * dest);

ttt_winner_indices ttt_check_for_winner(const char val);


#endif // _TICTACTOE_BACKEND
