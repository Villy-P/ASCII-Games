#include "util.h"
#include "platform.h"

#include <stdlib.h>

int wasKeyDown(int key) {
    if (0x00000001 & GetAsyncKeyState(key))
        return 1;
    return 0;
}

int randrange(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}