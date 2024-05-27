#ifndef FILM
#define FILM
#include <string>

class film
{
private:
    std::string idFilmweb;
    std::string tytul;
    int czasTrwaniaMin; 
public:
    film(std::string id, std::string tyt);
    ~film();
    std::string get_tytul();
    int get_czas();
};

#endif