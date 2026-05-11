#ifndef __C_SNAKE_SNAKE__
#define __C_SNAKE_SNAKE__

#include "segment.h"

enum Direction {
    UP = 1,
    RIGHT,
    DOWN,
    LEFT
};

struct Snake {
    int length;
    struct Segment **segments;
    enum Direction direction;
};

struct Snake* generateSnake(struct Segment *head);
int isSegmentAt(struct Snake *snake, int x, int y);
void moveTo(struct Snake *snake);
void handleKeypresses(struct Snake *snake);
int moveInDirection(struct Snake *snake, enum Direction direction);
int isGameOver(struct Snake *snake);

#endif