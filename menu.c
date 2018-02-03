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

void ustawienia_szybkosci()
{
    clear();
    refresh();
    char txt0[] = "Latwy";
    char txt1[] = "Sredni";
    char txt2[] = "Trudny";
    int ktory = 1, znak;
    const short int min_wybor = 1, max_wybor = 3;
    do
    {

        clear();
        if( znak == KEY_UP && ktory != min_wybor )
        {
            ktory--;
        }
        else if( znak == KEY_DOWN && ktory != max_wybor )
        {
            ktory++;
        }
        if( znak == 10 )
        {
            switch( ktory )
            {
            case 1:
               waz.szybkosc = 4;
                break;
            case 2:
                waz.szybkosc = 3;
                break;
            case 3:
                waz.szybkosc = NULL;
                break;
            }
            break;
        }
       switch( ktory )
        {
        case 1:

            mvprintw( 1, 0, txt1 );
            mvprintw( 2, 0, txt2 );
            attron( A_REVERSE );
            mvprintw( 0, 0, txt0 );

            break;

        case 2:
            mvprintw( 0, 0, txt0 );
            mvprintw( 2, 0, txt2 );
            attron( A_REVERSE );
            mvprintw( 1, 0, txt1 );
            break;

        case 3:
            mvprintw( 0, 0, txt0 );
            mvprintw( 1, 0, txt1 );
            attron( A_REVERSE );
            mvprintw( 2, 0, txt2 );
            break;
        }
        attroff( A_REVERSE );
        znak = getch();
    } while( ktory != 3 || znak != 10 );
menu();
}
void menu()
{
    char txt0[] = "Nowa Gra";
    char txt1[] = "Poziom trudniosci";
    char txt2[] = "Wyjscie";
    int ktory = 1, znak;
    const short int min_wybor = 1, max_wybor = 3;
    while( ktory != 3 || znak != 10 )
    {

        clear();
        if( znak == KEY_UP && ktory != min_wybor )
        {
            ktory--;
        }
        else if( znak == KEY_DOWN && ktory != max_wybor )
        {
            ktory++;
        }
        if( znak == 10 )
        {
            switch( ktory )
            {
            case 1:
               snake();
                break;
            case 2:
                ustawienia_szybkosci();
                break;
            case 3:
               break;
            }
            break;
        }
       switch( ktory )
        {
        case 1:

            mvprintw( 1, 0, txt1 );
            mvprintw( 2, 0, txt2 );
            attron( A_REVERSE );
            mvprintw( 0, 0, txt0 );

            break;

        case 2:
            mvprintw( 0, 0, txt0 );
            mvprintw( 2, 0, txt2 );
            attron( A_REVERSE );
            mvprintw( 1, 0, txt1 );
            break;

        case 3:
            mvprintw( 0, 0, txt0 );
            mvprintw( 1, 0, txt1 );
            attron( A_REVERSE );
            mvprintw( 2, 0, txt2 );
            break;
        }
        attroff( A_REVERSE );
        znak = getch();
    }
    }
