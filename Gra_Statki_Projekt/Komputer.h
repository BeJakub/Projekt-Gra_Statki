
#include"Gracz.h"
#include "Plansza.h"


#ifndef KOMPUTER_H
#define KOMPUTER_H


class Komputer:public Gracz
{
public:

	void Ustaw_plansze_auto(Plansza& p, bool);
	void Nastepny_ruch_auto(Plansza& p);
};

#endif