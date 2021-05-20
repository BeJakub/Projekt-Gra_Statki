#include <iostream>
#include <conio.h>
#include <Windows.h>
#include"Gracz.h"
#include"Plansza.h"
#include"Statek.h"
#include"Komputer.h"
#include"Czlowiek.h"


void gra_jednoosobowa();
enum status{G1_WIN, G2_WIN, ROZGRYWKA_TRWA};
status stan_gry(Plansza & p1, Plansza& p2);

int main()
{
	int we;

	cout << "     MENU" << endl;
	cout << "1.Gra jednoosobowa (z 'komputerem')" << endl;
	cout << "2.Gra dwuosobowa" << endl;
	cout << "3.O grze" << endl;
	cout << "4.WYJSCIE" << endl;
	cout << "Wybor: ";
	cin >> we;

	switch (we) {
	case 1:
	{
		gra_jednoosobowa();
	}
	}

}
void gra_jednoosobowa() {
	int pierwszy_gracz;
	string wejscie, imie;
	Czlowiek cz1;
	Komputer k1;
	Plansza p1, p2;
	Plansza * test;
	
	
		cout << "Kto ma miec pierwszy ruch?" << endl;
	cout << "1. TY    /    2. Komputer" << endl;
	cout << "Wybor: ";
	cin >> pierwszy_gracz;
	if (pierwszy_gracz == 1) {
		test = &p1;
	}
	else { test = &p2; }
	cz1.set_numer(1);
	k1.set_numer(2);
	cout << "Podaj Twoja nazwe: ";
	cin >> imie;
	cz1.set_nazwa(imie);
	cout << "Podaj nazwe Twojego przeciwnika: ";
	cin >> imie;
	k1.set_nazwa(imie);
	cz1.Ustaw_plansze(p1);
	k1.Ustaw_plansze_auto(p2, 1);
	while (stan_gry(p1, p2) == ROZGRYWKA_TRWA) {
		cout << "TWOJA PLANSZA: " << endl;
		p1.rysuj_plansze();
		cout << "\n";
		cout << "PLANSZA TWOJEGO PRZECIWNIKA:" << endl;
		p2.rysuj_plansze_trafien();
		cout << "\n";
		cz1.Nastepny_ruch(p2);

		p1.rysuj_plansze();
		cout << "\n";
		cout << "PLANSZA TWOJEGO PRZECIWNIKA:" << endl;
		p2.rysuj_plansze_trafien();
		cout << "\n";
		Sleep(3000);

		cout << "TWOJA PLANSZA: " << endl;
		p2.rysuj_plansze();
		cout << "\n";
			cout << "PLANSZA TWOJEGO PRZECIWNIKA:" << endl;
		p1.rysuj_plansze_trafien();
		cout << "\n";
	    k1.Nastepny_ruch_auto(p1);

	}




}
status stan_gry(Plansza &p1, Plansza& p2) {
	if (p1.ilosc_trafien() == suma_kratek_statkow) {
		return G2_WIN;
	}
	else if (p2.ilosc_trafien() == suma_kratek_statkow) {
		return G1_WIN;
	}
	else {
		return ROZGRYWKA_TRWA;
	}
}
