#ifndef PLATNOSC
#define PLATNOSC
#include <string>

class platnosc {
private:
    double kwota;
    std::string data;
    int id_transakcja;
public:
    platnosc();
    ~platnosc();
};

#endif