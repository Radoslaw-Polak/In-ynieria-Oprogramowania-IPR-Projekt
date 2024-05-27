#include "sala.h"
using namespace std;

sala::sala(list<miejsce_sali*> uklad, std::string naz)
{
    miejsca = uklad;
    nazwa = naz;
}

sala::~sala()
{
    for(list<miejsce_sali*>::iterator it = miejsca.begin(); it != miejsca.end(); ++it)
        delete (*it);
}

std::list<miejsce_sali *> sala::get_miejsca()
{
    return miejsca;
}

std::string sala::get_nazwa()
{
    return nazwa;
}

int sala::liczba_kolumn() {
    int maxk = 0;
    for (list<miejsce_sali*>::iterator it = miejsca.begin(); it != miejsca.end(); ++it)
        if ((*it)->get_kolumna() > maxk)
            maxk = (*it)->get_kolumna();
    return maxk;

}

int sala::liczba_rzedow() {
    int maxr = 0;
    for (list<miejsce_sali*>::iterator it = miejsca.begin(); it != miejsca.end(); ++it)
        if ((*it)->get_rzad() > maxr)
            maxr = (*it)->get_rzad();
    return maxr;

}