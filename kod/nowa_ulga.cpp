#include "nowa_ulga.h"
#include "ui_nowa_ulga.h"
#include "GUImanager.h"

nowa_ulga::nowa_ulga(QWidget* parent, klient* k)
	: QDialog(parent), ui9(new Ui::nowa_ulga)
{
	ui9->setupUi(this);
	connect(ui9->bOk, &QPushButton::clicked, this, &nowa_ulga::on_bok_clicked);
	ulgi = GUImanager::getInstance().pobierzDane(false);
	for (std::list<ulga*>::iterator it = ulgi.begin(); it != ulgi.end(); ++it) {
		ui9->cUlgi->addItem(QString::fromStdString((*it)->rodzaj_get() + "  " + std::to_string((*it)->wartosc_get())));

	}
	osoba = k;

}

nowa_ulga::~nowa_ulga() {
	delete ui9;

}

void nowa_ulga::on_bok_clicked() {
	auto sel = ulgi.begin();
	std::advance(sel, ui9->cUlgi->currentIndex());
	GUImanager::getInstance().wyslijDane(osoba, *sel);
	this->accept();

}