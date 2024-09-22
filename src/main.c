// #include <stdio.h>

#include "typedefs.h"
#include "tictactoe.h"
#include "term.h"
#include <stdio.h>

int main(void){
    const struct termios oldt = get_termios();
    {
        const struct termios newt = turn_off_flags(oldt);
        set_termios(&newt);
    }

    int32_t input = 0;
    // int32_t turn = 1; // 1 is X, -1 is O.
    char char_turn = 'X';

    puts(ttt_board_layout);

    while (1){
        char board_format [TICTACTOE_BOARD_LAYOUT_SIZE];
        input = getchar();

        if (input == '\x1b'){
            break;
        }
        if (input == 'r'){
            ttt_reset_board();
            puts("The board has been reset!");
            puts(ttt_board_as_str(board_format));
            char_turn = 'X';
            continue;
        }

        enum ttt_error error = ttt_add_to_board(input - '1', char_turn);

        if (error == TTT_OUT_OF_BOUNDS){
            puts("That is not on the board!");
            continue;
        }
        if (error == TTT_NOT_X_OR_O){
            puts("Something very wrong has happened!");
            continue;
        }
        if (error == TTT_INDEX_USED_ALREADY){
            puts("This spot has already been filled! Try a different spot.");
            continue;
        }

        ttt_winner_indices indices = ttt_check_for_winner(char_turn);


        puts(ttt_board_as_str(board_format));
        char_turn = (char_turn == 'X') ? 'O' : 'X';
    }

    set_termios(&oldt);
    return 0;
}
