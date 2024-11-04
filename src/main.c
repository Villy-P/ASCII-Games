#include "grid.h"
#include "segment.h"
#include "snake.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifdef __WIN32
#include <windows.h>
#endif

int main() {
    srand(time(0));
    int game = 1;
    struct Segment* head = generateSegment(gridWidth / 4, gridHeight / 2);
    struct Snake* snake = generateSnake(head);
    apple = generateSegment(gridWidth / 2, gridHeight / 2);
    while (game) {
        displayGrid(snake);
        printf("%c[%dA\n", 0x1B, gridHeight + 3);
        handleKeypresses(snake);
        moveTo(snake);
        if (isGameOver(snake)) {
            game = 0;
            printf("%c[%dB!GAME OVER\n", 0x1B, gridHeight + 3);
        }
        if (snake->length == (gridWidth * gridHeight)) {
            game = 0;
            printf("%c[%dBYOU WON!\n", 0x1B, gridHeight + 3);
        }
        Sleep(100);
    }
    free(head);
    free(snake);
    return 0;
}