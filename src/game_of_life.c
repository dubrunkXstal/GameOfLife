#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "grid.h"
#include "keyboard_capture.h"
#include "rendering.h"
#include "structs.h"

void gameCycle(Grid* grid);

int main() {
    int error_status = 0;

    Grid grid = NULL;
    grid = createGrid(&error_status);

    if (!error_status) {
        setGrid(grid, &error_status);
    }

    if (!error_status) {
        error_status = !freopen("/dev/tty", "r", stdin);
    }

    if (!error_status) {
        gameCycle(&grid);
    }

    for (int i = 0; i < HEIGHT && grid; ++i) {
        if (grid[i]) {
            free(grid[i]);
        }
    }

    if (grid) {
        free(grid);
    }

    if (error_status) {
        printf("n/a");
    }

    return error_status;
}

void gameCycle(Grid* grid) {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    // setColorsNcurses();

    int delay = 1000;  // ms
    int game_status = 1;
    int iteration = 0;

    while (game_status) {
        clock_t frame_start = clock();
        printBorders();
        printGrid(*grid);
        printStatusBar(++iteration, delay);
        refresh();

        updateGridCurrentState(*grid);
        updateGridNextState(*grid);

        while (game_status && ((clock() - frame_start) < delay * CLOCKS_PER_SEC / 1000)) {
            processKey(&delay, &game_status);
            printDelay(delay);
            refresh();
        }
    }

    endwin();
}
