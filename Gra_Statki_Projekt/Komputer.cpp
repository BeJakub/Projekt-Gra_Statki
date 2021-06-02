#include "Komputer.h"
#include "Plansza.h"


void Komputer::Ustaw_plansze_auto(Plansza& p, bool rysuj) {
	int x_we, y_we, orientacja_we;

	unsigned seed = time(0);  
	default_random_engine rng(seed);         //mechanizm losujacy

	uniform_int_distribution<int> k(0, 9);     //zakresy losowania liczb
	uniform_int_distribution<int> o(0, 1);

	for (int i = 0; i < ILOSC_STATKOW; ++i) {

		do {
			x_we = k(rng);
			y_we = k(rng);
			orientacja_we = o(rng);
		} while (!p.sprawdz_polozenie(x_we, y_we, i, orientacja_we));
	}

	if (rysuj) {
		cout << "Twoja plansza: " << endl;
		p.rysuj_plansze();
	}
}

void Komputer::Nastepny_ruch_auto(Plansza& p) {
	int x_we, y_we;
	bool poprawnosc = false;

	unsigned seed = time(0);
	default_random_engine rng(seed);
	uniform_int_distribution<int> w(0, 9);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			if (p.wartosc_polozenia(i, j) == 'X' && !p.Sprawdz_zatopienie(i, j)) {
				if (i > 0 && j > 0) {
					uniform_int_distribution<int> d(i-1, i+3);
					uniform_int_distribution<int> q(j -1 , j +2);
					while (!poprawnosc) {
						x_we = d(rng);
						y_we = q(rng);

						if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
							p.Sprawdz_trafienie(x_we, y_we, 0);
							poprawnosc = true;
						}
					}
				}
				else if (i > 0 && j == 0) {
					uniform_int_distribution<int> d(i-1, i+2);
					uniform_int_distribution<int> q(j, j + 2);
					while (!poprawnosc) {
						x_we = d(rng);
						y_we = q(rng);

						if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
							p.Sprawdz_trafienie(x_we, y_we, 0);
							poprawnosc = true;
						}
					}
				}
				else if (i == 0 && j > 0) {
					uniform_int_distribution<int> d(i, i+2);
					uniform_int_distribution<int> q(j-1, j+2);
					while (!poprawnosc) {
						x_we = d(rng);
						y_we = q(rng);

						if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
							p.Sprawdz_trafienie(x_we, y_we, 0);
							poprawnosc = true;
						}
					}
				}
			}
		}
		while (!poprawnosc) {
			x_we = w(rng);
			y_we = w(rng);

			if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
				p.Sprawdz_trafienie(x_we, y_we, 0);
				poprawnosc = true;
			}

		}
	}
}


/*
void Komputer::Nastepny_ruch_auto(Plansza& p) {
	int x_we, y_we;
	bool poprawnosc = false;

	unsigned seed = time(0);
	default_random_engine rng(seed);
	uniform_int_distribution<int> w(0, 9);

	while (!poprawnosc) {
		x_we = w(rng);
		y_we = w(rng);

		if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
			p.Sprawdz_trafienie(x_we, y_we,0);
			poprawnosc = true;
		}
	}
}
*/
