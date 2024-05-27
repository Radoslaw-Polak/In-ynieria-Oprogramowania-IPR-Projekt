#ifndef GUI
#define GUI
#include "singleton.h"
#include "kasjer.h"
#include "mainWindow.h"
#include <list>

class GUImanager : singleton {
private:
    GUImanager();
    kasjer k = kasjer::getInstance();
    mainWindow* win;
public:
    ~GUImanager();
    static GUImanager& getInstance();
    std::list<seans*> pobierzDane(std::string tyt, std::string data, std::string godz);
    std::list<miejsce_sali*> pobierzDane(seans* s, bool wolne);
    std::list<przekaska*> pobierzDane(std::string nazw);
    std::list<ulga*> pobierzDane(bool aktywna);
    klient* pobierzDane(int id);
    bilet* pobierzDane(int id, bool temp);
    double pobierzDane(data_seans* data);
    int pobierzDane();
    void wyslijDane(bilet* b);
    void wyslijDane(przekaska* p);
    void wyslijDane(klient* kl, ulga* u);
    void wyslijDane(int id);
    void akceptuj();
    void anuluj();

};

#endif