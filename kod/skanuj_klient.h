#pragma once

#include <qdialog.h>
#include "klient_info.h"

namespace Ui {
	class skanuj_klient;
}

class skanuj_klient : public QDialog
{
	Q_OBJECT

public:
	explicit skanuj_klient(QWidget* parent = nullptr);
	~skanuj_klient();
	void on_bszukaj_clicked();
private:
	Ui::skanuj_klient* ui7;
};
#pragma once
