#include "seans_info.h"
#include "ui_seans_info.h"
#include "GUImanager.h"
#include "nowy_bilet.h"

seans_info::seans_info(QWidget* parent)
	: QDialog(parent), ui3(new Ui::seans_info)
{
	ui3->setupUi(this);
	connect(ui3->bBilet, &QPushButton::clicked, this, &seans_info::on_bbilet_clicked);

}

seans_info::~seans_info() {
	delete ui3;

}

void seans_info::on_bbilet_clicked() {
	nowy_bilet* win_a3 = new nowy_bilet();
	win_a3->setModal(false);
	win_a3->setAttribute(Qt::WA_DeleteOnClose);
	win_a3->setAttribute(Qt::WA_QuitOnClose, false);
	win_a3->setFields(miejsca_wolne, GUImanager::getInstance().pobierzDane(wybor, false), wybor);
	win_a3->exec();
	this->accept();

}

void seans_info::setFields(seans* s) {
	wybor = s;
	ui3->txtTytul->setPlainText(QString::fromStdString(s->tytul_get()));
	ui3->txtData->setPlainText(QString::fromStdString(s->data_get()->get_data()));
	ui3->txtGodzina->setPlainText(QString::fromStdString(s->data_get()->get_godzina()));
	miejsca_wolne = GUImanager::getInstance().pobierzDane(s, true);
	ui3->txtMiejsca->setPlainText(QString::fromStdString(std::to_string(miejsca_wolne.size())));

}