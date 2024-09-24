#include "ttt_config.h"
#ifdef TTT_SUPPORTS_TERMIOS

#ifndef _TICTACTOE_TERMIOS_SIMPLIFIED
    #define _TICTACTOE_TERMIOS_SIMPLIFIED

#include <termios.h> // termios, TCSANOW, ECHO, ICANON
// Issue incoming from a Windows user probably
// Any alternatives to this?

// returns the current settings of the terminal.
struct termios get_termios();

// returns a terminal with local flags off, You don't see what you type + getchar returns for every key press.
__attribute__ ((const))
struct termios turn_off_flags(struct termios term);

// sets the terminal settings, use this to reset with old settings.
void set_termios(const struct termios * term);

#endif // _TICTACTOE_TERMIOS_SIMPLIFIED

#endif
