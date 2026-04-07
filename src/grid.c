#include "grid.h"

#include <stdio.h>
#include <stdlib.h>

#include "cell.h"
#include "structs.h"

Grid createGrid(int* error_status) {
    Grid grid = malloc(HEIGHT * sizeof(Cell*));
    *error_status = (!grid);

    for (height i = 0; i < HEIGHT && !*error_status; ++i) {
        grid[i] = malloc(WIDTH * sizeof(Cell));
        *error_status = (!grid[i]);

        for (width j = 0; j < WIDTH && !*error_status; ++j) {
            grid[i][j].current_state = 0;
            grid[i][j].next_state = 0;
        }
    }

    return grid;
}

void setGrid(Grid grid, int* error_status) {
    for (height i = 0; i < HEIGHT && !*error_status; ++i) {
        for (width j = 0; j < WIDTH && !*error_status; ++j) {
            char ch = getchar();

            if (ch == '#') {
                grid[i][j].current_state = 1;
                grid[i][j].next_state = 1;
            } else if (ch == '.') {
                grid[i][j].current_state = 0;
                grid[i][j].next_state = 0;
            } else {
                *error_status = 1;
            }
        }
        *error_status = (getchar() != '\n');
    }
}

void updateGridCurrentState(Grid grid) {
    for (height i = 0; i < HEIGHT; ++i) {
        for (width j = 0; j < WIDTH; ++j) {
            updateCellCurrentState(grid, j, i);
        }
    }
}

void updateGridNextState(Grid grid) {
    for (height i = 0; i < HEIGHT; ++i) {
        for (width j = 0; j < WIDTH; ++j) {
            updateCellNextState(grid, j, i);
        }
    }
}

width cycleBorderWidth(width x) { return (WIDTH + (x % WIDTH)) % WIDTH; }

height cycleBorderHeight(height y) { return (HEIGHT + (y % HEIGHT)) % HEIGHT; }
