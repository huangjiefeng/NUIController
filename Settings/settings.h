#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtWidgets/QMainWindow>
#include "ui_settings.h"

class Settings : public QMainWindow
{
	Q_OBJECT

public:
	Settings(QWidget *parent = 0);
	~Settings();

private:
	Ui::SettingsClass ui;

private slots:
	void handleConfirm();
};

#endif // SETTINGS_H
