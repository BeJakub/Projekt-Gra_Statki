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



