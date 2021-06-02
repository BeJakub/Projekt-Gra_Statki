#include <iostream>
#include <conio.h>
#include <Windows.h>
#include"Gracz.h"
#include"Plansza.h"
#include"Statek.h"
#include"Komputer.h"
#include"Czlowiek.h"


void gra_jednoosobowa();
void gra_dwuosobowa();
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
		case 2:
		{
			gra_dwuosobowa();
		}
		case 3:
			cout << "Na planszach 10 na 10 przyjmuje sie, ze kazdy z graczy dysponuje flota zlozona z:\n";
			cout << "jednego czteromasztowca o wielkosci czterech kratek\n";
			cout << "dwóch trojmasztowcow o wielkosci trzech kratek\n";
			cout << "trzech dwumasztowcow o wielkosci dwóch kratek\n";
			cout << "czterech jednomasztowcow o wielkosci jednej kratki.\n";
			cout << "Aby przechodzic do nastepnego ruchu nalezy wciskac [ENTER]" << endl;
			cout << "znak ~ oznacza wode" << endl;
			cout << "znak S oznacza statek" << endl;
			cout << "znak X oznacza trafiony statek" << endl;
			cout << "znak ? oznacza pole nieznane" << endl;

			cout << "Autor Jakub Besz" << endl;
		case 4:
		{
			exit(0);
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
	k1.Ustaw_plansze_auto(p2, 0);
	while (stan_gry(p1, p2) == ROZGRYWKA_TRWA) {
		cout << "TWOJA PLANSZA: " << endl;
		p1.rysuj_plansze();
		cout << "\n";
		cout << "PLANSZA TWOJEGO PRZECIWNIKA:" << endl;
		p2.rysuj_plansze_trafien();
		cout << "\n";
		cz1.Nastepny_ruch(p2);

	    k1.Nastepny_ruch_auto(p1);

	}

	if (stan_gry(p1, p2) == G1_WIN) {
		cout << cz1.get_nazwa() << " wygral!" << endl;
	}
	else
		cout << k1.get_nazwa() << " wygral!" << endl;

}
void gra_dwuosobowa() {
	int pierwszy_gracz;
	string wejscie, imie;
	Czlowiek cz1, cz2;
	Plansza p1, p2;
	Plansza* test;

	cout << "Podaj nazwe gracza nr 1: ";
	cin >> imie;
	cz1.set_nazwa(imie);
	cout << "Podaj nazwe gracza nr 2: ";
	cin >> imie;
	cz2.set_nazwa(imie);
	cout << "Kto ma miec pierwszy ruch?" << endl;
	cout << "1." << cz1.get_nazwa()<<" / 2. "<<cz2.get_nazwa()<< endl;
	cout << "Wybor: ";
	cin >> pierwszy_gracz;

	if (pierwszy_gracz == 1) {
		cz1.Ustaw_plansze(p1);
		cz2.Ustaw_plansze(p2);
	}
	else {  
		cz2.Ustaw_plansze(p2);
		cz1.Ustaw_plansze(p1);
	}
	if (pierwszy_gracz == 1) {
		while (stan_gry(p1, p2) == ROZGRYWKA_TRWA) {
			cout <<cz1.get_nazwa()<< " TWOJA PLANSZA: " << endl;
			p1.rysuj_plansze();
			cout << "\n";
			cout << "PLANSZA TWOJEGO PRZECIWNIKA:" << endl;
			p2.rysuj_plansze_trafien();
			cout << "\n";
			cz1.Nastepny_ruch(p2);

			system("cls");
			cout << "ZAMIANA GRACZY! Za 5 sekund pojawi sie plansza gracza nr 2"<<endl;
			Sleep(3000);
			for (int i = 5; i > 0; --i) {
				cout << i;
				Sleep(1000);
				system("cls");
			}
			cout <<endl<<cz2.get_nazwa()<< " TWOJA PLANSZA: " << endl;
			p2.rysuj_plansze();
			cout << "\n";
			cout << "PLANSZA TWOJEGO PRZECIWNIKA:" << endl;
			p1.rysuj_plansze_trafien();
			cout << "\n";
			cz2.Nastepny_ruch(p1);
			system("cls");
			cout << "ZAMIANA GRACZY! Za 5 sekund pojawi sie plansza gracza nr 1" << endl;;
			Sleep(3000);
			for (int i = 5; i > 0; --i) {
				cout << i;
				Sleep(1000);
				system("cls");
			}

		}
	}
	else {
		while (stan_gry(p1, p2) == ROZGRYWKA_TRWA) {
			cout << cz2.get_nazwa() << " TWOJA PLANSZA: " << endl;
			p2.rysuj_plansze();
			cout << "\n";
			cout << "PLANSZA TWOJEGO PRZECIWNIKA:" << endl;
			p1.rysuj_plansze_trafien();
			cout << "\n";
			cz2.Nastepny_ruch(p1);

			system("cls");
			cout << "ZAMIANA GRACZY! Za 5 sekund pojawi sie plansza gracza nr 1" << endl;
			Sleep(3000);
			for (int i = 5; i > 0; --i) {
				cout << i;
				Sleep(1000);
				system("cls");
			}
			cout << endl << cz1.get_nazwa() << " TWOJA PLANSZA: " << endl;
			p1.rysuj_plansze();
			cout << "\n";
			cout << "PLANSZA TWOJEGO PRZECIWNIKA:" << endl;
			p2.rysuj_plansze_trafien();
			cout << "\n";
			cz1.Nastepny_ruch(p2);
			system("cls");
			cout << "ZAMIANA GRACZY! Za 5 sekund pojawi sie plansza gracza nr 2" << endl;;
			Sleep(3000);
			for (int i = 5; i > 0; --i) {
				cout << i;
				Sleep(1000);
				system("cls");
			}

		}
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
