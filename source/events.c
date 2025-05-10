#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "events.h"

int getInput() {
    int input = getch();

    if (input == KEY_DIR_ALIAS || input == 224) {
        input = getch();

        switch(input) {
            case KEY_RIGHT:
                return KEY_RIGHT;
            case KEY_LEFT:
                return KEY_LEFT;
            default:
                return input; 
        }
    }
    else {
        int input;
        input = getch();

        switch(input) {
            default:
                return input; 
        }
    }
}
