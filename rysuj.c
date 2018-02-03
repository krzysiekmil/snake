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

void rysuj_wynik()
{
	mvprintw(0,0,"Twoj wynik = %d",waz.wielkosc-1);
}
void rysuj_gracza()
{
    mvaddch(waz.cialo[0].y,waz.cialo[0].x,cialo_waza);
    int i;
    for(i=1;i<waz.wielkosc;i++)
        mvaddch(waz.cialo[i].y,waz.cialo[i].x,cialo_waza);
}
void rysuj_pokarm()
{
mvaddch(karma.y,karma.x,jedzenie);
}
void rysuj_ramke()
{
	clear();
	int i;
	for (i = 0; i < (ekran.szerokosc-1); i++)
	{
		mvaddch (1, i,ramka_pozioma_gora);
		mvaddch ((ekran.wysokosc-1), i, ramka_pozioma_dol);
	}
	for (i = 1; i < (ekran.wysokosc-1); i++)
	{
		mvaddch (i, 0, ramka_pionowo);
		mvaddch (i, (ekran.szerokosc-1), ramka_pionowo);
	}
}
void rysuj()
{
    rysuj_ramke();
    rysuj_pokarm();
    rysuj_gracza();
    rysuj_wynik();
    usleep(100000*waz.szybkosc-75000);
    refresh();
}
