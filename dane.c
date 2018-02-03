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

void snake()
{
	jedzenie_funkcja();
	nodelay(stdscr,true);
	curs_set(0);
	noecho();
	raw();
	cbreak();
	refresh();
	dane();
	while(1)
	{
		kierunek();
		gra_dalej();
		zjedzenie_pokarmu();
		if(zdzerzenie()==true)
		break;
		if(kanibal()==true)
		break;
		rysuj();
	}

	nodelay(stdscr,false);
	koniec_gry();

}
void dane ()
{
    if(waz.szybkosc==NULL)
    waz.szybkosc = 2;
	waz.kierunek = prawo;
	waz.wielkosc = 1;
	waz.cialo = malloc (ekran.szerokosc*ekran.wysokosc * sizeof (struct kawalek_weza)*waz.wielkosc);
	if (waz.cialo == NULL)
	{
		mvprintw(25,25,"Blad alokacji pamieci");
	}

	waz.cialo[0].x = ekran.szerokosc/2;
	waz.cialo[0].y = ekran.wysokosc/2;

}
