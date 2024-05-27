#pragma once

#include <qdialog.h>
#include "skanuj_bilet.h"
#include "bilet_info.h"

namespace Ui {
	class skanuj_bilet;
}

class skanuj_bilet : public QDialog
{
	Q_OBJECT

public:
	explicit skanuj_bilet(QWidget* parent = nullptr);
	~skanuj_bilet();
	void on_bszukaj_clicked();
private:
	Ui::skanuj_bilet* ui6;
};
#pragma once
