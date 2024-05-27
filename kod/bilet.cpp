#include "bilet.h"
using namespace std;

bilet::bilet(int id, string data, string godzina, double cen, ulga* u, seans* film, miejsce_sali* m) {
	data_seans* d = new data_seans(data, godzina);
	cena = new cena_seans(cen, d);
	uzytaUlga = u;
	s = film;
	miejsce = m;
	id_bilet = id;

}

bilet::~bilet() {
	delete cena;
	delete uzytaUlga;
	delete s;
	delete miejsce;

}

double bilet::cena_get() {
	return cena->get_cena() * (100 - uzytaUlga->wartosc_get()) / 100;

}

data_seans* bilet::data_get() {
	return cena->get_data();

}

void bilet::ulga_set(ulga* u) {
	uzytaUlga = u;

}

seans* bilet::seans_get() {
	return s;

}

ulga* bilet::ulga_get() {
	return uzytaUlga;

}

int bilet::id_get() {
	return id_bilet;

}