#include "Statek.h"


using namespace std;

Statek::Statek(int x, int y, int r, bool o, bool z) {
	pozycja_x = x;
	pozycja_y = y;
	rozmiar_statku = r;
	strefa_statku = new char[rozmiar_statku];
	for (int i = 0; i < rozmiar_statku; ++i) {
		strefa_statku[i] = znak_statku;
	}
	orientacja = o;
	zatopiony = z;
}
Statek::Statek(int x, int y) {
	pozycja_x = x;
	pozycja_y = y;
}

int Statek::get_x() {
	return pozycja_x;
}
int Statek::get_y() {
	return pozycja_y;
}
int Statek::get_rozmiar() {
	return rozmiar_statku;
}
bool Statek::czy_zatopiony() {
	return zatopiony;
}
bool Statek::jaka_orientacja() {
	return orientacja;
}
bool Statek::sprawdz_trafienie(int strzal_x, int strzal_y) {
	if (orientacja && (strzal_x < pozycja_x || strzal_x >= pozycja_x + rozmiar_statku||strzal_y!=pozycja_y)) {
		return false;
	}
	else if (!orientacja && (strzal_y < pozycja_y || strzal_y >= pozycja_y + rozmiar_statku||strzal_x!=pozycja_x)) {
		return false;
	}
	else {
		if (orientacja) {
			strefa_statku[strzal_x - pozycja_x] = 'X';

		}
		else
			strefa_statku[strzal_y - pozycja_y] = 'X';
	}

	zatopiony = true;
	for (int i = 0; i < rozmiar_statku; ++i) {
		if (strefa_statku[i] == znak_statku)
			zatopiony = false;
	}
	return true;
}

void Statek::print() {
	for (int i = 0; i < rozmiar_statku; ++i) {
		cout << strefa_statku[i];
	}
	return;
}

void Statek::ustaw_pozycje(int x, int y, bool h) {
	pozycja_x = x;
	pozycja_y = y;
	orientacja = h;
	return;

}