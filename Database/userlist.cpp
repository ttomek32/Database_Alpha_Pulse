#include <curses.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "database_lib.h"

using namespace std;

void userlist(){

    raw();
    keypad( stdscr, TRUE );
    curs_set(0);
    wclear(stdscr);
    int key;
    //int w = 0;
    ulist(0,0,COLOR_BLACK,COLOR_MENUTEXT);

    while (key <= 21){

        start_color();
        attron( COLOR_PAIR( 2 ) );
        init_pair( 2, COLOR_BLACK, COLOR_MENUTEXT );

        mvprintw(2,3,"   ID:  |     NAME:      |   SURNAME:    |   AGE:    |   CLASS:  |   SEX:  ");
        mvprintw(3,3,"--------+----------------+---------------+-----------+-----------+---------");

        int i;

        for (i=4;i<=22;i++){

            mvprintw(i,3,  "        |                |               |           |           |         ");
            mvprintw(i+1,3,"--------+----------------+---------------+-----------+-----------+---------");
            mvprintw(0,14," ESC = Exit to menu. Use arrow or W/S to move in menu. ");
            wrefresh(stdscr);
            i = i + 1;

        }

    ifstream plik("database.dat");

    if(plik)
    {

        string linia;
        const char *cstr = linia.c_str();
        int i = 4;
        while(getline(plik, linia))
        {
            const char *cstr = linia.c_str();
            mvprintw(i,4,"%s",cstr);
            i = i+2;

        }
    }
    else
    {
        mvprintw(2,1,"Error: File not found.");
    }

        key = getch();
    }


    attroff( COLOR_PAIR( 2 ) );
    curs_set(1);

}
