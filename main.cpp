#include <curses.h>
#include <windows.h>
#include <assert.h>
#include <fstream>
#include <stdlib.h>
#include "database_lib.h"

int main (void) {

    initscr();
    wclear(stdscr);

    intro();
    login();
    menu(1);

    endwin();
    return 0;
}

