#include "grid.h"
#include "snake.h"

#include <stdio.h>

int gridWidth = 10;
int gridHeight = 10;

void displayGrid(struct Snake *snake) {
    printf("+");
    for (int i = 0; i < gridWidth; i++)
        printf(" -");
    printf(" +\n");
    for (int i = 0; i < gridHeight; i++) {
        printf("|");
        for (int j = 0; j < gridWidth; j++) {
            if (isSegmentAt(snake, j, i))
                printf(" #");
            else if (apple->x == j && apple->y == i)
                printf(" @");
            else
                printf("  ");
        }
        printf(" |\n");
    }
    printf("+");
    for (int i = 0; i < gridWidth; i++)
        printf(" -");
    printf(" +\n");
}