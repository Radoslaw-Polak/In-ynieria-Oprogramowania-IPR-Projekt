#ifndef SALA
#define SALA
#include <list>
#include "miejsce_sali.h"

class sala
{
private:
    std::list<miejsce_sali*> miejsca;
    std::string nazwa;
public:
    sala(std::list<miejsce_sali*> uklad, std::string naz);
    ~sala();
    std::list<miejsce_sali*> get_miejsca();
    std::string get_nazwa();
    int liczba_kolumn();
    int liczba_rzedow();
};

#endif