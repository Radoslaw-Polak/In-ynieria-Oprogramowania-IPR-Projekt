#include "bilet_info.h"
#include "ui_bilet_info.h"
#include "GUImanager.h"

bilet_info::bilet_info(QWidget* parent)
	: QDialog(parent), ui9(new Ui::bilet_info)
{
	ui9->setupUi(this);
	connect(ui9->bZwrot, &QPushButton::clicked, this, &bilet_info::on_bzwrot_clicked);

}

bilet_info::~bilet_info() {
	delete ui9;

}

void bilet_info::on_bzwrot_clicked() {
	GUImanager::getInstance().wyslijDane(doZwrotu->id_get());
	this->accept();

}

void bilet_info::setFields(bilet* b) {
	doZwrotu = b;
	ui9->txtTytul->setPlainText(QString::fromStdString(b->seans_get()->tytul_get()));
	ui9->txtData->setPlainText(QString::fromStdString(b->data_get()->get_data()));
	ui9->txtGodzina->setPlainText(QString::fromStdString(b->data_get()->get_godzina()));
	ui9->txtCena->setPlainText(QString::fromStdString(std::to_string(b->cena_get())));

}