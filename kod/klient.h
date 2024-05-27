#ifndef KLIENT
#define KLIENT
#include "ulga.h"
#include <string>

class klient {
private:
    int id_klient;
    std::string imie;
    std::string nazwisko;
    std::string email;
    ulga* rodzajUlgi;
    int punktyLojalnosciowe;
public:
    klient(int id, std::string i, std::string n, std::string em, ulga* u);
    ~klient();
    ulga* ulga_get();
    void ulga_set(ulga* u);
    int id_get();
    std::string imie_get();
    std::string nazwisko_get();
    std::string email_get();
};

#endif