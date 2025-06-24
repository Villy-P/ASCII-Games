#include "util.h"
#include "platform.h"

#include <stdlib.h>

int wasKeyDown(int key) {
    #ifdef __WIN32
    if (0x00000001 & GetAsyncKeyState(key))
        return 1;
    return 0;
    #else
    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Unable to open X display\n");
        return 0;
    }
    char keys[32];
    XQueryKeymap(display, keys);
    KeyCode keycode = XKeysymToKeycode(display, key);
    return (keys[keycode >> 3] & (1 << (keycode & 7))) != 0;
    #endif
}

int randrange(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}