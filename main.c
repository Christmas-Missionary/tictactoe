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

    int input = 0;

    while (1){
        input = getchar();
        printf("%c", input);
    }

    set_termios(&oldt);
    return 0;
}
