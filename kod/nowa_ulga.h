#pragma once

#include <qdialog.h>
#include "ulga.h"
#include "klient.h"

namespace Ui {
	class nowa_ulga;
}

class nowa_ulga : public QDialog
{
	Q_OBJECT

public:
	explicit nowa_ulga(QWidget* parent = nullptr, klient* k = nullptr);
	~nowa_ulga();
	void on_bok_clicked();
private:
	klient* osoba;
	std::list<ulga*> ulgi;
	Ui::nowa_ulga* ui9;
};
#pragma once
