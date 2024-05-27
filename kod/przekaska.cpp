#include "przekaska.h"
using namespace std;

przekaska::przekaska(string n, double c) {
	cena = c;
	nazwa = n;

}

przekaska::~przekaska() {


}

double przekaska::cena_get() {
	return cena;

}

string przekaska::nazwa_get() {
	return nazwa;

}