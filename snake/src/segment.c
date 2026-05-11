#include "segment.h"

#include <stdlib.h>

struct Segment *apple;

struct Segment* generateSegment(int x, int y) {
    struct Segment *segment = (struct Segment*)malloc(sizeof(struct Segment));
    segment->x = x;
    segment->y = y;
    return segment;
}