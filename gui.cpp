#include <curses.h>
#include <windows.h>
#include "database_lib.h"

void ramka(short color1, short color2,int sleep){

    start_color();
    attron( COLOR_PAIR( 1 ) );
    init_pair( 1, color1, color2 );
    mvprintw(0,0,"+------------------------------------------------------------------------------+");
    wrefresh(stdscr);

    int i;
    for (i=0;i<23;i++){

        printw( "|                                                                              |");
        wrefresh(stdscr);
        Sleep(sleep);
    }

    printw( "+------------------------------------------------------------------------------+");
    mvprintw(24,14," (C) 2013-2014, Thomas Martin. All rights reserved. ");
    wrefresh(stdscr);
    attroff( COLOR_PAIR( 1 ) );

}

void boxinfo (char* text,int pos, int line,int column, short color1, short color2){

    start_color();
    attron( COLOR_PAIR( 2 ) );
    init_pair( 2, color1, color2 );

    mvprintw(line,column,       "#=================================[?][_][X]");
    mvprintw(line + 1,column,   "#                                         #");
    mvprintw(line + 2,column,   "#                                         #");
    mvprintw(line + 2,column + pos,"%s",text);
    mvprintw(line + 3,column,   "#                                         #");
    mvprintw(line + 4,column,   "#=========================================#");

    wrefresh(stdscr);
    attroff( COLOR_PAIR( 2 ) );

}

void boxmenu (char* text, char* text1 ,int pos ,int pos1 ,int line, int column, short color1, short color2){

    start_color();
    attron( COLOR_PAIR( 2 ) );
    init_pair( 2, color1, color2 );

    mvprintw(line,column,       "* * * * * * * * * * * * * * * * * * * * * * * *");
    mvprintw(line + 1,column,   "*                                             *");
    mvprintw(line + 2,column,   "*                                             *");
    mvprintw(line + 2,column + pos,"%s",text);
    mvprintw(line + 3,column,   "*                                             *");
    mvprintw(line + 3,column + pos1,"%s",text1);
    mvprintw(line + 4,column,   "*                                             *");
    mvprintw(line + 5,column,   "* * * * * * * * * * * * * * * * * * * * * * * *");

    wrefresh(stdscr);
    attroff( COLOR_PAIR( 2 ) );

}

void smallbox (char* text, int pos, int line, int column, short color1, short color2){

    start_color();
    attron( COLOR_PAIR( 2 ) );
    init_pair( 2, color1, color2 );


    mvprintw(line,column,     "|                                   |");
    mvprintw(line + 1,column, "|                                   |");
    mvprintw(line + 1,column + pos, "%s",text);
   // mvprintw(line + 2,column, "|                                   |");
    mvprintw(line + 2,column, "|___________________________________|");

    wrefresh(stdscr);
    attroff( COLOR_PAIR( 2 ) );

}

void boxyn (char* title, short color1, short color2){

    char yes[] = "YES";
    char no[] ="NO";
    int pos = 3;
    int pos1 = 6;
    int pos2 = 34;
    int column = 18;
    int line = 8;

    start_color();
    attron( COLOR_PAIR( 2 ) );
    init_pair( 2, color1, color2 );

    mvprintw(line,column,       "#=================================[?][_][X]");
    mvprintw(line,column + pos,"%s",title);
    mvprintw(line + 1,column,   "#                                         #");
    mvprintw(line + 2,column,   "#                                         #");
    mvprintw(line + 3,column,   "#                                         #");
    mvprintw(line + 4,column,   "#=========================================#");

    wrefresh(stdscr);
    //attroff( COLOR_PAIR( 2 ) );

    // Chose YES or NO

    int i = 2;
    int key;

    const short int min_select = 1;
    const short int max_select = 2;

    do
    {
        start_color();
        attron( COLOR_PAIR( 2 ) );
        init_pair( 2, color1, color2 );

        if( (key == 'a' or key == KEY_LEFT) && i != min_select )
        {
            i--;
        }
        else if( (key == 'd' or key == KEY_RIGHT) && i != max_select )
        {
            i++;
        }

        if( key == 13 )
        {
            switch( i )
            {
            case 1:
                // true
                break;

            case 2:
                // false
                break;
            }
        }

        switch( i )

        {
        case 1:
            attron( A_REVERSE );
            mvprintw( line + 2, column + pos1, yes );
            attroff( A_REVERSE );
            mvprintw( line + 2, column + pos2, no );
            break;

        case 2:
            mvprintw( line + 2, column + pos1, yes );
            attron( A_REVERSE );
            mvprintw( line + 2, column + pos2, no );
            attroff( A_REVERSE );
            break;
        }
        attroff( COLOR_PAIR( 2 ) );
        key = getch();
    } while( 1 );

    curs_set(1);
}

void neon (char* text, int line, int full){

    // Ta funkcja zostala stworzona przez: Martin Winged (Winged4ever)
    // https://github.com/Winged4Ever

    // Full - pelna animacja czy polowa

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
