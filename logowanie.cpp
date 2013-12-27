#include <curses.h>
#include <windows.h>
#include <assert.h>

void login(){

    move(0,0);
    printw( "+------------------------------------------------------------------------------+");
    wrefresh(stdscr);

    int i;
    for (i=0;i<23;i++){

        printw( "|                                                                              |");
        wrefresh(stdscr);
        Sleep(25);
    }

    printw( "+------------------------------------------------------------------------------+");
    wrefresh(stdscr);

    move(6, 23);
    printw( "#===============================#");
    move(7,23);
    printw( "#        Panel logowania.       #");
    move(8, 23);
    printw( "#===============================#");
    move(9, 24);
    printw( "|                             |");
    move(10,24);
    printw( "| Podaj login:                |");
    move(11, 24);
    printw( "|                             |");
    move(12, 24);
    printw( "|_____________________________|");
    wrefresh(stdscr);

    move(10,39);
    raw();
    nonl();
    keypad(stdscr, FALSE);
    char username[14];
    attron(A_BOLD);
    getstr(username);
    attroff(A_BOLD);
    getch();

}
