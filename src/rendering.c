#include "rendering.h"

#include <ncurses.h>

#include "structs.h"

void printBorders() {
    // attron(COLOR_PAIR(3));
    for (height i = 0; i < HEIGHT + 3; ++i) {
        mvprintw(i, 0, "|");
        mvprintw(i, WIDTH + 1, "|");
    }

    mvprintw(0, 0,
             "*================================================================================*");
    mvprintw(HEIGHT + 1, 0,
             "*================================================================================*");
    mvprintw(HEIGHT + 3, 0,
             "*================================================================================*");

    // attroff(COLOR_PAIR(3));
}

void printStatusBar(int iteration, int delay) {
    // attron(COLOR_PAIR(3));
    mvprintw(HEIGHT + 2, 1, " iteration: %9d | A - speed up | Z - slow down | _ - end | delay:   %.3lf ",
             iteration, delay / 1000.0);
    // attroff(COLOR_PAIR(3));
}

void printDelay(int delay) {
    mvprintw(HEIGHT + 2, 75, "%.3lf", delay / 1000.0);
}

void lightA() {
    // attron(COLOR_PAIR(4));
    mvprintw(HEIGHT + 2, 25, "a");
    // attroff(COLOR_PAIR(4));
}

void lightZ() {
    // attron(COLOR_PAIR(4));
    mvprintw(HEIGHT + 2, 40, "z");
    // attroff(COLOR_PAIR(4));
}

void printGrid(Grid grid) {
    for (height y = 0; y < HEIGHT; y++) {
        for (width x = 0; x < WIDTH; x++) {
            printCell(grid, x, y);
        }
    }
}

void printCell(Grid grid, width x, height y) {
    if (grid[y][x].current_state) {
        // attron(COLOR_PAIR(1));
        mvaddch(y + 1, x + 1, ALIVE);
        // attroff(COLOR_PAIR(1));
    } else {
        // attron(COLOR_PAIR(2));
        mvaddch(y + 1, x + 1, DEAD);
        // attroff(COLOR_PAIR(2));
    }
}

// void setColorsNcurses() {
//     start_color();
//     init_pair(1, COLOR_GREEN, COLOR_WHITE);  // 1 цвет -- зелёные символы на белом фоне
//     init_pair(2, COLOR_RED, COLOR_BLACK);   // 2 цвет -- красные символы на чёрном фоне
//     init_pair(3, COLOR_BLACK, COLOR_BLUE);   // 3 цвет для границ
//     init_pair(4, COLOR_BLACK, COLOR_GREEN);  // 4 цвет для нажатых клавиш
// }
