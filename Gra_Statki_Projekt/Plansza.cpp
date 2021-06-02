#include "Plansza.h"




Plansza::Plansza() {
	plansza_gry = vector<vector<char>>(WYMIAR_PLANSZY, vector<char>(WYMIAR_PLANSZY, WODA));

}

void Plansza::rysuj_plansze() {
	cout << "  A B C D E F G H I J\n";

	for (int i = 0; i < WYMIAR_PLANSZY; ++i) {
		cout << i << " ";
		for (int j = 0; j < WYMIAR_PLANSZY; ++j) {
			cout << plansza_gry[i][j] << " ";
		}
		cout << endl;
	}

}

bool Plansza::sprawdz_polozenie(int x, int y, int numer_statku, bool orientacja) {

	Statek s1(x, y, ROZMIARY_STATKOW[numer_statku], orientacja, 0);
	int r = s1.get_rozmiar();
	//jesli wybor jest poza rozmiarem planszy zwroc false
	if ((x >= WYMIAR_PLANSZY || y >= WYMIAR_PLANSZY)) {
		return false;
	}
	for (int i = 0; i < r; ++i) {
		if (orientacja && ((x + i) >= WYMIAR_PLANSZY)) {                                          //jesli statek wychodzi poza
			return false;                                                                             // plansze zwroc false
		}
		else if (!orientacja && ((y + i) >= WYMIAR_PLANSZY)) {
			return false;
		}

		if (orientacja && (plansza_gry[y][x + i]) != WODA) {                                      // jesli w tym miejscu jest juz
			return false;                                                                              // statek zwroc false
		}
		else if (!orientacja && (plansza_gry[y + i][x] != WODA)) {
			return false;
		}
	}
	//warunki polozenia bez "rogow" i krawedzi
	if (x != 0 && y != 0 && x != WYMIAR_PLANSZY - 1 && y != WYMIAR_PLANSZY - 1) {
		if (orientacja && (x + r) < WYMIAR_PLANSZY) {
			for (int k = y - 1; k < y + 2; ++k) {
				for (int j = x - 1; j < (x + r + 1); ++j) {
					if (plansza_gry[k][j] != WODA) {
						return false;
					}
				}
			}
		}
		if (!orientacja && (y + r) < WYMIAR_PLANSZY) {
			for (int k = y - 1; k < (y + r + 1); ++k) {
				for (int j = x - 1; j < x + 2; ++j) {
					if (plansza_gry[k][j] != WODA) {
						return false;
					}
				}
			}
		}
	}
	//warunki polozenia na lewy gorny rog
	if (x == 0 && y == 0) {
		if (orientacja) {
			for (int k = y; k < y + 2; ++k) {
				for (int j = x; j < (x + r + 1); ++j) {
					if (plansza_gry[k][j] != WODA) {
						return false;
					}
				}
			}
		}
		if (!orientacja) {
			for (int k = y; k < (y + r + 1); ++k) {
				for (int j = x; j < x + 2; ++j) {
					if (plansza_gry[k][j] != WODA) {
						return false;
					}
				}
			}
		}
		// warunki polozenia na prawy gorny rog
	}
	else if ((x + r) == WYMIAR_PLANSZY && y == 0 && orientacja) {

		for (int k = y; k < y + 2; ++k) {
			for (int j = x - 1; j < (x + r); ++j) {
				if (plansza_gry[k][j] != WODA) {
					return false;
				}
			}
		}

	}
	else if (x == WYMIAR_PLANSZY - 1 && y == 0 && !orientacja) {

		for (int k = y; k < r + 2; ++k) {
			for (int j = x - 1; j < x + 1; ++j) {
				if (plansza_gry[k][j] != WODA) {
					return false;
				}
			}
		}

	}
	// warunki polozenia na lewy dolny rog
	else if (x == 0 && (y + r) == WYMIAR_PLANSZY) {
		if (!orientacja) {
			for (int k = y - 1; k < (y + r); ++k) {
				for (int j = x; j < x + 2; ++j) {
					if (plansza_gry[k][j] != WODA) {
						return false;
					}
				}
			}
		}
	}
	else if (x == 0 && y == WYMIAR_PLANSZY - 1) {
		if (orientacja) {
			for (int k = y - 1; k < y + 1; ++k) {
				for (int j = x; j < r + 2; ++j) {
					if (plansza_gry[k][j] != WODA) {
						return false;
					}
				}
			}
		}
	}
	// warunki polozenia na prawy dolny rog
	else if (x + r == WYMIAR_PLANSZY && (y == WYMIAR_PLANSZY - 1)) {
		if (orientacja) {
			for (int k = y - 1; k < y + 1; ++k) {
				for (int j = x - 1; j < (x + r); ++j) {
					if (plansza_gry[k][j] != WODA) {
						return false;
					}
				}
			}
		}
	}
	else if (x == WYMIAR_PLANSZY - 1 && (y + r == WYMIAR_PLANSZY)) {
		if (!orientacja) {
			for (int k = y - 1; k < (y + r + 1); ++k) {
				for (int j = x - 1; j < (x + 1); ++j) {
					if (plansza_gry[k][j] != WODA) {
						return false;
					}
				}
			}
		}
	}
	else {
		//LEWA KRAWEDZ PLANSZY, WARUNEK GDY tylko x==0, TO NIE ROG!
		if (y > 0 < WYMIAR_PLANSZY - 1 && x == 0) {
			if (orientacja) {
				for (int k = y - 1; k < y + 2; ++k) {
					for (int j = x; j < (x + r + 1); ++j) {
						if (plansza_gry[k][j] != WODA) {
							return false;
						}
					}
				}
			}
			if (!orientacja) {
				for (int k = y - 1; k < (y + r + 1); ++k) {
					for (int j = x; j < x + 2; ++j) {
						if (plansza_gry[k][j] != WODA) {
							return false;
						}
					}
				}
			}
		}
		//WARUNEK, GDY TO NIE JEST ROG! A jedna ze wspolrzednych jest 0 druga nie !GORNA KRAWEDZ planszy!
		if (x > 0 < WYMIAR_PLANSZY && y == 0) {
			if (orientacja) {
				for (int k = y; k < y + 2; ++k) {
					for (int j = x - 1; j < (x + r + 1); ++j) {
						if (plansza_gry[k][j] != WODA) {
							return false;
						}
					}
				}
			}
			if (!orientacja) {
				for (int k = y; k < (y + r + 2); ++k) {
					for (int j = x - 1; j < x + 2; ++j) {
						if (plansza_gry[k][j] != WODA) {
							return false;
						}
					}
				}
			}
		}
		//WARUNEK DOLNA KRAWEDZ PLANSZY 
		if (x > 0 < WYMIAR_PLANSZY - 1 && y == WYMIAR_PLANSZY - 1 && orientacja) {
			for (int k = y - 1; k < y + 1; ++k) {
				for (int j = x - 1; j < (x + r + 1); ++j) {
					if (plansza_gry[k][j] != WODA) {
						return false;
					}
				}
			}
		}
		if (x > 0 < WYMIAR_PLANSZY - 1 && (y + r) == WYMIAR_PLANSZY && !orientacja) {
			for (int k = y - 1; k < (y + r); ++k) {
				for (int j = x - 1; j < x + 2; ++j) {
					if (plansza_gry[k][j] != WODA) {
						return false;
					}
				}
			}
		}
		//WARUNEK PRAWA KRAWEDZ PLANSZY
		if (0 < y < WYMIAR_PLANSZY - 1 && x == WYMIAR_PLANSZY - 1 && !orientacja) {
			for (int k = y - 1; k < (y + r + 1); ++k) {
				for (int j = x - 1; j < x + 1; ++j) {
					if (plansza_gry[k][j] != WODA) {
						return false;
					}
				}
			}
		}
		if (0 < y < WYMIAR_PLANSZY - 1 && (x + r) == WYMIAR_PLANSZY && orientacja) {
			for (int k = y - 1; k < y + 2; ++k) {
				for (int j = x - 1; j < (x + r); ++j) {
					if (plansza_gry[k][j] != WODA) {
						return false;
					}
				}
			}
		}

	}




	for (int i = 0; i < r; ++i) {
		if (orientacja) {
			plansza_gry[y][x + i] = 'S';
		}
		if (!orientacja) {
			plansza_gry[y + i][x] = 'S';
		}
	}
	statki.push_back(s1);

	return true;
}
char Plansza::wartosc_polozenia(int x, int y) {
	return plansza_gry[y][x];
}

