#pragma once
#include <QString>
#include "libini.h"
class Controller
{
public:
	Controller(void);
	~Controller(void);
	bool startRecgonize();
private:
	void sendToDBus(enum CoreAction action,int argument);
	QString ThreeThreeLayouGesture;
	INI *pini;
};

