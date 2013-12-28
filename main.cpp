#include <curses.h>
#include <windows.h>
#include <assert.h>
#include "database_lib.h"

int main (void) {

    initscr();
    wclear(stdscr);

    //intro();
    login();

    getch();
    endwin();
    return 0;
}
