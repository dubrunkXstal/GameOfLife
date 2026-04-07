#ifndef GRID_H
#define GRID_H

#include "structs.h"

Grid createGrid(int* error_status);
void setGrid(Grid grid, int* error_status);
void updateGridCurrentState(Grid grid);
void updateGridNextState(Grid grid);
width cycleBorderWidth(width x);
height cycleBorderHeight(height y);

#endif  // GRID_H
