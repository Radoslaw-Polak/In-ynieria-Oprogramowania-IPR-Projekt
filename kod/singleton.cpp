#include "singleton.h"
using namespace std;

singleton::singleton() {


}

singleton& singleton::getInstance() {
    static singleton s;
    return s;

}