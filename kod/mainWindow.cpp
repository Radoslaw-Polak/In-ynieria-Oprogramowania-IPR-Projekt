#include "mainWindow.h"
#include "GUImanager.h"

mainWindow::mainWindow(QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this);
    // idk why automatic connect doesnt work
    connect(ui.bbilet, &QPushButton::clicked, this, &mainWindow::on_bbilet_clicked);
    connect(ui.bprzekaska, &QPushButton::clicked, this, &mainWindow::on_bprzekaska_clicked);
    connect(ui.bulga, &QPushButton::clicked, this, &mainWindow::on_bulga_clicked);
    connect(ui.bzwrot, &QPushButton::clicked, this, &mainWindow::on_bzwrot_clicked);

}

mainWindow::~mainWindow() {

}

void mainWindow::on_bbilet_clicked() {
    szukaj_seans* win_a1 = new szukaj_seans();
    win_a1->setModal(false);
    win_a1->setAttribute(Qt::WA_DeleteOnClose);
    win_a1->setAttribute(Qt::WA_QuitOnClose, false);
    win_a1->exec();

}

void mainWindow::on_bprzekaska_clicked() {
    nowa_przekaska* win_b1 = new nowa_przekaska();
    win_b1->setModal(false);
    win_b1->setAttribute(Qt::WA_DeleteOnClose);
    win_b1->setAttribute(Qt::WA_QuitOnClose, false);
    win_b1->exec();

}

void mainWindow::on_bulga_clicked() {
    skanuj_klient* win_c1 = new skanuj_klient();
    win_c1->setModal(false);
    win_c1->setAttribute(Qt::WA_DeleteOnClose);
    win_c1->setAttribute(Qt::WA_QuitOnClose, false);
    win_c1->exec();

}

void mainWindow::on_bzwrot_clicked() {
    skanuj_bilet* win_d1 = new skanuj_bilet();
    win_d1->setModal(false);
    win_d1->setAttribute(Qt::WA_DeleteOnClose);
    win_d1->setAttribute(Qt::WA_QuitOnClose, false);
    win_d1->exec();

}