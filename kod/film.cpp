#include "film.h"
using namespace std;

film::film(std::string id, std::string tyt)
{
    idFilmweb = id;
    // Normally would get this from filmweb db
    tytul = tyt;
    czasTrwaniaMin = 0;
}

film::~film()
{
}

std::string film::get_tytul()
{
    return tytul;
}

int film::get_czas()
{
    return czasTrwaniaMin;
}
