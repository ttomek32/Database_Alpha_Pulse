#include <curses.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "database_lib.h"

void search_u(){


    raw();
    keypad( stdscr, TRUE );
    curs_set(0);
    int key;
    char wpis[20];

    do {

        wclear(stdscr);
        ramka(COLOR_WHITE,COLOR_CYAN,0);
        ramka2(COLOR_WHITE,COLOR_CYAN,0);

        start_color();
        attron( COLOR_PAIR( 2 ) );
        init_pair( 2, COLOR_WHITE, COLOR_CYAN );

        mvprintw(2,32,"Search for users.");
        mvprintw(4,(80/2)-8,"Search: ");
        curs_set(1);
        echo();
        mvgetnstr(4,40,wpis,20);

            wclear(stdscr);
            ramka(COLOR_WHITE,COLOR_CYAN,0);
            ramka2(COLOR_WHITE,COLOR_CYAN,0);

            start_color();
            attron( COLOR_PAIR( 2 ) );
            init_pair( 2, COLOR_WHITE, COLOR_CYAN );

            mvprintw(2,32,"Search for users.");
            mvprintw(4,(80/2)-8,"Search: ");
            curs_set(1);

            mvprintw(4,40,wpis);


        std::fstream szukaj("database.dat");

        if(szukaj.is_open())
        {
            std::string szuk;
            int i = 8;

            while ( !szukaj.eof( )){

                getline(szukaj, szuk);
                std::string::size_type pos = szuk.find(wpis);


                if(pos != std::string::npos) {

                    mvprintw(6,3,"   ID:  |     NAME:      |   SURNAME:    |   AGE:    |   CLASS:  |   SEX:  ");
                    mvprintw(7,3,"--------+----------------+---------------+-----------+-----------+---------");

                    const char *cstr = szuk.c_str();
                    mvprintw(i,6,"%s",cstr);
                    i = i+1;

                } else {

                  //  mvprintw(8,6,"Nie ma takich danych\n");
                }

            }

            if (szukaj.eof()) {
              //  return FALSE;
            }

        } else {
            //return FALSE;
        }
        curs_set(0);
        mvprintw(21,(80/2)-20,"Press ESCAPE if you want return to menu.");
        key = getch();

    } while( key != VK_ESCAPE );



    attroff( COLOR_PAIR( 2 ) );
    curs_set(1);

}
