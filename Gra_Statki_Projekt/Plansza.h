#include <iostream>
#include <vector>
#include<Windows.h>
#include "Statek.h"

#ifndef PLANSZA_H
#define PLANSZA_H


using namespace std;




class Plansza
{
	vector <vector<char>>plansza_gry;
	const int WYMIAR_PLANSZY = 10;
	const char WODA = '~';
	vector <Statek>statki;
	
public:
	//vector <Statek>statki;
	Plansza();
	bool sprawdz_polozenie(int, int, int, bool);
	void rysuj_plansze();
	void rysuj_plansze_trafien();
	char wartosc_polozenia(int, int);
	bool Sprawdz_trafienie(int, int, bool);
	int ilosc_trafien();
	bool Sprawdz_zatopienie(int, int);
};
const int ILOSC_STATKOW = 10;
const int ROZMIARY_STATKOW[ILOSC_STATKOW] = { 4,3,3,2,2,2,1,1,1,1 };
const int suma_kratek_statkow = 20;
void odliczanie();
#endif