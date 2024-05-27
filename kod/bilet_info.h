#pragma once

#include <qdialog.h>
#include "bilet.h"

namespace Ui {
	class bilet_info;
}

class bilet_info : public QDialog
{
	Q_OBJECT

public:
	explicit bilet_info(QWidget* parent = nullptr);
	~bilet_info();
	void on_bzwrot_clicked();
	void setFields(bilet* b);
private:
	bilet* doZwrotu;
	Ui::bilet_info* ui9;
};
#pragma once
