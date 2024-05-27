#pragma once

#include <qdialog.h>
#include "przekaska.h"

namespace Ui {
	class nowa_przekaska;
}

class nowa_przekaska : public QDialog
{
	Q_OBJECT

public:
	explicit nowa_przekaska(QWidget* parent = nullptr);
	~nowa_przekaska();
	void on_bszukaj_clicked();
	void on_bplatnosc_clicked();
	void on_bdodaj_clicked();
	przekaska* getElem(int i);
private:
	std::list<przekaska*> koszyk;
	std::list<przekaska*> przekaski;
	Ui::nowa_przekaska* ui5;
	int indexer;
	void reject();
	void updateSuma();
};
