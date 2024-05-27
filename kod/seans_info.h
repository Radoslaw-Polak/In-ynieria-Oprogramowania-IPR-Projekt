#pragma once

#include <qdialog.h>
#include "nowy_bilet.h"
#include "seans.h"

namespace Ui {
	class seans_info;
}

class seans_info : public QDialog
{
	Q_OBJECT

public:
	explicit seans_info(QWidget* parent = nullptr);
	~seans_info();
	void on_bbilet_clicked();
	void setFields(seans* s);
private:
	std::list<miejsce_sali*> miejsca_wolne;
	seans* wybor;
	Ui::seans_info* ui3;
};
#pragma once
