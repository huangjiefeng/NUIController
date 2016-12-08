#include "settings.h"
#include "libini.h"
#include <QtWidgets/QMessageBox>

Settings::Settings(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.btn_OK, SIGNAL(clicked()), this, SLOT(handleConfirm())); 

}

Settings::~Settings()
{

}

void Settings::handleConfirm()
{
	INI *pini;
	pini = ini_open("..\\NUIController\\config.ini");
	if (!pini) {
		QMessageBox::warning(NULL, "Config.ini", "Load config.ini failed!");
		//printf("load config faild.\n");
		return ;
	}
	ini_set(pini,"HandsClosed",ui.cbb_HandsClosed->currentText().toStdString().c_str());
	ini_set(pini,"SingleHand_Left",ui.cbb_LeftHandLeft->currentText().toStdString().c_str());
	ini_set(pini,"SingleHand_Right",ui.cbb_RightHandRight->currentText().toStdString().c_str());
	ini_set(pini,"HandsUp_Left",ui.cbb_LeftHandUp->currentText().toStdString().c_str());
	ini_set(pini,"HandsUp_Right",ui.cbb_RightHandUp->currentText().toStdString().c_str());
	if(ini_save(pini))
	{
		QMessageBox::warning(NULL, "Config.ini", "Save config.ini succeed!");
	};
	ini_close(pini);
}

