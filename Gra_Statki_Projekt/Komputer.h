
#include"Gracz.h"
#include "Plansza.h"
#include <vector>


#ifndef KOMPUTER_H
#define KOMPUTER_H


class Komputer:public Gracz
{
	bool trafienie_z_rzêdu;
	vector<int>ostatni_strzal;
public:

	void Ustaw_plansze_auto(Plansza& p, bool);
	void Nastepny_ruch_auto(Plansza& p);
};

#endif