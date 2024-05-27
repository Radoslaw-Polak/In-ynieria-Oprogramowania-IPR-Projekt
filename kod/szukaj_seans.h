#pragma once

#include <qdialog.h>
#include "seans_info.h"
#include "seans.h"

namespace Ui {
	class szukaj_seans;
}

class szukaj_seans : public QDialog
{
	Q_OBJECT

public:
	explicit szukaj_seans(QWidget *parent = nullptr);
	~szukaj_seans();
	void on_bszukaj_clicked();
	void on_list_clicked();
	seans* getElem(int i);
private:
	std::list<seans*> lista_seans;
	Ui::szukaj_seans* ui2;
};
