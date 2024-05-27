#include "seans.h"
using namespace std;

seans::seans(string id_filmweb, string tytul, string data, string godzina, sala* s) {
	film* f = new film(id_filmweb, tytul);
	master = new wersja_film("PL", f);
	dzien = new data_seans(data, godzina);
	salaKinowa = s;

}

seans::~seans() {
	delete master;
	delete dzien;
	delete salaKinowa;

}

string seans::tytul_get() {
	return master->get_master()->get_tytul();

}

data_seans* seans::data_get() {
	return dzien;

}

list<miejsce_sali*> seans::sala_uklad_get() {
	return salaKinowa->get_miejsca();

}

int seans::liczba_kolumn() {
	return salaKinowa->liczba_kolumn();

}

int seans::liczba_rzedow() {
	return salaKinowa->liczba_rzedow();

}