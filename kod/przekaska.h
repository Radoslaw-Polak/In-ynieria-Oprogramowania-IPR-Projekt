#ifndef PRZEKASKA
#define PRZEKASKA
#include <string>

class przekaska {
private:
    std::string nazwa;
    double cena;
public:
    przekaska(std::string n, double c);
    ~przekaska();
    std::string nazwa_get();
    double cena_get();
};

#endif