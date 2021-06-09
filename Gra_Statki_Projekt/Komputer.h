
#include"Gracz.h"
#include "Plansza.h"
#include <vector>
#include <stack>


#ifndef KOMPUTER_H
#define KOMPUTER_H


class Komputer:public Gracz
{
	stack<int>ostatni_hitx;
	stack<int>ostatni_hity;
	vector <int> strzal_x;
	vector <int>strzal_y;
	int licznik;
	bool ostatni_strzal;
	bool hunt_poziom;
	bool hunt_pion;
public:
	Komputer(bool, int);
	void Ustaw_plansze_auto(Plansza& p, bool);
	void Nastepny_ruch_auto(Plansza& p);


};

#endif