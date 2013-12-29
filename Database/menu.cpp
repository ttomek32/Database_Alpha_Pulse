#include <curses.h>
#include <windows.h>
#include <assert.h>
#include "database_lib.h"

void menu (int pozycja_menu) {

    raw();
    keypad( stdscr, TRUE );
    curs_set(0);
    ramka(COLOR_WHITE,COLOR_CYAN,1);
    border( '|', '|', '-', '-', '+', '+', '+', '+');
    flushinp();

    noecho();
    const char txt1[] = "- User List";
    const char txt2[] = "- Add a user";
    const char txt3[] = "- Edit user";
    const char txt4[] = "- Delete user";
    const char txt5[] = "- Print users";
    const char txt6[] = "- Search for user";
    const char txt7[] = "- Exit";

    int i = pozycja_menu; // For position in case
    int key;  //Key is char from keyboard



    const short int min_select = 1;
    const short int max_select = 7;

    //Position menu
    int line = 5;
    int column = 8;

   while( i <= 9) {
        if( (key == 'w' or key == KEY_UP) && i != min_select )
        {
            i--;
        }
        else if( (key == 's' or key == KEY_DOWN) && i != max_select )
        {
            i++;
        }

        if( key == 13 )
        {
            switch( i )
            {
            case 1:
                mvprintw( 1, 1, "Opcja 1" );
                break;
            case 2:
                mvprintw( 1, 1, "Opcja 2" );
                break;
            case 3:
                mvprintw( 1, 1, "Opcja 3" );
                break;
            case 4:
                mvprintw( 1, 1, "Opcja 4" );
                break;
            case 5:
                mvprintw( 1, 1, "Opcja 5" );
                break;
            case 6:
                mvprintw( 1, 1, "Opcja 6" );
                break;
            case 7:
                exityn (" Do you want exit? ", COLOR_WHITE, COLOR_RED);
                break;
            }

        }

        if (i == 1) {
            boxmenu ( "LISTA UZYTKOWNIKOW", "Pozwala na wyswietlenie wszystkich osob." ,3 ,3 ,15, 29, COLOR_YELLOW, COLOR_BLUE);
        }
        else if (i == 2) {
            boxmenu ( "DODAJ UZYTKOWNIKA", "Pozwala na dodanie do bazy uzytkownika." ,3 ,3 ,15, 29, COLOR_YELLOW, COLOR_BLUE);
        }
        else if (i == 3) {
            boxmenu ( "EDYTUJ UZYTKOWNIKA", "Pozwala na edycje wybranego uzytkownika" ,3 ,3 ,15, 29, COLOR_YELLOW, COLOR_BLUE);
        }
        else if (i == 4) {
            boxmenu ( "USUN UZYTKOWNIKA", "Pozwala na usuniecie z bazy uzytkownika." ,3 ,3 ,15, 29, COLOR_YELLOW, COLOR_BLUE);
        }
        else if (i == 5) {
            boxmenu ( "DRUKUJ UZYTKOWNIK(A)/OW", "Pozwala na wydrukowanie danego uzytkownika." ,3 ,3 ,15, 29, COLOR_YELLOW, COLOR_BLUE);
        }
        else if (i == 6) {
            boxmenu ( "SZUKAJ UZYTKOWNIKA", "Pozwala na znalezienie danego uzytkownika." ,3 ,3 ,15, 29, COLOR_YELLOW, COLOR_BLUE);
        }
        else if (i == 7) {
            boxmenu ( "WYJSCIE", "Wyjscie z programu." ,3 ,3 ,15, 29, COLOR_YELLOW, COLOR_BLUE);
        }

        start_color();
        attron( COLOR_PAIR( 2 ) );
        init_pair( 2, COLOR_WHITE, COLOR_CYAN );

        switch( i )

        {
        case 1:
            attron( A_REVERSE );
            mvprintw( line, column, txt1 );
            attroff( A_REVERSE );
            mvprintw( line +1, column, txt2 );
            mvprintw( line +2, column, txt3 );
            mvprintw( line +3, column, txt4 );
            mvprintw( line +4, column, txt5 );
            mvprintw( line +5, column, txt6 );
            mvprintw( line +6, column, txt7 );
            break;

        case 2:
            mvprintw( line, column, txt1 );
            attron( A_REVERSE );
            mvprintw( line +1, column, txt2 );
            attroff( A_REVERSE );
            mvprintw( line +2, column, txt3 );
            mvprintw( line +3, column, txt4 );
            mvprintw( line +4, column, txt5 );
            mvprintw( line +5, column, txt6 );
            mvprintw( line +6, column, txt7 );
            break;

        case 3:
            mvprintw( line, column, txt1 );
            mvprintw( line +1, column, txt2 );
            attron( A_REVERSE );
            mvprintw( line +2, column, txt3 );
            attroff( A_REVERSE );
            mvprintw( line +3, column, txt4 );
            mvprintw( line +4, column, txt5 );
            mvprintw( line +5, column, txt6 );
            mvprintw( line +6, column, txt7 );
            break;

        case 4:
            mvprintw( line, column, txt1 );
            mvprintw( line +1, column, txt2 );
            mvprintw( line +2, column, txt3 );
            attron( A_REVERSE );
            mvprintw( line +3, column, txt4 );
            attroff( A_REVERSE );
            mvprintw( line +4, column, txt5 );
            mvprintw( line +5, column, txt6 );
            mvprintw( line +6, column, txt7 );
            break;

        case 5:
            mvprintw( line, column, txt1 );
            mvprintw( line +1, column, txt2 );
            mvprintw( line +2, column, txt3 );
            mvprintw( line +3, column, txt4 );
            attron( A_REVERSE );
            mvprintw( line +4, column, txt5 );
            attroff( A_REVERSE );
            mvprintw( line +5, column, txt6 );
            mvprintw( line +6, column, txt7 );
            break;

        case 6:
            mvprintw( line, column, txt1 );
            mvprintw( line +1, column, txt2 );
            mvprintw( line +2, column, txt3 );
            mvprintw( line +3, column, txt4 );
            mvprintw( line +4, column, txt5 );
            attron( A_REVERSE );
            mvprintw( line +5, column, txt6 );
            attroff( A_REVERSE );
            mvprintw( line +6, column, txt7 );
            break;

        case 7:
            mvprintw( line, column, txt1 );
            mvprintw( line +1, column, txt2 );
            mvprintw( line +2, column, txt3 );
            mvprintw( line +3, column, txt4 );
            mvprintw( line +4, column, txt5 );
            mvprintw( line +5, column, txt6 );
            attron( A_REVERSE );
            mvprintw( line +6, column, txt7 );
            attroff( A_REVERSE );
            break;

        }

        mvprintw(22,6,"Use arrow or W/S to move in menu. Press ENTER if you choose options.");
        attroff( COLOR_PAIR( 2 ) );
        mvprintw(24,15," (C) 2013-2014, Thomas Martin. All rights reserved. ");
        key = getch();

    }

    curs_set(1);
    echo();

}

