#include "miejsce_sali.h"

miejsce_sali::miejsce_sali(int x, int y, std::string rodzaj)
{
    kolumna = x;
    rzad = y;
    typ = rodzaj;
}

miejsce_sali::~miejsce_sali()
{
}

int miejsce_sali::get_kolumna()
{
    return kolumna;
}

int miejsce_sali::get_rzad()
{
    return rzad;
}

std::string miejsce_sali::get_typ()
{
    return typ;
}
