#ifndef _TICTACTOE_CONFIGURATION
    #define _TICTACTOE_CONFIGURATION

#if !defined(_WIN32) && (defined(__unix__) || defined(unix) || defined(__APPLE__))
#define TTT_SUPPORTS_TERMIOS
#endif // if defined not _WIN32 and (__unix__, unix, __APPLE__)

#endif // _TICTACTOE_CONFIGURATION
