#include <curses.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "database_lib.h"

void print (){

     std::ifstream plik("database.dat");

            if(plik) {

                std::ofstream saveFile ("Savedatabase.txt");

                std::string textToSave;
                saveFile << textToSave;
                saveFile.close();

            } else {

                mvprintw(2,1,"Error: File not found.");

            }



}

