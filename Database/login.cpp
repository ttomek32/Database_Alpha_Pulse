#include <curses.h>
#include <windows.h>
#include <assert.h>
#include "database_lib.h"

int szukajlogin(char*);
int szukajhaslo(char*);

int szukajlogin(char* name){

    char username[] = "admin";

    if ( strcmp ( name, username) == 0 ) {

        return TRUE;

    } else {

        return FALSE;

    }
}

int szukajhaslo(char* pass){

    char haslo[] = "admin";

    if ( strcmp ( pass, haslo) == 0 ) {

        return TRUE;

    } else {

        return FALSE;

    }
}



void login(){

    char name[14];
    char pass[14];
    int w = 0;

    wclear(stdscr);

    ramka(COLOR_WHITE, COLOR_CYAN,0);// Load ramka

    boxinfo("Login panel.",13,5,20,COLOR_WHITE,COLOR_BLUE); // Load box info

    smallbox ("Login: ",3,10,23,COLOR_WHITE,COLOR_BLUE); // Load small box

    start_color();
    attron( COLOR_PAIR( 2 ) | A_BOLD );
    init_pair( 2, COLOR_WHITE, COLOR_BLUE );
    flushinp();
    mvgetnstr(11,33,name,20);
    attroff( COLOR_PAIR( 2 ) | A_BOLD );

    if (szukajlogin(name) == TRUE) {

        ramka(COLOR_WHITE, COLOR_CYAN,0);// Load ramka
        boxinfo("Login panel.",13,5,20,COLOR_WHITE,COLOR_BLUE); // Load box info
        smallbox ("Login: ",3,10,23,COLOR_WHITE,COLOR_BLUE); // Load small box

        start_color();
        attron( COLOR_PAIR( 2 ) | A_BOLD );
        init_pair( 2, COLOR_WHITE, COLOR_BLUE );
        mvprintw(11,33,"%s",name);
        attroff( COLOR_PAIR( 2 ) | A_BOLD );

        smallbox ("Password: ",3,12,23,COLOR_WHITE,COLOR_BLUE); // Load small box

        move(13,36);
        noecho();
        getnstr(pass,16);
        echo();
        //mvprintw(13,39,"*******"); // Not now
        attroff( COLOR_PAIR( 1 ) );

        if (szukajhaslo(pass) == TRUE) {

                curs_set(0);
                boxinfo ("Logged in as: ",10,17,20,COLOR_WHITE,COLOR_GREEN); // Load box
                start_color();
                attron( COLOR_PAIR( 2 ) );
                init_pair( 2, COLOR_WHITE, COLOR_GREEN );
                mvprintw(19,44,name);
                attroff( COLOR_PAIR( 2 ) );
                wrefresh(stdscr);

                Sleep(2000);
                curs_set(1);

            } else {

                curs_set(0);
                boxinfo ("You have entered a wrong password!",5,17,20,COLOR_WHITE,COLOR_RED); // Load small box
                wrefresh(stdscr);
                Sleep(1000);
                curs_set(1);
                login();
            }

        } else  {

                curs_set(0);
                ramka(COLOR_WHITE, COLOR_CYAN,0);// Load ramka
                boxinfo("Login panel.",13,5,20,COLOR_WHITE,COLOR_BLUE); // Load box info
                smallbox ("Login: ",3,10,23,COLOR_WHITE,COLOR_BLUE); // Load small box

                start_color();
                attron( COLOR_PAIR( 2 ) | A_BOLD );
                init_pair( 2, COLOR_WHITE, COLOR_BLUE );
                mvprintw(11,33,"%s",name);
                attroff( COLOR_PAIR( 2 ) | A_BOLD );

                boxinfo ("There is no such user.",10,17,20,COLOR_WHITE,COLOR_RED); // Load small box
                wrefresh(stdscr);
                Sleep(1000);
                curs_set(1);
                login();
        }
}