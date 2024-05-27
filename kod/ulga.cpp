#include "ulga.h"
using namespace std;

ulga::ulga(string typ, int opust) {
	rodzajZnizki = typ;
	wartosc = opust;

}

ulga::~ulga() {


}

string ulga::rodzaj_get() {
	return rodzajZnizki;

}

int ulga::wartosc_get() {
	return wartosc;

}