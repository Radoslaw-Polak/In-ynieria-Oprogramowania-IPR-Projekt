#include "data_seans.h"
using namespace std;

data_seans::data_seans(string d, string godz)
{
    data = d;
    godzina = godz;
}

data_seans::~data_seans()
{
}

string data_seans::get_data_tostr()
{
    string temp = "";
    temp += data;
    temp += "\t";
    temp += godzina;
    return temp;
}

string data_seans::get_data()
{
    return data;
}

string data_seans::get_godzina()
{
    return godzina;
}
