#include "cell.h"

#include "grid.h"

void updateCellCurrentState(Grid grid, width x, height y) {
    grid[y][x].current_state = grid[y][x].next_state;
}

void updateCellNextState(Grid grid, width x, height y) {
    int neighbours_cnt = countNeighbours(grid, x, y);

    Cell* cell = &grid[y][x];

    if (cell->current_state == 1 && (2 > neighbours_cnt || neighbours_cnt >= 4)) {
        cell->next_state = 0;
    } else if (cell->current_state == 0 && neighbours_cnt == 3) {
        cell->next_state = 1;
    }
}

int countNeighbours(Grid grid, width x, height y) {
    const int neighbours[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    /*
    {-1, -1} {0, -1} {1, -1}
    {-1,  0}         {1,  0}
    {-1,  1} {0,  1} {1,  1}
    */

    int alive_cnt = 0;

    for (int i = 0; i < 8; ++i) {
        height y_shift = cycleBorderHeight(y + neighbours[i][0]);
        width x_shift = cycleBorderWidth(x + neighbours[i][1]);

        if (grid[y_shift][x_shift].current_state != 0) {
            ++alive_cnt;
        }
    }

    return alive_cnt;
}