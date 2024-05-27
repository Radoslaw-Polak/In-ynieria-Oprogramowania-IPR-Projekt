#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainWindow.h"
#include "szukaj_seans.h"
#include "nowa_przekaska.h"
#include "skanuj_bilet.h"
#include "skanuj_klient.h"

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();
    void on_bbilet_clicked();
    void on_bprzekaska_clicked();
    void on_bulga_clicked();
    void on_bzwrot_clicked();

private:
    Ui::mainWindowClass ui;
};
