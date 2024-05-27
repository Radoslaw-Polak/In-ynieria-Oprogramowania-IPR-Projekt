#ifndef KASJER
#define KASJER
#include "bilet.h"
#include "platnosc.h"
#include "przekaska.h"
#include "klient.h"
#include "seans.h"
#include "SQLmanager.h"
#include <list>

class kasjer : public singleton{
private:
    std::list<przekaska*> koszyk_p;
    std::list<bilet*> koszyk_b;
    SQLmanager sql = SQLmanager::getInstance();
    ulga* aktywnaUlga;
    double suma;
    int idBiletNext;
    kasjer();
    // Just for testing, hardcoded
    sala* testSala;
public:
    static kasjer& getInstance();
    ~kasjer();

    // Pipeline - sprzedaż biletu
    void dodajBilet(bilet* b);
    void usunBilet(int idKoszyk);

    // Wyszukiwanie
    ///@brief Calls guimanager::executequery and parses output to list
    std::list<seans*> szukajSeans(std::string tyt, std::string data, std::string godz);
    std::list<klient*> szukajKlient(int id);
    std::list<bilet*> szukajBilet(int id);
    std::list<przekaska*> szukajPrzekaska(std::string nazwa);
    std::list<miejsce_sali*> szukajMiejsca(seans* s, bool wolne);
    std::list<ulga*> szukajUlga(bool aktywna);
    double szukajCena(data_seans* data);
    int noweIdBilet();

    // Pipeline - sprzedaż przekąsek
    void dodajPrzekaske(przekaska* p);
    void usunPrzekaske(int idKoszyk);

    // Finalizacja transkacji
    void finalizujTrasakcje();
    void przyjmijPlatnosc(double kwota);
    void aktualizujKwoteDoZaplaty();
    void zwrocBilet(int id);
    void anulujTransakcje();

    // Ulgi
    void nowaUlga(klient* k, ulga* u);
    ulga* dodajUlga(klient* k);
};

#endif