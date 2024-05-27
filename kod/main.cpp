#include <stdlib.h>
#include <iostream>
#include <QtWidgets/QApplication>
#include "GUImanager.h"
using namespace std;


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    //app.setQuitOnLastWindowClosed(false);
    GUImanager gui = GUImanager::getInstance();
    return app.exec();
}
