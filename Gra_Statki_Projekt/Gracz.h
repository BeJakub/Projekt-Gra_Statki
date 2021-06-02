#include <string>
#include <random>
#include <time.h>
#include <iostream>
#include<cstdlib>


#ifndef GRACZ_H
#define GRACZ_H


using namespace std;

class Gracz
{

	string nazwa;
	int numer_gracza;
	bool rodzaj_gracza;                     // 1 czlowiek, 0 -komputer

public:
	Gracz();
	Gracz(string, int, bool);
	Gracz(bool);
	~Gracz() { return; };
	int get_numer();
	bool jaki_gracz();
	string get_nazwa();
	void set_nazwa(string i);
	void set_numer(int nr);
	void set_rodzaj_gracza(bool x);
	string sprawdz_wejscie();
	
};
//korekta na kod ASCII
const int korekta_liter = 65;                        
const int korekta_liczb = 48;


#endif