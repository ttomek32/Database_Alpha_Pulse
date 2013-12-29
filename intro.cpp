#include <curses.h>
#include <windows.h>
#include "database_lib.h"

void intro() {

    curs_set(0); // cursor is off
    neon("L O A D N I N G . . .",23,1); // load neon animation on 23 line and full
    Sleep(500);

    ramka(COLOR_WHITE, COLOR_BLACK,25); // load ramka from gui.cpp

    // start logo animation

    start_color();
    init_pair( 1, COLOR_RED, COLOR_BLACK );
    attron( COLOR_PAIR( 1 ) );

    int line = 0;
    mvprintw(line+1,1, "                   +-------------------------------+                          "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+2,1, "                   |                               |                          "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+3,1, "                   |                               |                          "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+4,1, "                   |                               |                          "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+5,1, "                   +-------+       +-------+       |                          "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+6,1, "                           |       |       |       |                          "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+7,1, "                           |       |       |       |                          "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+8,1, "                           |       |       |       |                          "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+9,1,"                           |       +-------+       +-------+                  "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+10,1,"                           |                               |                  "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+11,1,"                           |                               |                  "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+12,1,"                           |                               |                  "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+13,1,"                           |       +-------+       +-------+                  "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+14,1,"                           |       |       |       |                          "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+15,1,"                           |       |       |       |                          "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+16,1,"                           |       |       |       |                          "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+17,1,"                           |       |       |       +-------+                  "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+18,1,"                           |       |       |               |                  "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+19,1,"                           |       |       |               |                  "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+20,1,"                           |       |       |               |                  "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+21,1,"                           +-------+       +---------------+                  "); Sleep(50); wrefresh(stdscr);
    mvprintw(line+22,1,"                                                                              "); Sleep(50); wrefresh(stdscr);

    attroff( COLOR_PAIR( 1 ) );
    wrefresh(stdscr);

    start_color();
    attron( COLOR_PAIR( 1 ) );
    init_pair( 1, COLOR_WHITE, COLOR_RED );

    // this animation make red color on logo

    int i = 23;
    move(23,2);

    for (i=23;i>-1;i--){

        printw( "                                                                             ");
        wrefresh(stdscr);
        Sleep(50);
        move(i,2);
    }
    attroff( COLOR_PAIR( 1 ) );

    // end of logo animation

    start_color();
    attron( COLOR_PAIR( 1 ) );
    init_pair( 1, COLOR_WHITE, COLOR_BLACK );

    neon(" . . . Alpha Pulse . . . ",22,0);

    attroff( COLOR_PAIR( 1 ) );

    wrefresh(stdscr);
    curs_set(1); // on cursor
    Sleep(2000);
}

