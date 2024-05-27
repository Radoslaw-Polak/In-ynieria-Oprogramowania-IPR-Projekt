#include "kasjer.h"
using namespace std;

kasjer::kasjer() {
    suma = 0.0;
    koszyk_b.clear();
    koszyk_p.clear();
    aktywnaUlga = new ulga("Brak", 0);
    idBiletNext = 0;
    srand(time(NULL));
    list<miejsce_sali*> m;
    miejsce_sali* miej;
    int mod = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = mod; j < 12 - mod; j++) {
            if (i < 1)
                miej = new miejsce_sali(j, i, "A");
            else miej = new miejsce_sali(j, i, "B");
            m.push_back(miej);

        }
        if (i % 3 == 2)
            mod++;

    }
    testSala = new sala(m, "Sala testowa");

}

kasjer::~kasjer() {
    koszyk_b.clear();
    koszyk_p.clear();

}

kasjer& kasjer::getInstance() {
    static kasjer instance;
    return instance;

}

// Pipeline - sprzedaż biletu

void kasjer::dodajBilet(bilet* b) {
    koszyk_b.push_back(b);
    aktualizujKwoteDoZaplaty();

}

void kasjer::usunBilet(int idKoszyk) {
    // No type-checking/overflow protection
    list<bilet*>::iterator it = koszyk_b.begin();
    for(int i = 0; i < idKoszyk; i++)
        it++;
    koszyk_b.erase(it);
    aktualizujKwoteDoZaplaty();

}

// Wyszukiwanie

list<seans*> kasjer::szukajSeans(string tyt, string data, string godz) {
    string q = "SELECT * FROM seanse WHERE Tytul LIKE \"%" + tyt + "%\"";
    list<string> res = {};
    res = sql.executeQuery(q,4);
    list<seans*> temp;
    string t = "";
    string d = "";
    string g = "";
    for (list<string>::iterator it = res.begin(); it != res.end(); ++it) {
        // id
        (*it).erase(0, (*it).find("~") + 1);
        // tytul
        t = (*it).substr(0, (*it).find("~"));
        (*it).erase(0, (*it).find("~") + 1);
        // data
        d = (*it).substr(0, (*it).find("~"));
        (*it).erase(0, (*it).find("~") + 1);
        // godz
        g = (*it).substr(0, (*it).find("~"));
        seans* s = new seans(to_string(rand()%100 + 10000), t, d, g, testSala);
        temp.push_back(s);

    }
    return temp;

}

list<klient*> kasjer::szukajKlient(int id) {
    string q = "SELECT k.idKlient, k.ime, k.nazwisko, k.email, u.rodzajZnizki, u.wartoscZnizki FROM `kino-ipr`.klient_stacjonarny as k JOIN ulga as u ON k.idUlga=u.idUlga WHERE k.idKlient = \"" + std::to_string(id) + "\"";
    list<string> res = {};
    res = sql.executeQuery(q, 6);
    list<klient*> temp;
    // temporary check
    if (res.front().size() < 4) {
        temp.push_back(nullptr);
        return temp;

    }
    string i = "";
    string n = "";
    string e = "";
    string r = "";
    string w = "";
    for (list<string>::iterator it = res.begin(); it != res.end(); ++it) {
        // id
        (*it).erase(0, (*it).find("~") + 1);
        // imie
        i = (*it).substr(0, (*it).find("~"));
        (*it).erase(0, (*it).find("~") + 1);
        // nazwisko
        n = (*it).substr(0, (*it).find("~"));
        (*it).erase(0, (*it).find("~") + 1);
        // email
        e = (*it).substr(0, (*it).find("~"));
        (*it).erase(0, (*it).find("~") + 1);
        // rodzaj
        r = (*it).substr(0, (*it).find("~"));
        (*it).erase(0, (*it).find("~") + 1);
        // wartosc
        w = (*it).substr(0, (*it).find("~"));

        ulga* u = new ulga(r,std::stoi(w));
        klient* k = new klient(id, i, n, e, u);
        temp.push_back(k);

    }
    return temp;

}

list<bilet*> kasjer::szukajBilet(int id) {
    // Just for testing, hardcoded
    list<bilet*> temp;
    if (id > 1) {
        temp.push_back(nullptr);
        return temp;
    }
    std::string dat = "01.02.2024";
    std::string godz = "11.30";
    ulga* u = new ulga("Brak", 0);
    seans* f = new seans("10100101", "Chłopi", dat, godz, testSala);
    temp.push_back(new bilet(0, dat, godz, 26.0, u, f, testSala->get_miejsca().front()));
    dat = "06.02.2024";
    godz = "18.00";
    temp.push_back(new bilet(1, dat, godz, 22.0, u, f, testSala->get_miejsca().back()));
    return temp;

}

