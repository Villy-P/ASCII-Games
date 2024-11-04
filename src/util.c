#include "util.h"

#include <stdlib.h>

#ifdef __WIN32
#include <windows.h>
#else
#include <X11/Xlib.h>
#include <X11/keysym.h>
#endif

int wasKeyDown(int key) {
    if (0x00000001 & GetAsyncKeyState(key))
        return 1;
    return 0;
}

int randrange(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}