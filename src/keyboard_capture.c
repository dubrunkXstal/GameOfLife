#include "keyboard_capture.h"

#include <ncurses.h>

#include "rendering.h"

void processKey(int* delay, int* game_status) {
    int ch = getch();

    if ((ch == 'z' || ch == 'Z') && *delay < 9975) {
        lightZ();
        *delay += 25;
    } else if ((ch == 'a' || ch == 'A') && *delay > 25) {
        lightA();
        *delay -= 25;
    } else if (ch == ' ') {
        *game_status = 0;
    }
}
