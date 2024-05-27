#pragma once

#include <qdialog.h>
#include "miejsce_sali.h"
#include "ulga.h"
#include "seans.h"
#include "bilet.h"

namespace Ui {
	class nowy_bilet;
}

class nowy_bilet : public QDialog
{
	Q_OBJECT

public:
	explicit nowy_bilet(QWidget* parent = nullptr);
	~nowy_bilet();
	void on_bplatnosc_clicked();
	void on_bbilet_clicked();
	void setFields(std::list<miejsce_sali*> wol, std::list<miejsce_sali*> zaj, seans* s);
private:
	QPushButton* Field[30][30];
	std::list<miejsce_sali*> wolne;
	std::list<miejsce_sali*> wszystkie;
	miejsce_sali* wybor;
	std::list<bilet*> koszyk;
	seans* film;
	ulga* aktywnaUlga;
	Ui::nowy_bilet* ui4;
	int indexer;
	miejsce_sali* matchxy(int x, int y, bool tylkoWolne);
	void updateUi();
	int x_getmax();
	int y_getmax();
	void reject();
	void updateSuma();

};
#pragma once
