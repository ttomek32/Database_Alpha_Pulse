#ifndef DATABASE_LIB_H_INCLUDED
#define DATABASE_LIB_H_INCLUDED

void intro();
void login();
void menu (int pozycja_menu);
//void exit_DB();

void ramka(short color1, short color2, int sleep);
void neon(char* text, int line, int full);
void boxinfo (char* text,int pos, int line,int column, short color1, short color2);
void smallbox (char* text, int pos, int line, int column, short color1, short color2);
void boxmenu (char* text, char* text1 ,int pos ,int pos1 ,int line, int column, short color1, short color2);
void boxyn (char* title, short color1, short color2);
void exityn (char* title, short color1, short color2);

#endif // DATABASE_LIB_H_INCLUDED
