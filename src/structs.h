#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    int current_state;
    int next_state;
} Cell;

#define HEIGHT 25
#define WIDTH 80

#define ALIVE '#'
#define DEAD ' '

typedef int width;
typedef int height;

typedef Cell** Grid;

#endif  // STRUCTS_H
