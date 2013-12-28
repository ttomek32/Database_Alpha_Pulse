#include <curses.h>
#include <windows.h>
#include <assert.h>

void username(char* name){
    name = "admin";
}
void checkpass(){}

void login(){

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
    attron( COLOR_PAIR( 1 ) );
    init_pair( 1, COLOR_WHITE, COLOR_BLUE );

    move(6, 23);
    printw( "#=======================[?][_][X]");
    move(7,23);
    printw( "#        Panel logowania.       #");
    move(8, 23);
    printw( "#===============================#");
    move(9, 24);
    printw( "|                             |");
    move(10,24);
    printw( "| Podaj login:                |");
    move(11, 24);
    printw( "|                             |");
    move(12, 24);
    printw( "|_____________________________|");
    wrefresh(stdscr);

    move(10,39);
    raw();
    nonl();
    keypad(stdscr, FALSE);
    char name[14];
    char us[] = "admin";
    attron(A_BOLD);
    getstr(name);
    attroff(A_BOLD);

    if ( strcmp ( name, us) == 0 ) {

        move(12, 24);
        printw( "| Haslo:                      |");
        move(13, 24);
        printw( "|_____________________________|");
        wrefresh(stdscr);

        move(12,33);
        noecho();
        char pass[14];
        char pa[] = "admin123";
        getstr(pass);
        echo();
        attroff( COLOR_PAIR( 1 ) );

        if ( strcmp ( pass, pa) == 0 ){

            attroff( COLOR_PAIR( 1 ) );
            start_color();
            attron( COLOR_PAIR( 1 ) );
            init_pair( 1, COLOR_WHITE, COLOR_GREEN );

            curs_set(0);
            move(15,22);
            printw( "#=========================[?][_][X]");
            move(16,22);
            printw( "#                                 #");
            move(17,22);
            printw( "#  Zalogowano jako:               #");
            move(17,42);
            printw( us );
            move(18,22);
            printw( "#                                 #");
            move(19,22);
            printw( "#=================================#");
            wrefresh(stdscr);
            Sleep(2000);
            attroff( COLOR_PAIR( 1 ) );
            curs_set(1);
            login();

        } else {

            attroff( COLOR_PAIR( 1 ) );
            start_color();
            attron( COLOR_PAIR( 1 ) );
            init_pair( 1, COLOR_WHITE, COLOR_RED );

            curs_set(0);
            move(15,22);
            printw( "#=========================[?][_][X]");
            move(16,22);
            printw( "#                                 #");
            move(17,22);
            printw( "#        Podales zle haslo!       #");
            move(18,22);
            printw( "#                                 #");
            move(19,22);
            printw( "#=================================#");
            wrefresh(stdscr);
            Sleep(2000);
            attroff( COLOR_PAIR( 1 ) );
            curs_set(1);
            login();

        };

    } else  {

        attroff( COLOR_PAIR( 1 ) );
        start_color();
        attron( COLOR_PAIR( 1 ) );
        init_pair( 1, COLOR_WHITE, COLOR_RED );

        curs_set(0);
        move(15,22);
        printw( "#=========================[?][_][X]");
        move(16,22);
        printw( "#                                 #");
        move(17,22);
        printw( "#   Nie ma takiego uzytkownika!   #");
        move(18,22);
        printw( "#                                 #");
        move(19,22);
        printw( "#=================================#");
        wrefresh(stdscr);
        Sleep(2000);
        attroff( COLOR_PAIR( 1 ) );
        curs_set(1);
        login();
    }

    getch();
}
