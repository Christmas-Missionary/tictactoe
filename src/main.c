#include <stdio.h>

#include "typedefs.h"
#include "tictactoe.h"
#include "term.h"

int main(void){
    // This comes first before any input.
    const struct termios oldt = get_termios();
    {
        const struct termios newt = turn_off_flags(oldt);
        set_termios(&newt);
    }

    puts("Would you like to enable inputs for qweasdzxc? [y/anything else]");
    int32_t input = getchar();
    bool is_left_pad_enabled = (input == 'y');

    char char_turn = 'X';
    puts(ttt_board_layout);
    puts("X goes first!");

    while (1){
        char board_format [TICTACTOE_BOARD_LAYOUT_SIZE];
        input = getchar();

        if (input == '\x1b'){
            break;
        }
        if (input == 'r'){
            goto reset;
        }
        if (input == 't'){
            printf("It is %c's turn.\n", char_turn);
            continue;
        }
        if (input == 'b'){
            puts(ttt_board_as_str(board_format));
            continue;
        }

        const enum ttt_error error = ttt_add_to_board(input_to_index(input, is_left_pad_enabled), char_turn);

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

        const ttt_winner_indices indices = ttt_check_for_winner(char_turn);

        puts(ttt_board_as_str(board_format));

        if (indices.one == -1){
            char_turn = (char_turn == 'X') ? 'O' : 'X';
            continue;
        }

        printf("%c wins!\nPress 'r' to reset the board, or press anything else to quit.\n", char_turn);
        input = getchar();
        if (input != 'r'){
            break;
        }

        reset:
            ttt_reset_board();
            puts("The board has been reset!\nX goes first!");
            puts(ttt_board_as_str(board_format));
            char_turn = 'X';
    }

    set_termios(&oldt);
    return 0;
}
