#include "skanuj_bilet.h"
#include "ui_skanuj_bilet.h"
#include "GUImanager.h"
#include <qmessagebox.h>

skanuj_bilet::skanuj_bilet(QWidget* parent)
	: QDialog(parent), ui6(new Ui::skanuj_bilet)
{
	ui6->setupUi(this);
	connect(ui6->bSzukaj, &QPushButton::clicked, this, &skanuj_bilet::on_bszukaj_clicked);

}

skanuj_bilet::~skanuj_bilet() {
	delete ui6;

}

void skanuj_bilet::on_bszukaj_clicked() {
	bilet* res = GUImanager::getInstance().pobierzDane(ui6->txtId->toPlainText().toInt(), true);
	if (res != nullptr) {
		bilet_info* win_d2 = new bilet_info();
		win_d2->setModal(false);
		win_d2->setAttribute(Qt::WA_DeleteOnClose);
		win_d2->setAttribute(Qt::WA_QuitOnClose, false);
		win_d2->setFields(res);
		win_d2->exec();
		this->accept();

	}
	else {
		QMessageBox* err = new QMessageBox(this);
		err->setIcon(QMessageBox::Warning);
		err->setText("Nie znaleziono biletu.");
		err->setStandardButtons(QMessageBox::Cancel);
		err->exec();

	}

}