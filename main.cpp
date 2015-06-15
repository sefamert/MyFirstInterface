#include "mainwindow.h"
#include "nameandsite.h"
#include "sefa.h"
#include "basetest.h"

#include <QApplication>
#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QVariant>

#include <iostream>

using namespace std;




void afterChooseTest(Sefa t,QDataStream &stream)
{
	int num;
	t.starttime(QDateTime :: currentDateTime());
	qDebug()<<QDateTime :: currentDateTime();
	num=t.getState();
	qDebug() << "test with state" << t.getState();

	stream << QString("test with state")<< num;								//Stream

	t.start();

	num=t.getState();
	qDebug() << "test with state" << t.getState();

	stream << QString("test with state")<< num;								//Stream

	/* wait test to start */
	while (t.getState() == BaseTest::STATE_STARTING)
	{
		t.afterstart();
	}

	qDebug("test is started");
	/* now the test is running, wait it for to be completed */

	num=t.getState();
	qDebug() << "test with state" << t.getState();

		stream << QString("test with state")<< num;							//Stream

	while (t.getState() == BaseTest::STATE_RUNNING)
		t.run();
	num=t.getState();

	stream << QString("test with state")<< num;								//Stream

	t.stop();

	num=t.getState();
	qDebug() << "test finished with state" << t.getState();

		stream << QString("test finished with state")<< num;				//Stream

	/* save test results to the disk */

	t.finishtime(QDateTime :: currentDateTime());
	qDebug()<<QDateTime :: currentDateTime();

}

void afterWritingFile(void)
{
	qDebug("\n\nAfter Writing File:\n\n");
	QFile file2("setting.dat");
	file2.open(QIODevice::ReadOnly);
	//while(file2.isOpen() == 0);
	QDataStream stream2(&file2);
	stream2.setByteOrder(QDataStream::LittleEndian);
	QString str,str2,str3;

	int num2;
	stream2>>num2;							//sign
	if(num2!=0x11223344)
	{
		qDebug("This folder is wrong");
		return ;
	}

	stream2>>str;							//version
	qDebug()<<str;

	stream2>>str>>str2>>str3;				//name-surname-site
	qDebug() << str<<str2<<str3;

	stream2 >> str;							//choosing text
	qDebug() << str;

	stream2 >> str>>num2;
	qDebug() << str<<num2;

	stream2 >> str>>num2;
	qDebug() << str<<num2;

	stream2 >> str>>num2;
	qDebug() << str<<num2;

	stream2 >> str>>num2;
	qDebug() << str<<num2;

	stream2 >> str>>num2;
	qDebug() << str<<num2;


}




int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	Sefa t;

	QFile file("setting.dat");
	file.open(QIODevice::WriteOnly);
	QDataStream stream(&file);
	stream.setByteOrder(QDataStream::LittleEndian);

	int sign=0x11223344;
	stream<<sign;																			//Stream+
	QString version("Version 0");
	stream<<version;																		//Stream+

	QString name,surname,site;

	w.show();
	while (w.isVisible())
		QApplication::processEvents();

	name=w.name;
	surname=w.surname;
	site=w.site;
	stream<<name<<surname<<site;															//Stream+

	if(w.finalchoose==1) //Stress Test
	{
		qDebug("oldu1");
		stream<<QString("Selected test is Stress Test ");									//Stream
	}
	else if(w.finalchoose==2) //Functionality Test
	{
		qDebug("oldu2");
		stream<<QString("Selected test is Functionality Test ");							//Stream
	}
	else if(w.finalchoose==3) //Performance Test
	{
		qDebug("oldu3");
		stream<<QString("Selected test is Performance Test ");								//Stream
	}
	else
		qDebug("exit");

	afterChooseTest(t,stream);

	file.close();

	afterWritingFile();

	return a.exec();
}
