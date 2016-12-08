
#include <QtCore/QCoreApplication>
#include "Controller.h"
#include <dbus/CvCoreIf.h>
#include "config/Main_config.h"
#include <QString>
#include <string>
#include <iostream>


using namespace std;
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Controller stController;
	stController.startRecgonize();
	return a.exec();
}
