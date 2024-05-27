#include "klient_info.h"
#include "ui_klient_info.h"
#include "GUImanager.h"

klient_info::klient_info(QWidget* parent)
	: QDialog(parent), ui8(new Ui::klient_info)
{
	ui8->setupUi(this);
	connect(ui8->bUlga, &QPushButton::clicked, this, &klient_info::on_bulga_clicked);

}

klient_info::~klient_info() {
	delete ui8;

}

void klient_info::on_bulga_clicked() {
	nowa_ulga* win_c3 = new nowa_ulga(this, osoba);
	win_c3->setModal(false);
	win_c3->setAttribute(Qt::WA_DeleteOnClose);
	win_c3->setAttribute(Qt::WA_QuitOnClose, false);
	win_c3->exec();
	setFields(GUImanager::getInstance().pobierzDane(osoba->id_get()));

}

void klient_info::setFields(klient* k) {
	osoba = k;
	ui8->txtImie->setPlainText(QString::fromStdString(k->imie_get()));
	ui8->txtNazwisko->setPlainText(QString::fromStdString(k->nazwisko_get()));
	ui8->txtEmail->setPlainText(QString::fromStdString(k->email_get()));
	ui8->txtUlga->setPlainText(QString::fromStdString(k->ulga_get()->rodzaj_get()));

}