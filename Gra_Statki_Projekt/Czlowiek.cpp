#include "Czlowiek.h"


void Czlowiek::Ustaw_plansze(Plansza& p1) {
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
			cout << "Kapitanie wprowadz wspolrzedne [DUZA LITERA][0-9]dla Twojego statku o rozmiarze " << ROZMIARY_STATKOW[i] << " kratek: ";
			if (i > 0) { cin.ignore(); }
			wejscie = sprawdz_wejscie();
			x_we = static_cast<int>(wejscie[0]);
			y_we = static_cast<int>(wejscie[1]);
			cout << "Kapitanie wprowadz polozenie naszego statku (1 - poziome polozenie, 0 - pionowe polozenie: ";
			cin >> orientacja_we;
			
			++licznik;
			
		} while (!p1.sprawdz_polozenie(x_we-korekta_liter, y_we-korekta_liczb, i, orientacja_we));
	}
	cout << "Twoja plansza: " << endl;
	p1.rysuj_plansze();
	
	return;
}
void Czlowiek::Nastepny_ruch(Plansza &p) {
	int x_we, y_we, licznik{ 0 };
	bool poprawnosc = false;
	string wejscie;
	
	while(!poprawnosc){

		if (licznik > 0) {
			cout << "Strzal o takich wspolrzednych juz wykonales! Sprobuj ponownie! "<<endl;
		}
		cout << "Kapitanie! Wybierz wspolrzedne strzalu [DUZA LITERA][0-9]: ";
		wejscie = sprawdz_wejscie();
		x_we = static_cast<int>(wejscie[0]);
		y_we = static_cast<int>(wejscie[1]);

		if (p.wartosc_polozenia(x_we - korekta_liter, y_we - korekta_liczb) != 'X' && p.wartosc_polozenia(x_we - korekta_liter, y_we - korekta_liczb) != '#') {
			p.Sprawdz_trafienie(x_we - korekta_liter, y_we - korekta_liczb);
			poprawnosc = true;
		}
		++licznik;
	}
	return;
}