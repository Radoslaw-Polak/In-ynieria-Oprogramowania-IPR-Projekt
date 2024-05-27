#ifndef ULGA
#define ULGA
#include <string>

class ulga {
private:
    std::string rodzajZnizki;
    int wartosc;
public:
    ulga(std::string typ, int opust);
    ~ulga();
    int wartosc_get();
    std::string rodzaj_get();
};

#endif