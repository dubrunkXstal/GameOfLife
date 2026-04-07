#ifndef RENDERING_H
#define RENDERING_H

#include "structs.h"

void printBorders();
void printStatusBar(int iteration, int delay);
void printGrid(Grid grid);
void printCell(Grid grid, width x, height y);
// void setColorsNcurses();
void printDelay(int delay);
void lightA();
void lightZ();

#endif  // RENDERING_H
