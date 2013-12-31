#include <curses.h>
#include <windows.h>
#include <assert.h>
#include <fstream>
#include "database_lib.h"

int main {}

    fstream acc;
    acc.open( "accounts.dat", std::ios::in );
    if( acc.good() == true )
    {

        mvprintw(1,1,"Yes");
        acc.close();
    } else {mvprintw(1,1,"Yes");}
    return( 0 );
