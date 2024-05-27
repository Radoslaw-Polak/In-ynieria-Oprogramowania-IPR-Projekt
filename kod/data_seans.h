#ifndef DATASEANS
#define DATASEANS
#include <string>

class data_seans
{
private:
    std::string data;
    std::string godzina;
public:
    data_seans(std::string d, std::string godz);
    ~data_seans();
    std::string get_data_tostr();
    std::string get_data();
    std::string get_godzina();
};

#endif