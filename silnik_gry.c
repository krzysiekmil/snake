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

void gra_dalej()
{

	int i;
	for (i = (waz.wielkosc); i > 0; i--)
	{
		waz.cialo[i].x = waz.cialo[i-1].x;
		waz.cialo[i].y = waz.cialo[i-1].y;
	}


	if (waz.kierunek == gora)
		waz.cialo[0].y--;
	else if (waz.kierunek == lewo)
		waz.cialo[0].x--;

	else if (waz.kierunek == dol)
		waz.cialo[0].y++;

	else if (waz.kierunek == prawo)
		waz.cialo[0].x++;

}

int zjedzenie_pokarmu()
{
    if((waz.cialo[0].x==karma.x)&&(waz.cialo[0].y==karma.y))
    {
        waz.wielkosc++;
        jedzenie_funkcja();
        return true;
    }
    else
    {
        return false;
    }
}

int zdzerzenie()
{
	if(((waz.cialo[0].x<1)||(waz.cialo[0].x>(ekran.szerokosc-1)))||((waz.cialo[0].y<2)||(waz.cialo[0].y>(ekran.wysokosc-2))))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void koniec_gry()
{
    clear();
    printw("Koniec gry twoj wynik to = %d ",waz.wielkosc-1);
    free(waz.cialo);
    refresh();
    getch();
    getch();
    menu();
}

void kierunek ()
{
	int x=getch();
	switch(x)
	{
		case ERR:
		break;
		case KEY_UP: case 'w':
		zmiana_kierunku(gora);
		break;
		case KEY_DOWN : case 's':
		zmiana_kierunku(dol);
		break;
		case KEY_RIGHT : case 'd':
		zmiana_kierunku(prawo);
		break;
		case KEY_LEFT: case 'a':
		zmiana_kierunku(lewo);
		break;
		case 'p': case 32:
		pausa();
		break;
	}
}

void pausa()
{
	int i;
	while(1)
	{
	i=getch();
	if((i=='p')||(i==32))
	break;
	}
}

int kanibal()
{
    int i;
    for(i=1;i<(waz.wielkosc);i++)
    {
        if((waz.cialo[0].x==waz.cialo[i].x)&&(waz.cialo[0].y==waz.cialo[i].y))
        {
            return true;
            break;
        }
    }
    return false;
}
void zmiana_kierunku (kierunek_t nowy)
{
	if ((nowy == gora) && (waz.kierunek != dol) && (waz.kierunek != gora) )
		waz.kierunek = gora;

	else if ((nowy == lewo) && (waz.kierunek != prawo) &&(waz.kierunek != lewo) )
		waz.kierunek = lewo;

	else if ((nowy == dol) && (waz.kierunek !=gora) &&(waz.kierunek != dol) )
		waz.kierunek = dol;

	else if ((nowy == prawo) && (waz.kierunek != lewo) && (waz.kierunek!= prawo) )
		waz.kierunek = prawo;
}

void jedzenie_funkcja()
{
	srand(time(NULL));
	karma.x = (rand()%(ekran.szerokosc-2)+1);
	karma.y = (rand()%(ekran.wysokosc-3)+2);
	int i;
	for(i=0;i<waz.wielkosc-1;i++)
	{
		if((karma.x==waz.cialo[i].x)&&(karma.y==waz.cialo[i].y))
			break;
	}
}

