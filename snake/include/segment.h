#ifndef __C_SNAKE_SEGMENT__
#define __C_SNAKE_SEGMENT__

struct Segment {
    int x;
    int y;
};

extern struct Segment *apple;

struct Segment* generateSegment(int x, int y);

#endif