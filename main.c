#include "silnik_gry.h"
#include "dane.h"
#include "menu.h"
#include "rysuj.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
initscr();
getmaxyx(stdscr,ekran.wysokosc,ekran.szerokosc);
keypad(stdscr,true);
menu();
endwin();
return 0;
}
