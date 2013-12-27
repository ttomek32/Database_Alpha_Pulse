#include <curses.h>
#include <windows.h>

void load (char* text, int line, int full){

    // Ta funkcja zostala stworzona przez: Martin Winged (Winged4ever)
    // https://github.com/Winged4Ever

    if (full == 1) {

        int length = 0, i, origin = 0;

        /*Calculate string length*/
        while(text[length] != '\0'){

            length++;
        }

        origin = 40 - (length/2);

        /*Print it on the center of chosen line*/
        for (i = 0; i <= length; i++){

            move(line, origin+i);
            printw("%c", text[i]);
            wrefresh(stdscr);
            Sleep (100);
        }

        i = 0;
        /*De-print it*/
        for (i = 0; i <= length; i++){

            move(line, origin+i);
            printw(" ");
            wrefresh(stdscr);
            Sleep (100);
        }
    } else {

        int length = 0, i, origin = 0;

        /*Calculate string length*/
        while(text[length] != '\0'){

            length++;
        }

        origin = 40 - (length/2);

        /*Print it on the center of chosen line*/
        for (i = 0; i <= length; i++){

            move(line, origin+i);
            printw("%c", text[i]);
            wrefresh(stdscr);
            Sleep (100);
        }
    }
}

void intro() {

    curs_set(0);
    load("Wczytywanie...",23,1);
    Sleep(500);
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

    start_color();
    init_pair( 1, COLOR_RED, COLOR_BLACK );
    attron( COLOR_PAIR( 1 ) );

    move(1,1);
    printw( "                                                                              "); Sleep(50); wrefresh(stdscr); move(2,1);
    printw( "                   +-------------------------------+                          "); Sleep(50); wrefresh(stdscr); move(3,1);
    printw( "                   |                               |                          "); Sleep(50); wrefresh(stdscr); move(4,1);
    printw( "                   |                               |                          "); Sleep(50); wrefresh(stdscr); move(5,1);
    printw( "                   |                               |                          "); Sleep(50); wrefresh(stdscr); move(6,1);
    printw( "                   +-------+       +-------+       |                          "); Sleep(50); wrefresh(stdscr); move(7,1);
    printw( "                           |       |       |       |                          "); Sleep(50); wrefresh(stdscr); move(8,1);
    printw( "                           |       |       |       |                          "); Sleep(50); wrefresh(stdscr); move(9,1);
    printw( "                           |       |       |       |                          "); Sleep(50); wrefresh(stdscr); move(10,1);
    printw( "                           |       +-------+       +-------+                  "); Sleep(50); wrefresh(stdscr); move(11,1);
    printw( "                           |                               |                  "); Sleep(50); wrefresh(stdscr); move(12,1);
    printw( "                           |                               |                  "); Sleep(50); wrefresh(stdscr); move(13,1);
    printw( "                           |                               |                  "); Sleep(50); wrefresh(stdscr); move(14,1);
    printw( "                           |       +-------+       +-------+                  "); Sleep(50); wrefresh(stdscr); move(15,1);
    printw( "                           |       |       |       |                          "); Sleep(50); wrefresh(stdscr); move(16,1);
    printw( "                           |       |       |       |                          "); Sleep(50); wrefresh(stdscr); move(17,1);
    printw( "                           |       |       |       |                          "); Sleep(50); wrefresh(stdscr); move(18,1);
    printw( "                           |       |       |       +-------+                  "); Sleep(50); wrefresh(stdscr); move(19,1);
    printw( "                           |       |       |               |                  "); Sleep(50); wrefresh(stdscr); move(20,1);
    printw( "                           |       |       |               |                  "); Sleep(50); wrefresh(stdscr); move(21,1);
    printw( "                           |       |       |               |                  "); Sleep(50); wrefresh(stdscr); move(22,1);
    printw( "                           +-------+       +---------------+                  "); Sleep(50); wrefresh(stdscr); move(23,1);
    printw( "                                                                              "); Sleep(50); wrefresh(stdscr);

    attroff( COLOR_PAIR( 1 ) );
    wrefresh(stdscr);

    start_color();
    attron( COLOR_PAIR( 1 ) );
    init_pair( 1, COLOR_WHITE, COLOR_RED );

    move(1,2);
    i = 0;
    for (i=1;i<24;i++){

        printw( "                                                                             ");
        wrefresh(stdscr);
        Sleep(50);
        move(i,2);
    }

    start_color();
    attron( COLOR_PAIR( 1 ) );
    init_pair( 1, COLOR_WHITE, COLOR_BLACK );
    load(" . . . Alpha Pulse . . . ",23,0);
    attroff( COLOR_PAIR( 1 ) );
    wrefresh(stdscr);
    curs_set(1);
    Sleep(2000);
}

