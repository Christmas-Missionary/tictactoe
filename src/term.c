#include "ttt_config.h"
#ifdef TTT_SUPPORTS_TERMIOS

#include <unistd.h> // STDIN_FILENO

#include "term.h"

struct termios get_termios(){
    struct termios res;
    tcgetattr(STDIN_FILENO, &res);
    return res;
}

struct termios turn_off_flags(struct termios term){
    term.c_lflag = 0;
    return term;
}

void set_termios(const struct termios * term){
    tcsetattr(STDIN_FILENO, TCSANOW, term);
}

#endif
