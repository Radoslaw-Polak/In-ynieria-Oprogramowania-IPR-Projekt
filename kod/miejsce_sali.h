#ifndef MIEJSCE
#define MIEJSCE
#include <string>

class miejsce_sali
{
private:
    int kolumna;
    int rzad;
    std::string typ;
public:
    miejsce_sali(int x, int y, std::string rodzaj);
    ~miejsce_sali();
    int get_kolumna();
    int get_rzad();
    std::string get_typ();
};

#endif