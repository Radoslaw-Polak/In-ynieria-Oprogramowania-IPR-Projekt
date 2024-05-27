#ifndef SEANS
#define SEANS
#include <string>
#include "data_seans.h"
#include "wersja_film.h"
#include "sala.h"

class seans {
private:
    wersja_film* master;
    data_seans* dzien;
    sala* salaKinowa;
public:
    seans(std::string id_filmweb, std::string tytul, std::string data, std::string godzina, sala* s);
    ~seans();
    std::string tytul_get();
    data_seans* data_get();
    std::list<miejsce_sali*> sala_uklad_get();
    int liczba_rzedow();
    int liczba_kolumn();
};

#endif