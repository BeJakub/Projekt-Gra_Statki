#include "Czlowiek.h"


void Czlowiek::Ustaw_plansze(Plansza& p1,string a) {
	int x_we, y_we;
	int orientacja_we;
	int licznik;
	string wejscie;

	for (int i = 0; i < ILOSC_STATKOW; ++i) {

		licznik = 0;

		do 
		{
			p1.rysuj_plansze();
			if (licznik > 0) {
				cout << "Podales zle wspolrzedne! Sprobuj ponownie!" << endl;
		     }
			cout << a <<" wprowadz wspolrzedne [DUZA LITERA][0-9] dla Twojego statku o rozmiarze " << ROZMIARY_STATKOW[i] << " kratek: ";
			if (i < 1) { cin.ignore(); }
			//cin.ignore();
			wejscie = sprawdz_wejscie();
			x_we = static_cast<int>(wejscie[0]);
			y_we = static_cast<int>(wejscie[1]);
			cout << a << " wprowadz polozenie naszego statku (1 - poziome polozenie, 0 - pionowe polozenie: ";
			orientacja_we = sprawdz_int(0, 1);
			//cin >> orientacja_we;
			
			++licznik;
			system("cls");
			
		} while (!p1.sprawdz_polozenie(x_we-korekta_liter, y_we-korekta_liczb, i, orientacja_we));
	}
	//cout << "Twoja plansza: " << endl;
	//p1.rysuj_plansze();
	
	return;
}

void Czlowiek::Nastepny_ruch(Plansza &p) {
	int x_we, y_we, licznik{ 0 };
	bool poprawnosc = false;
	string wejscie;
	bool test = false;
	
	while(!poprawnosc){

		if (licznik > 0) {
			cout << "Strzal o takich wspolrzednych juz wykonales! Sprobuj ponownie! "<<endl;
		}
		cin.ignore();
		cout << "Kapitanie! Wybierz wspolrzedne strzalu [DUZA LITERA][0-9]: ";
		wejscie = sprawdz_wejscie();
		x_we = static_cast<int>(wejscie[0]);
		y_we = static_cast<int>(wejscie[1]);

		if (p.wartosc_polozenia(x_we - korekta_liter, y_we - korekta_liczb) != 'X' && p.wartosc_polozenia(x_we - korekta_liter, y_we - korekta_liczb) != '#') {
			test=p.Sprawdz_trafienie(x_we - korekta_liter, y_we - korekta_liczb,1);
			poprawnosc = true;
			//if (test) {
			//	p.rysuj_plansze_trafien();
			//}
		}
		else {
			++licznik;
		}
	
	}
	return;
}
/*
void Czlowiek::Nastepny_ruch(Plansza& p) {
	int x_we, y_we, licznik{ 0 };
	bool poprawnosc = true;
	bool test = false;

	string wejscie;
	cin.ignore();
	do{

		if (licznik>0) {
			cout << "Strzal o takich wspolrzednych juz wykonales! Sprobuj ponownie! " << endl;
		}
			
		cout << "Kapitanie! Wybierz wspolrzedne strzalu [DUZA LITERA][0-9]: ";
		wejscie = sprawdz_wejscie();
		x_we = static_cast<int>(wejscie[0]);
		y_we = static_cast<int>(wejscie[1]);

		if (p.wartosc_polozenia(x_we - korekta_liter, y_we - korekta_liczb) != 'X' && p.wartosc_polozenia(x_we - korekta_liter, y_we - korekta_liczb) != '#') {
			test=p.Sprawdz_trafienie(x_we - korekta_liter, y_we - korekta_liczb, 1);
			if (test) {
				p.rysuj_plansze_trafien();
			}
		}
		else {
			++licznik;
		}
	} while (test);
	return;
}
*/