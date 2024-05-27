#include "szukaj_seans.h"
#include "ui_szukaj_seans.h"
#include "GUImanager.h"

szukaj_seans::szukaj_seans(QWidget *parent)
	: QDialog(parent), ui2(new Ui::szukaj_seans)
{
	ui2->setupUi(this);
	connect(ui2->bSzukaj, &QPushButton::clicked, this, &szukaj_seans::on_bszukaj_clicked);
	connect(ui2->lSeanse, &QListWidget::itemClicked, this, &szukaj_seans::on_list_clicked);

}

szukaj_seans::~szukaj_seans() {
	delete ui2;

}

void szukaj_seans::on_bszukaj_clicked() {
	lista_seans = GUImanager::getInstance().pobierzDane(ui2->txtTytul->toPlainText().toStdString(), ui2->txtData->toPlainText().toStdString(), ui2->txtGodzina->toPlainText().toStdString());
	int i = 0;
	ui2->lSeanse->clear();
	for (std::list<seans*>::iterator it = lista_seans.begin(); it != lista_seans.end(); ++it) {
		std::string temp = (*it)->tytul_get();
		temp += "\t";
		temp += (*it)->data_get()->get_data_tostr();
		ui2->lSeanse->insertItem(i, QString::fromStdString(temp));
		i++;

	}

}

void szukaj_seans::on_list_clicked() {
	seans_info* win_a2 = new seans_info();
	win_a2->setModal(false);
	win_a2->setAttribute(Qt::WA_DeleteOnClose);
	win_a2->setAttribute(Qt::WA_QuitOnClose, false);
	win_a2->setFields(getElem(ui2->lSeanse->currentRow()));
	win_a2->exec();
	this->accept();

}

seans* szukaj_seans::getElem(int i) {
	auto l = lista_seans.begin();
	std::advance(l, i);
	return (*l);

}