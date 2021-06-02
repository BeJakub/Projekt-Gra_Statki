
#include <iostream>
#include "Gracz.h"

#ifndef STATEK_H
#define STATEK_H


class Statek
{
	char* strefa_statku;
	int rozmiar_statku;
	int pozycja_x, pozycja_y;
	bool zatopiony;                                      // 1-tak 0 - nie
	bool orientacja;                                     //1-poziom, 0 - pion
	char znak_statku = 'S';

public:
	Statek(int, int, int, bool, bool);
	Statek(int, int);
	void ustaw_pozycje(int, int, bool);
	bool czy_zatopiony();
	bool jaka_orientacja();
	bool sprawdz_trafienie(int, int);
	void print();
	int get_x();
	int get_y();
	int get_rozmiar();
	bool czy_istnieje(int, int);
};


#endif