
#include"Gracz.h"
#include"Plansza.h"

#ifndef CZLOWIEK_H
#define CZLOWIEK_H
class Czlowiek : public Gracz
{
	public:
		Czlowiek() : Gracz(1) {}
		void Ustaw_plansze(Plansza& p,string);
		void Nastepny_ruch(Plansza& p);
};

#endif