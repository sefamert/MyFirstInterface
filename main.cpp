#include "mainwindow.h"
#include "nameandsite.h"
#include "basetest.h"

#include <QApplication>
#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QVariant>

#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow mainwindow;
	mainwindow.show();
	while (mainwindow.isVisible())
		QApplication::processEvents();

	return a.exec();
}
