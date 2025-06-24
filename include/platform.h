#ifndef __C_SNAKE_PLATFORM__
#define __C_SNAKE_PLATFORM__

#ifdef __WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#include <ncurses.h>
#endif

#endif