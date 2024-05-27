#ifndef WERSJA
#define WERSJA
#include "film.h"

class wersja_film
{
private:
    std::string jezyk;
    film* master;
public:
    wersja_film(std::string jez, film* f);
    ~wersja_film();
    film* get_master();
};

#endif