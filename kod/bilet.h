#ifndef BILET
#define BILET
#include "ulga.h"
#include "seans.h"
#include "cena_seans.h"

class bilet {
private:
    int id_bilet;
    cena_seans* cena;
    ulga* uzytaUlga;
    seans* s;
    miejsce_sali* miejsce;
public:
    bilet(int id, std::string data, std::string godzina, double cen, ulga* u, seans* film, miejsce_sali* m);
    ~bilet();
    double cena_get();
    data_seans* data_get();
    ulga* ulga_get();
    seans* seans_get();
    int id_get();
    void ulga_set(ulga* u);
};

#endif