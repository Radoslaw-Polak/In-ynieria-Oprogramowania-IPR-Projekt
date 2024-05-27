#ifndef CENASEANS
#define CENASEANS
#include "data_seans.h"

class cena_seans
{
private:
    double cena;
    data_seans* data;
public:
    cena_seans(double c, data_seans* d);
    ~cena_seans();
    double get_cena();
    data_seans* get_data();
};

#endif