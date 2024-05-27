#pragma once

#include <qdialog.h>
#include "klient.h"
#include "nowa_ulga.h"

namespace Ui {
	class klient_info;
}

class klient_info : public QDialog
{
	Q_OBJECT

public:
	explicit klient_info(QWidget* parent = nullptr);
	~klient_info();
	void on_bulga_clicked();
	void setFields(klient* k);
private:
	klient* osoba;
	Ui::klient_info* ui8;
};
#pragma once
