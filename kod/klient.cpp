#include "klient.h"
using namespace std;

klient::klient(int id, std::string i, std::string n, std::string em, ulga* u) {
	punktyLojalnosciowe = 0;
	id_klient = id;
	imie = i;
	nazwisko = n;
	email = em;
	rodzajUlgi = u;

}

klient::~klient() {


}

ulga* klient::ulga_get() {
	return rodzajUlgi;

}

void klient::ulga_set(ulga* u) {
	rodzajUlgi = u;
	return;

}

std::string klient::imie_get() {
	return imie;

}

std::string klient::nazwisko_get() {
	return nazwisko;

}

int klient::id_get() {
	return id_klient;

}

std::string klient::email_get() {
	return email;

}