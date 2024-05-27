#include "skanuj_klient.h"
#include "ui_skanuj_klient.h"
#include "GUImanager.h"
#include <qmessagebox.h>

skanuj_klient::skanuj_klient(QWidget* parent)
	: QDialog(parent), ui7(new Ui::skanuj_klient)
{
	ui7->setupUi(this);
	connect(ui7->bSzukaj, &QPushButton::clicked, this, &skanuj_klient::on_bszukaj_clicked);

}

skanuj_klient::~skanuj_klient() {
	delete ui7;

}

void skanuj_klient::on_bszukaj_clicked() {
	klient* res = GUImanager::getInstance().pobierzDane(ui7->txtId->toPlainText().toInt());
	if (res != nullptr) {
		klient_info* win_c2 = new klient_info();
		win_c2->setModal(false);
		win_c2->setAttribute(Qt::WA_DeleteOnClose);
		win_c2->setAttribute(Qt::WA_QuitOnClose, false);
		win_c2->setFields(res);
		win_c2->exec();
		this->accept();
	}
	else {
		QMessageBox* err = new QMessageBox(this);
		err->setIcon(QMessageBox::Warning);
		err->setText("Nie znaleziono klienta.");
		err->setStandardButtons(QMessageBox::Cancel);
		err->exec();

	}

}