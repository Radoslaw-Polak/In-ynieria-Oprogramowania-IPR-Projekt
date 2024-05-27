#include "nowy_bilet.h"
#include "ui_nowy_bilet.h"
#include "GUImanager.h"

nowy_bilet::nowy_bilet(QWidget* parent)
	: QDialog(parent), ui4(new Ui::nowy_bilet)
{
	ui4->setupUi(this);
	connect(ui4->bPlatnosc, &QPushButton::clicked, this, &nowy_bilet::on_bplatnosc_clicked);
	connect(ui4->bBilet, &QPushButton::clicked, this, &nowy_bilet::on_bbilet_clicked);
	indexer = 0;

}

nowy_bilet::~nowy_bilet() {
	delete ui4;

}

void nowy_bilet::on_bplatnosc_clicked() {
	for(std::list<bilet*>::iterator it = koszyk.begin(); it != koszyk.end(); ++it)
		GUImanager::getInstance().wyslijDane(*it);
	this->accept();

}

void nowy_bilet::on_bbilet_clicked() {
	if (wybor == nullptr)
		return;
	// What a mess
	bilet* nowy = new bilet(GUImanager::getInstance().pobierzDane(), film->data_get()->get_data(), film->data_get()->get_godzina(), GUImanager::getInstance().pobierzDane(film->data_get()), aktywnaUlga, film, wybor);
	std::string entry = wybor->get_typ() + "\t" + std::to_string(wybor->get_rzad()) + "/" + std::to_string(wybor->get_kolumna()) + "\t" + aktywnaUlga->rodzaj_get() + "\t" + std::to_string(nowy->cena_get());
	ui4->lBilet->insertItem(indexer, QString::fromStdString(entry));
	koszyk.push_back(nowy);
	indexer++;
	Field[wybor->get_kolumna()][wybor->get_rzad()]->setDisabled(true);
	// Reset ui + data
	wybor = nullptr;
	ui4->txtKolumna->clear();
	ui4->txtRzad->clear();
	ui4->txtTyp->clear();
	updateSuma();

}

void nowy_bilet::setFields(std::list<miejsce_sali*> wol, std::list<miejsce_sali*> zaj, seans* s) {
	wolne = wol;
	wszystkie = zaj;
	film = s;
	wybor = nullptr;
	aktywnaUlga = GUImanager::getInstance().pobierzDane(true).front();

	// Layout generated dynamically, but only up to 30x30
	for (int i = 0; i < x_getmax()+1; i++)
		for (int j = 0; j < y_getmax()+1; j++) {
			// Draw all seats first
			miejsce_sali* seat = matchxy(i, j, false);
			if (seat != nullptr) {
				std::string name = std::to_string(i + 1) + "/" + std::to_string(j + 1);
				Field[i][j] = new QPushButton(QString::fromStdString(name), this);
				Field[i][j]->setFixedHeight(30);
				Field[i][j]->setFixedWidth(30);
				Field[i][j]->move(380 + i * 34, 30 + j * 34);
				Field[i][j]->setEnabled(false);
				// A bit of colour to distinguish, has to be handled manually
				if (seat->get_typ() == "A")
					Field[i][j]->setStyleSheet("QPushButton { background-color: grey; }\n" "QPushButton:enabled { background-color: rgb(120,0,0); }\n");

			}
			// Then enable only open ones
			seat = matchxy(i, j, true);
			if (seat != nullptr) {
				Field[i][j]->setEnabled(true);
				connect(Field[i][j], &QPushButton::clicked, [this, i, j]()
					{ wybor = matchxy(i, j, false); if (wybor != nullptr) updateUi(); });

			}

		}



}

miejsce_sali* nowy_bilet::matchxy(int x, int y, bool tylkoWolne) {
	if (tylkoWolne) {
		for (std::list<miejsce_sali*>::iterator it = wolne.begin(); it != wolne.end(); ++it) {
			if ((*it)->get_kolumna() == x && (*it)->get_rzad() == y)
				return (*it);

		}
		return nullptr;
	}
	for (std::list<miejsce_sali*>::iterator it = wszystkie.begin(); it != wszystkie.end(); ++it) {
		if ((*it)->get_kolumna() == x && (*it)->get_rzad() == y)
			return (*it);

	}
	return nullptr;

}

void nowy_bilet::updateUi() {
	ui4->txtKolumna->setPlainText(QString::fromStdString(std::to_string(wybor->get_kolumna())));
	ui4->txtRzad->setPlainText(QString::fromStdString(std::to_string(wybor->get_rzad())));
	ui4->txtTyp->setPlainText(QString::fromStdString(wybor->get_typ()));

}

int nowy_bilet::x_getmax() {
	int max = 0;
	for (std::list<miejsce_sali*>::iterator it = wszystkie.begin(); it != wszystkie.end(); ++it)
		if ((*it)->get_kolumna() > max)
			max = (*it)->get_kolumna();
	return max;

}

int nowy_bilet::y_getmax() {
	int max = 0;
	for (std::list<miejsce_sali*>::iterator it = wszystkie.begin(); it != wszystkie.end(); ++it)
		if ((*it)->get_rzad() > max)
			max = (*it)->get_rzad();
	return max;

}

void nowy_bilet::reject() {
	GUImanager::getInstance().anuluj();
	this->accept();

}

void nowy_bilet::updateSuma() {
	// Not the most efficient but ok
	double suma = 0.0f;
	for (std::list<bilet*>::iterator it = koszyk.begin(); it != koszyk.end(); ++it)
		suma += (*it)->cena_get();
	ui4->lSuma->setText(QString::fromStdString("SUMA: " + std::to_string(suma)));

}