#include <curses.h>
#include <windows.h>
#include <assert.h>
#include "database_lib.h"



void exityn (char* title, short color1, short color2){

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
    int e = 0;
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
                exit_intro();
                break;

            case 2:
                menu(7);
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

    } while( e = 1 );

    curs_set(1);
}

void exit_intro(){

    wclear(stdscr);
    border( '|', '|', '-', '-', '+', '+', '+', '+');
    neon("Trwa Zamykanie...",23,1);
    wrefresh(stdscr);
    mvprintw(9,0, "Koniec programu, przycisnij przycisk..." );
    wrefresh(stdscr);
}
