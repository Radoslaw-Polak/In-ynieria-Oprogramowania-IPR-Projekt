#include "GUImanager.h"
using namespace std;

GUImanager::GUImanager() {
    win = new mainWindow();
    win->show();

}

GUImanager::~GUImanager() {
    delete win;

}

GUImanager& GUImanager::getInstance() {
    static GUImanager instance;
    return instance;

}

list<seans*> GUImanager::pobierzDane(string tyt, string data, string godz) {
    return k.szukajSeans(tyt, data, godz);

}

list<miejsce_sali*> GUImanager::pobierzDane(seans* s, bool wolne) {
    return k.szukajMiejsca(s, wolne);

}

std::list<przekaska*> GUImanager::pobierzDane(std::string nazw) {
    return k.szukajPrzekaska(nazw);

}

std::list<ulga*> GUImanager::pobierzDane(bool aktywna) {
    return k.szukajUlga(aktywna);

}

klient* GUImanager::pobierzDane(int id) {
    return k.szukajKlient(id).front();

}

bilet* GUImanager::pobierzDane(int id, bool temp) {
    return k.szukajBilet(id).front();

}

double GUImanager::pobierzDane(data_seans* data) {
    return k.szukajCena(data);

}

int GUImanager::pobierzDane() {
    return k.noweIdBilet();

}

void GUImanager::wyslijDane(bilet* b) {
    k.dodajBilet(b);

}

void GUImanager::wyslijDane(przekaska* p) {
    k.dodajPrzekaske(p);

}

void GUImanager::wyslijDane(klient* kl, ulga* u) {
    k.nowaUlga(kl, u);

}

void GUImanager::wyslijDane(int id) {
    k.zwrocBilet(id);

}

void GUImanager::akceptuj() {
    k.finalizujTrasakcje();

}

void GUImanager::anuluj() {
    k.anulujTransakcje();

}