#include "nowa_przekaska.h"
#include "ui_nowa_przekaska.h"
#include "GUImanager.h"

nowa_przekaska::nowa_przekaska(QWidget* parent)
	: QDialog(parent), ui5(new Ui::nowa_przekaska)
{
	ui5->setupUi(this);
	connect(ui5->bSzukaj, &QPushButton::clicked, this, &nowa_przekaska::on_bszukaj_clicked);
	connect(ui5->bPlatnosc, &QPushButton::clicked, this, &nowa_przekaska::on_bplatnosc_clicked);
	connect(ui5->bDodaj, &QPushButton::clicked, this, &nowa_przekaska::on_bdodaj_clicked);
	indexer = 0;

}

nowa_przekaska::~nowa_przekaska() {
	delete ui5;

}

void nowa_przekaska::on_bszukaj_clicked() {
	przekaski = GUImanager::getInstance().pobierzDane(ui5->txtNazwa->toPlainText().toStdString());
	int i = 0;
	ui5->lPrzekaski->clear();
	for (std::list<przekaska*>::iterator it = przekaski.begin(); it != przekaski.end(); ++it) {
		std::string temp = (*it)->nazwa_get();
		temp += "\t";
		temp += std::to_string((*it)->cena_get());
		ui5->lPrzekaski->insertItem(i, QString::fromStdString(temp));
		i++;

	}

}

void nowa_przekaska::on_bdodaj_clicked() {
	if (ui5->lPrzekaski->currentRow() >= 0) {
		przekaska* wybor = getElem(ui5->lPrzekaski->currentRow());
		koszyk.push_back(wybor);
		// Copying elems between lists doesnt work? Create new ones
		std::string temp = wybor->nazwa_get();
		temp += "\t";
		temp += std::to_string(wybor->cena_get());
		ui5->lKoszyk->insertItem(indexer, QString::fromStdString(temp));
		indexer++;
		updateSuma();

	}

}

void nowa_przekaska::on_bplatnosc_clicked() {
	for (std::list<przekaska*>::iterator it = koszyk.begin(); it != koszyk.end(); ++it)
		GUImanager::getInstance().wyslijDane(*it);
	GUImanager::getInstance().akceptuj();
	this->accept();

}

przekaska* nowa_przekaska::getElem(int i) {
	auto l = przekaski.begin();
	std::advance(l, i);
	return (*l);

}

void nowa_przekaska::reject() {
	GUImanager::getInstance().anuluj();
	this->accept();

}

void nowa_przekaska::updateSuma() {
	double suma = 0.0f;
	for (std::list<przekaska*>::iterator it = koszyk.begin(); it != koszyk.end(); ++it)
		suma += (*it)->cena_get();
	ui5->lSuma->setText(QString::fromStdString("SUMA: " + std::to_string(suma)));

}