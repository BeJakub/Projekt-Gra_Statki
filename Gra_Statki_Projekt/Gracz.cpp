#include "Gracz.h"


Gracz::Gracz() {
	nazwa = "";
	rodzaj_gracza = false;
	numer_gracza = 1;
}
Gracz::Gracz(string n, int num, bool a) {
	nazwa = n;
	rodzaj_gracza = a;
	numer_gracza = num;
}
Gracz::Gracz(bool a) {
	rodzaj_gracza = a;
}
string Gracz::get_nazwa() {
	return nazwa;
}
int Gracz::get_numer() {
	return numer_gracza;
}
bool Gracz::jaki_gracz() {
	return rodzaj_gracza;
}
void Gracz::set_numer(int n) {
	numer_gracza = n;
}
void Gracz::set_nazwa(string i) {
	nazwa = i;
}
void Gracz::set_rodzaj_gracza(bool r) {
	rodzaj_gracza = r;
}
string Gracz::sprawdz_wejscie() {
	
	bool poprawnosc = false;
	string wejscie;
	getline(cin, wejscie);
	
	while (!poprawnosc) {
		if (wejscie.size() == 2 && (wejscie[0] > 64 && wejscie[0] < 75) && (wejscie[1] > 47 && wejscie[1] < 58)) {
			poprawnosc = true;
		
		}
		else {
			cout << "\nBledne wspolrzedne! Sprobuj ponownie wprowadzic wspolrzedne [DUZA litera][cyfa 0-9]: ";
			getline(cin, wejscie);
		    
		}
		return wejscie;
	}

}

int sprawdz_int(int min, int max)
{
	string wejscie;
	getline(cin, wejscie);
	bool poprawnosc = false;
	int licznik = 0;
	char we_char;
	bool neg = false;
	int return_int = 0;

	while (!poprawnosc)
	{
		poprawnosc = true;
		if (licznik > 0)
		{
			cout << "Zle podales orientacje, sprobuj ponownie pomiedzy " << min;
			cout << " i " << max << "." << endl;
			getline(cin, wejscie);
		}
		if (wejscie.length() > 0)
		{

			for (int i = 0; i < wejscie.length(); i++)
			{
				we_char = static_cast<char>(wejscie[i]);

				if (i == 0 & we_char == '-')
				{
					neg = true;
				}
				else
				{
					if (we_char >= 48 && we_char <= 57)
					{
						return_int = return_int * 10 + (static_cast<int>(we_char) -
							48);
					}
					else
					{
						poprawnosc = false;
						break;
					}
				}
			}
		}

		else
		{
			poprawnosc = false;
		}


		if (poprawnosc && neg)
		{
			return_int = (-1) * return_int;
		}
		if (poprawnosc && (return_int<min || return_int>max))
		{
			poprawnosc = false;
		}

		if (!poprawnosc)
		{
			return_int = 0;
			neg = false;
		}

		licznik++;
	}

	return return_int;
}

