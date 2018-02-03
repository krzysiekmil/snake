
static char cialo_waza = '*';
static char jedzenie = '$';
static char ramka_pionowo = '#',ramka_pozioma_gora = '=',ramka_pozioma_dol = '=';
struct karma
{
	int x;
	int y;
}karma;

struct waz
{
    int szybkosc;
	int wielkosc;
	int kierunek;
	struct kawalek_weza* cialo;
}waz;

struct kawalek_weza
{
	int x;
	int y;
}kawalek_weza;

struct ekran
{
	int szerokosc;
	int wysokosc;
} ekran;

typedef enum kierunek{gora,lewo,dol,prawo}kierunek_t;


void snake();
void dane();
