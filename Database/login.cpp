#include <curses.h>
#include <windows.h>
#include <assert.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "database_lib.h"

int szukajlogin(char*);
int szukajhaslo(char*);

int szukajlogin(char* username){

    std::fstream acc("accounts.dat");

    if(acc.is_open())
    {
        std::string login;

        while ( !acc.eof( )){

            getline(acc, login);
            std::string::size_type pos = login.find(username);

            if(pos != std::string::npos) {

                return TRUE;

            } else {

                continue;
            }
        }

        if (acc.eof()) {

            return FALSE;
        }

    } else {
        mvprintw(2,1,"Error: File not found.");
        return FALSE;
    }
}

int szukajhaslo(char* pass){

    std::fstream acc("accounts.dat");

    if(acc.is_open())
    {
        std::string haslo;

        while ( !acc.eof( )){

            getline(acc, haslo);
            std::string::size_type pos = haslo.find(pass);

            if(pos != std::string::npos) {

                return TRUE;

            } else {

                continue;
            }
        }

        if (acc.eof()) {

            return FALSE;
        }

    } else {
        mvprintw(2,1,"Error: File not found.");
        return FALSE;
    }
}

void login(){

    char name[20];
    char pass[20];


    int a = 0; // Alert
    int o = 0; // Dezactive while


    while ( o < 1 ) {

        if ( a != 3){ // For block screen

            wclear(stdscr);
            ramka(COLOR_WHITE, COLOR_CYAN,0);// Load ramka
            ramka2(COLOR_WHITE, COLOR_CYAN,0);// Load ramka
            boxinfo("Login panel.",13,5,20,COLOR_WHITE,COLOR_BLUE); // Load box info
            smallbox ("Login: ",3,10,23,COLOR_WHITE,COLOR_BLUE); // Load small box

            start_color();
            attron( COLOR_PAIR( 2 ) | A_BOLD );
            init_pair( 2, COLOR_WHITE, COLOR_BLUE );

                flushinp();
                mvgetnstr(11,33,name,20);

            attroff( COLOR_PAIR( 2 ) | A_BOLD );


            if (szukajlogin(name) == TRUE) { // Good login

                ramka(COLOR_WHITE, COLOR_CYAN,0);
                ramka2(COLOR_WHITE, COLOR_CYAN,0);// Load ramka
                boxinfo("Login panel.",13,5,20,COLOR_WHITE,COLOR_BLUE);
                smallbox ("Login: ",3,10,23,COLOR_WHITE,COLOR_BLUE);

                start_color();
                attron( COLOR_PAIR( 2 ) | A_BOLD );
                init_pair( 2, COLOR_WHITE, COLOR_BLUE );

                    mvprintw(11,33,"%s",name);

                attroff( COLOR_PAIR( 2 ) | A_BOLD );

                smallbox ("Password: ",3,12,23,COLOR_WHITE,COLOR_BLUE); // Load small box

                noecho();
                mvgetnstr(13,36,pass,20);
                echo();

                    if (szukajhaslo(pass) == TRUE) { // Good pass

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
                        o = 1;

                    } else { // Wrong password

                        curs_set(0);
                        boxinfo ("You have entered a wrong password!",5,17,20,COLOR_WHITE,COLOR_RED);
                        wrefresh(stdscr);
                        Sleep(1000);
                        curs_set(1);
                        a++;
            }

            } else { // Wrong login

                curs_set(0);
                ramka(COLOR_WHITE, COLOR_CYAN,0);
                ramka2(COLOR_WHITE, COLOR_CYAN,0);// Load ramka
                boxinfo("Login panel.",13,5,20,COLOR_WHITE,COLOR_BLUE);
                smallbox ("Login: ",3,10,23,COLOR_WHITE,COLOR_BLUE);

                start_color();
                attron( COLOR_PAIR( 2 ) | A_BOLD );
                init_pair( 2, COLOR_WHITE, COLOR_BLUE );

                    mvprintw(11,33,"%s",name);

                attroff( COLOR_PAIR( 2 ) | A_BOLD );

                boxinfo ("There is no such user.",10,17,20,COLOR_WHITE,COLOR_RED);
                wrefresh(stdscr);
                Sleep(1000);
                curs_set(1);
                a++;

            }
        } else { // Block screen with timer

            curs_set(0);
            wclear(stdscr);
            ramka(COLOR_WHITE, COLOR_CYAN,0);
            ramka2(COLOR_WHITE, COLOR_CYAN,0);// Load ramka
            boxinfo("Limited access to:",13,5,19,COLOR_WHITE,COLOR_RED);

            int time = 10; // wait time in second

            while ( time >= 0 ){

                boxinfo("",20,12,21,COLOR_YELLOW,COLOR_RED);

                start_color();
                attron( COLOR_PAIR( 2 ));
                init_pair( 2, COLOR_WHITE, COLOR_RED );

                mvprintw(14,38,"%d",time);
                printw(" second.");
                wrefresh(stdscr);
                time = time - 1;
                Sleep(1000);

            }

            attroff( COLOR_PAIR( 2 ));

            curs_set(1);
            a = 0;
            o = 0;

        }
    }
}