bool Plansza::Sprawdz_trafienie(int x, int y,bool rodzaj_gracz) {
	for(auto i : statki){
		if (i.sprawdz_trafienie(x, y)) {
			plansza_gry[y][x] = 'X';
			odliczanie();
 			if (i.czy_zatopiony()) {
				if (rodzaj_gracz == 1) {
					cout << " Trafiony... ZATOPIONY! Aby przejsc dalej wcisnij [ENTER]" << endl;
				}
				else {
					cout << " Przeciwnik zatopil nasz okret! Aby przejsc dalej wcisnij [ENTER]" << endl;
				}
				cin.get();
				system("cls");
			
			}
			else {
				if (rodzaj_gracz == 1) {
					cout << " Kapitanie swietny strzal! Trafilismy wroga! Aby przejsc dalej wcisnij [ENTER]" << endl;
				}
				else {
					cout << " Przeciwnik trafil nasz okret! Aby przejsc dalej wcisnij [ENTER]" << endl;
				}
				cin.get();
				system("cls");
			}
			return true;
		}
	}
	odliczanie();
	plansza_gry[y][x] = '#'; //znak spud³owania
	if (rodzaj_gracz == 1) {
		cout << " Kapitanie spudlowalismy! Aby przejsc dalej wcisnij [ENTER]" << endl;
		cin.get();
		system("cls");
	}
	else if(rodzaj_gracz == 0) {
		cout << " Twoj przeciwnik spudlowal! Aby przejsc dalej wcisnij [ENTER]" << endl;
		cin.get();
		system("cls");
	}
	return false;

}
void Plansza::rysuj_plansze_trafien() {
	cout << "  A B C D E F G H I J\n";

	for (int i = 0; i < WYMIAR_PLANSZY; ++i) {
		cout << i << " ";
		for (int j = 0; j < WYMIAR_PLANSZY; ++j) {
			if (plansza_gry[i][j] == 'X' || plansza_gry[i][j] == '#') {
				cout << plansza_gry[i][j] << " ";
			}
			else
			{
				cout << '?' << " ";
			}
		}
		cout << endl;
	}

}
int Plansza::ilosc_trafien() {
	int licznik = 0;

	for (int i = 0; i < WYMIAR_PLANSZY; ++i) {
		for (int j = 0; j < WYMIAR_PLANSZY; ++j) {
			if ((plansza_gry[i][j])=='X')
			++licznik; 
		}
	}
	return licznik;
}

void odliczanie() {
	system("cls");
	for (int i = 3; i > 0; --i) {
		cout << i;
		Sleep(1000);
	    system("cls");
	}
}

bool Plansza::Sprawdz_zatopienie(int x, int y) {
	for (auto i : statki) {
		if (i.czy_istnieje(x, y)) {
			if (i.czy_zatopiony()) {
				return true;
			}
		}
	}
	return false;
}