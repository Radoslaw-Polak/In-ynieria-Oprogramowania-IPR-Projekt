#include "cena_seans.h"
using namespace std;

cena_seans::cena_seans(double c, data_seans* d)
{
    data = d;
    cena = c;
}

cena_seans::~cena_seans()
{
    delete data;
}

double cena_seans::get_cena()
{
    return cena;
}

data_seans *cena_seans::get_data()
{
    return data;
}
