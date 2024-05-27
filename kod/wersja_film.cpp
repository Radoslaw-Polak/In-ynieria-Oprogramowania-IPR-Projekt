#include "wersja_film.h"

wersja_film::wersja_film(std::string jez, film *f)
{
    jezyk = jez;
    master = f;
}

wersja_film::~wersja_film()
{
    delete master;
}

film *wersja_film::get_master()
{
    return master;
}
