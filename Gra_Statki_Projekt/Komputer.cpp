#include "Komputer.h"
#include "Plansza.h"

Komputer::Komputer(bool a,int x) {
	ostatni_strzal = a;
	licznik = x;
	hunt_poziom = a;
	hunt_pion = a;
}
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
/*
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


*/

void Komputer::Nastepny_ruch_auto(Plansza& p) {
	int x_we, y_we;
	bool poprawnosc = false;

	unsigned seed = time(0);
	default_random_engine rng(seed);
	uniform_int_distribution<int> w(0, 9);
	if (ostatni_strzal) {
		int x, y;
		int s_x, s_y;
		x = ostatni_hitx.top();
		y = ostatni_hity.top();

		uniform_int_distribution<int> losx(x - 1, x + 1);
		uniform_int_distribution<int> losy(y - 1, y + 1);
		//uniform_int_distribution<int> losx2(x, x + 1);
		//uniform_int_distribution<int> losy2(y, y + 1);
		uniform_int_distribution<int> losx2(x - 3, x );
		uniform_int_distribution<int> losy2(y - 3, y);
		uniform_int_distribution<int> losx3(x, x + 3);
		uniform_int_distribution<int> losy3(y, y + 3);

		if (licznik > 1) {
			
			int w_x, w_y;
			w_x = strzal_x.back();
			w_y = strzal_y.back();
			if (p.wartosc_polozenia(w_x,w_y)=='X') {
				ostatni_hitx.pop();
				ostatni_hity.pop();
			}
			s_x = ostatni_hitx.top();
			s_y = ostatni_hity.top();
 			if ((x != s_x && y == s_y)||hunt_poziom) {
				hunt_poziom = true;
				while (!poprawnosc) {
				
					bool dobry_los = false;
					while (!dobry_los) {
						x_we = losx(rng);
						y_we = s_y;
						if (x < 9 && x>0 && (p.wartosc_polozenia(x - 1, y) == '#')) {
							x_we = losx3(rng); 
						}
						else if (x < 9 && x>0 && (p.wartosc_polozenia(x + 1, y) == '#' )) {
							x_we = losx2(rng);
						}

						if (!(x_we < 0  || x_we > 9)) {
							dobry_los = true;
						}
						else {
							dobry_los = false;
						}
					}
				if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
					int zm;
					zm = p.Sprawdz_trafienie(x_we, y_we, 0);


					poprawnosc = true;
					if (zm && !p.Sprawdz_zatopienie(x_we, y_we)) {
						ostatni_strzal = true;
						ostatni_hitx.push(x_we);
						ostatni_hity.push(y_we);
						++licznik;
					}
					if (p.Sprawdz_zatopienie(x_we, y_we)) {
						ostatni_strzal = false;
						licznik = 0;
						hunt_poziom = false;
					}
						if (poprawnosc) {
					strzal_x.push_back(x_we);
					strzal_y.push_back(y_we);
				}
				}
			
			}
		}
		if ((x == s_x && y != s_y)&& hunt_pion) {}
		hunt_pion = true;
		while (!poprawnosc) {

			bool dobry_los = false;
			while (!dobry_los) {
				x_we = losx(rng);
				y_we = s_y;
				if (y < 9 && y>0 && (p.wartosc_polozenia(x , y-1) == '#')) {
					x_we = losy3(rng);
				}
				else if (y < 9 && y>0 && (p.wartosc_polozenia(x , y+1) == '#')) {
					x_we = losy2(rng);
				}

				if (!(x_we < 0 || x_we > 9)) {
					dobry_los = true;
				}
				else {
					dobry_los = false;
				}
			}
			if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
				int zm;
				zm = p.Sprawdz_trafienie(x_we, y_we, 0);


				poprawnosc = true;
				if (zm && !p.Sprawdz_zatopienie(x_we, y_we)) {
					ostatni_strzal = true;
					ostatni_hitx.push(x_we);
					ostatni_hity.push(y_we);
					++licznik;
				}
				if (p.Sprawdz_zatopienie(x_we, y_we)) {
					ostatni_strzal = false;
					licznik = 0;
					hunt_pion= false;
				}
				if (poprawnosc) {
					strzal_x.push_back(x_we);
					strzal_y.push_back(y_we);
				}
			}

		}
		}
		while (!poprawnosc) {
			bool dobry_los = false;
			while (!dobry_los) {
				x_we = losx(rng);
				y_we = losy(rng);
				if ((x + y) % 2 == 0 && (x_we + y_we) % 2 != 0) {
					dobry_los = true;
				}
				else if ((x + y) % 2 != 0 && (x_we + y_we) % 2 == 0) {
					dobry_los = true;
				}
				else if (x_we < 0 || y_we < 0 || x_we > 9 || y_we > 9) {
					dobry_los = false;
				}
				else {
					dobry_los = false;
				}
				
			}
			//if ((p.wartosc_polozenia(x+1, y) == 'X' || p.wartosc_polozenia(x,y) == '#'))

			if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
				int zm;
				zm = p.Sprawdz_trafienie(x_we, y_we, 0);

				poprawnosc = true;
				if (zm && !p.Sprawdz_zatopienie(x_we, y_we)) {
					ostatni_strzal = true;
					ostatni_hitx.push(x_we);
					ostatni_hity.push(y_we);
					++licznik;
				}
				if (p.Sprawdz_zatopienie(x_we, y_we)) {
					ostatni_strzal = false;
					licznik = 0;
				}
				if (poprawnosc) {
					strzal_x.push_back(x_we);
					strzal_y.push_back(y_we);
				}
			}
		}
	}
	else {

		while (!poprawnosc) {
			x_we = w(rng);
		   y_we = w(rng);
			//x_we = 2;
			//y_we = 1;

			if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
				int zm;
				zm = p.Sprawdz_trafienie(x_we, y_we, 0);
				poprawnosc = true;
				if (zm&& !p.Sprawdz_zatopienie(x_we, y_we)) {
					ostatni_strzal = true;
					ostatni_hitx.push(x_we);
					ostatni_hity.push(y_we);
					++licznik;
				}
				else {
					ostatni_strzal = false;
					licznik = 0;
				}
				if (poprawnosc) {
					strzal_x.push_back(x_we);
					strzal_y.push_back(y_we);
				}
			}
		}
		/*
		if (x == 0 && !p.Sprawdz_zatopienie(x, y)) {
			while (!poprawnosc) {
				x_we = losx2(rng);
				y_we = losy(rng);
				if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
					int zm;
					zm = p.Sprawdz_trafienie(x_we, y_we, 0);
					poprawnosc = true;
					if (zm && p.Sprawdz_zatopienie(x_we, y_we)) {
						ostatni_strzal = false;
					}

				}
			}
		}
		else if (y == 0 && !p.Sprawdz_zatopienie(x, y)) {
			while (!poprawnosc) {
				x_we = losx(rng);
				y_we = losy2(rng);
				if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
					int zm;
					zm = p.Sprawdz_trafienie(x_we, y_we, 0);

					poprawnosc = true;
					if (zm && p.Sprawdz_zatopienie(x_we, y_we)) {
						ostatni_strzal = false;
					}

				}
			}
		}
		else if(x!=0 || y!=0) {
			while (!poprawnosc) {
				bool dobry_los = false;
				while (!dobry_los) {
					x_we = losx(rng);
					y_we = losy(rng);
					if ((x + y) % 2 == 0 && (x_we + y_we) % 2 != 0) {
						dobry_los = true;
					}
					else if ((x + y) % 2 != 0 && (x_we + y_we) % 2 == 0) {
						dobry_los = true;
					}
					else if (x < 0 || y < 0 || x > 9 || y > 9) {
						dobry_los = false;
					}
					else {
						dobry_los = false;
					}
				}

				if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
					int zm;
					zm = p.Sprawdz_trafienie(x_we, y_we, 0);
					poprawnosc = true;
					if (zm&&p.Sprawdz_zatopienie(x_we,y_we)) {
						ostatni_strzal = false;
					}
				}
			}
		}
	}
	else {

		while (!poprawnosc) {
			x_we = w(rng);
			y_we = w(rng);
			//x_we = 4;
			//y_we = 0;

			if (p.wartosc_polozenia(x_we, y_we) != 'X' && p.wartosc_polozenia(x_we, y_we) != '#') {
				int zm;
				zm=p.Sprawdz_trafienie(x_we, y_we, 0);
				poprawnosc=true;
				if (zm) {
					ostatni_strzal = true;
					ostatni_hitx.push(x_we);
					ostatni_hity.push(y_we);
				}
				else {
					ostatni_strzal = false;
				}
			}
		}

	*/

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
				p.Sprawdz_trafienie(x_we, y_we, 0);
				poprawnosc = true;
			}
		}
	
}
*/

