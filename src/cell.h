#ifndef CELL_H
#define CELL_H

#include "structs.h"

void updateCellCurrentState(Grid grid, width x, height y);
void updateCellNextState(Grid grid, width x, height y);
int countNeighbours(Grid grid, width x, height y);

#endif  // CELL_H
