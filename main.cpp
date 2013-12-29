#include <curses.h>
#include <windows.h>
#include <assert.h>
#include "database_lib.h"

int main (void) {

    initscr();
    wclear(stdscr);

    intro();
    login();
    menu(1);

    exit_intro();
    endwin();
    return 0;
}