list<przekaska*> kasjer::szukajPrzekaska(string nazwa) {
    list<przekaska*> temp;
    temp.push_back(new przekaska("Popcorn mały", 10.0f));
    temp.push_back(new przekaska("Popcorn duży", 15.0f));
    temp.push_back(new przekaska("Popcorn mały karmel", 15.0f));
    temp.push_back(new przekaska("Popcorn duży karmel", 20.0f));
    temp.push_back(new przekaska("Pepsi 0.5l", 12.0f));
    return temp;

}

list<miejsce_sali*> kasjer::szukajMiejsca(seans* s, bool tylkoWolne) {
    list<miejsce_sali*> temp = s->sala_uklad_get();
    if (!tylkoWolne)
        return temp;

    // SELECT * FROM bilet JOIN seans ON (seans_id), and remove these from all; For testing, harcoded
    for (list<miejsce_sali*>::iterator it = temp.begin(); it != temp.end(); ++it)
        if ((*it)->get_rzad() > (*it)->get_kolumna())
            temp.erase(it);
    return temp;

}

list<ulga*> kasjer::szukajUlga(bool aktywna) {
    list<ulga*> temp;
    if (aktywna) {
        temp.push_back(aktywnaUlga);
        return temp;

    }
    string q = "SELECT * FROM `kino-ipr`.ulga";
    list<string> res = {};
    res = sql.executeQuery(q, 3);
    string rodz = "";
    string upust = "";
    for (list<string>::iterator it = res.begin(); it != res.end(); ++it) {
        // id
        (*it).erase(0, (*it).find("~") + 1);
        // rodzaj
        rodz = (*it).substr(0, (*it).find("~"));
        (*it).erase(0, (*it).find("~") + 1);
        // wartosc
        upust = (*it).substr(0, (*it).find("~"));
        (*it).erase(0, (*it).find("~") + 1);

        ulga* u = new ulga(rodz, std::stoi(upust));
        temp.push_back(u);

    }
    return temp;

}

double kasjer::szukajCena(data_seans* data) {
    // Would normally select from data_seans join cena_seans; for testing:
    return 50.0f;

}

int kasjer::noweIdBilet() {
    // Would normally get highest id from bilet; for testing:
    return idBiletNext++;

}

// Pipeline - sprzedaż przekąsek

void kasjer::dodajPrzekaske(przekaska* p) {
    koszyk_p.push_back(p);
    aktualizujKwoteDoZaplaty();

}

void kasjer::usunPrzekaske(int idKoszyk) {
    // No type-checking/overflow protection
    list<przekaska*>::iterator it = koszyk_p.begin();
    for(int i = 0; i < idKoszyk; i++)
        it++;
    koszyk_p.erase(it);
    aktualizujKwoteDoZaplaty();

}

// Finalizacja transkacji

void kasjer::finalizujTrasakcje() {
    przyjmijPlatnosc(suma);
    suma = 0.0;
    koszyk_b.clear();
    koszyk_p.clear();

}

void kasjer::przyjmijPlatnosc(double kwota) {
    // Halt program until card registered / cash accepted etc.
    list<string> res = {};
    //res = sql.executeQuery("",1);
    // If payment successful, add row(s) to bilet
    //res = sql.executeQuery("", 1);

}

void kasjer::aktualizujKwoteDoZaplaty() {
    // Opust tylko na bilety
    for(std::list<bilet*>::iterator it = koszyk_b.begin(); it != koszyk_b.end(); ++it)
        suma += (*it)->cena_get();
    for(std::list<przekaska*>::iterator it = koszyk_p.begin(); it != koszyk_p.end(); ++it)
        suma += (*it)->cena_get();
}

void kasjer::zwrocBilet(int id) {
    // Delete from bilet
    list<string> res = {};
    //res = sql.executeQuery("",0);

}

void kasjer::anulujTransakcje() {
    suma = 0.0;
    koszyk_b.clear();
    koszyk_p.clear();

}

// Ulgi

void kasjer::nowaUlga(klient* k, ulga* u) {
    // Find correct idUlga first:
    string q = "SELECT u.idUlga FROM `kino-ipr`.ulga as u WHERE u.rodzajZnizki = \"" + u->rodzaj_get() + "\" AND u.wartoscZnizki = \"" + std::to_string(u->wartosc_get()) + "\"";
    list<string> res = {};
    res = sql.executeQuery(q, 1);
    string id = res.front();
    id = id.substr(0, id.find("~"));
    // Update row in klient_stacjonarny
    q = "UPDATE klient_stacjonarny SET idUlga = \"" + id + "\" WHERE idKlient = \"" + std::to_string(k->id_get()) + "\"";
    sql.executeQuery(q, 1, true);
    k->ulga_set(u);
    dodajUlga(k);

}

ulga* kasjer::dodajUlga(klient* k) {
    aktywnaUlga = k->ulga_get();
    for (std::list<bilet*>::iterator it = koszyk_b.begin(); it != koszyk_b.end(); ++it)
        (*it)->ulga_set(aktywnaUlga);
    aktualizujKwoteDoZaplaty();
    return aktywnaUlga;

}
