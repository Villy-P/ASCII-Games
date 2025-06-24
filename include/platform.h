#ifndef __C_SNAKE_PLATFORM__
#define __C_SNAKE_PLATFORM__

#ifdef __WIN32
#include <windows.h>

struct DisplayDef {} Display;
#else
#include <unistd.h>
#include <termios.h>
#include <ncurses.h>

#include <X11/Xlib.h>
#include <X11/keysym.h>
#endif

#endif