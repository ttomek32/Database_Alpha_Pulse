#include <curses.h>
#include <windows.h>
#include <assert.h>
#include "database_lib.h"

void szukajlogin(char*);
void szukajhaslo(char*);

void szukajlogin(char ){

    char username[] = "admin";
}

void szukajhaslo(char ){

    char haslo[] = "admin";
}

void login(){
    // Special accounts
    char haslo[] = "toor";
    char username[] = "root";
    // Don't delete this

    char name[14];
    char pass[14];
    wclear(stdscr);

    ramka(COLOR_WHITE, COLOR_CYAN,25);// Load ramka

    boxinfo("Panel logowania.",13,5,20,COLOR_WHITE,COLOR_BLUE); // Load box info

    smallbox ("Podaj login: ",3,10,23,COLOR_WHITE,COLOR_BLUE); // Load small box

    start_color();
    attron( COLOR_PAIR( 2 ) | A_BOLD );
    init_pair( 2, COLOR_WHITE, COLOR_BLUE );
    flushinp();
    mvgetnstr(11,39,name,20);
    attroff( COLOR_PAIR( 2 ) | A_BOLD );

    if ( strcmp ( name, username) == 0 ) {
//    if ( strcmp ( name, szukajlogin();) == 0 ) {

        ramka(COLOR_WHITE, COLOR_CYAN,0);// Load ramka
        boxinfo("Panel logowania.",13,5,20,COLOR_WHITE,COLOR_BLUE); // Load box info
        smallbox ("Podaj login: ",3,10,23,COLOR_WHITE,COLOR_BLUE); // Load small box

        start_color();
        attron( COLOR_PAIR( 2 ) | A_BOLD );
        init_pair( 2, COLOR_WHITE, COLOR_BLUE );
        mvprintw(11,39,"%s",name);
        attroff( COLOR_PAIR( 2 ) | A_BOLD );

        smallbox ("Podaj haslo: ",3,12,23,COLOR_WHITE,COLOR_BLUE); // Load small box

        move(13,39);
        noecho();
        getnstr(pass,16);
        echo();
        //mvprintw(13,39,"*******"); // Not now
        attroff( COLOR_PAIR( 1 ) );

            if ( strcmp ( pass, haslo) == 0 ) {
         //   if ( strcmp ( pass, szukajhaslo()) == 0 ){

                curs_set(0);
                boxinfo ("Zalogowano jako: ",8,17,20,COLOR_WHITE,COLOR_GREEN); // Load box
                start_color();
                attron( COLOR_PAIR( 2 ) );
                init_pair( 2, COLOR_WHITE, COLOR_GREEN );
                mvprintw(19,45,username);
                attroff( COLOR_PAIR( 2 ) );
                wrefresh(stdscr);

                Sleep(2000);
                curs_set(1);

            } else {

                curs_set(0);
                boxinfo ("Podales zle haslo!",12,17,20,COLOR_WHITE,COLOR_RED); // Load small box
                wrefresh(stdscr);
                Sleep(3000);
                curs_set(1);
                login();
            }

        } else  {

                curs_set(0);
                ramka(COLOR_WHITE, COLOR_CYAN,0);// Load ramka
                boxinfo("Panel logowania.",13,5,20,COLOR_WHITE,COLOR_BLUE); // Load box info
                smallbox ("Podaj login: ",3,10,23,COLOR_WHITE,COLOR_BLUE); // Load small box

                start_color();
                attron( COLOR_PAIR( 2 ) | A_BOLD );
                init_pair( 2, COLOR_WHITE, COLOR_BLUE );
                mvprintw(11,39,"%s",name);
                attroff( COLOR_PAIR( 2 ) | A_BOLD );

                boxinfo ("Nie ma takiego uzytkownika!",8,17,20,COLOR_WHITE,COLOR_RED); // Load small box
                wrefresh(stdscr);
                Sleep(3000);
                curs_set(1);
                login();
        }
}
