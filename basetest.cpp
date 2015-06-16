#include "basetest.h"
#include "testselectionwidget.h"
#include "filename.h"

#include <QDateTime>
#include <QFile>
#include <errno.h> //wireshark  C++exeption
#include <QDebug>

#include <iostream>
using namespace std;

BaseTest::BaseTest()
{
	state = STATE_IDLE;
}

int BaseTest::start()
{
	startTime = QDateTime::currentDateTime();

	setState(STATE_STARTING);
	return 0;
}

int BaseTest::stop()
{
	finishTime = QDateTime::currentDateTime();

	setState(STATE_IDLE);
	return 0;
}

void BaseTest::setState(BaseTest::TestState s)
{
	state = s;
}
BaseTest::TestState BaseTest::getState()
{
	return state;
}

const QHash<QString, QVariant> BaseTest::getTestParameters()
{
	return testParameters;
}

void BaseTest::setTestParameter(QString &name, QVariant &par,QString &filename)
{
	setState(STATE_RUNNING);
	if(par == 1) //Stress Test
	{
		par="Stress Test";
	}
	else if(par == 2) //Functionality Test
	{
		par="Functionality Test";
	}
	else if(par == 3) //Performance Test
	{
		par="Performance Test";
	}
	else
	{
		par="None of the parameters is not selected";
	}

	testParameters.insert(name, par);
	qDebug()<<testParameters<<filename;
	saveTest(filename);
}

int BaseTest::saveTest(const QString &filename)
{
	QFile file(filename);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
		return -ENOENT;

	QDataStream stream(&file);
	stream.setByteOrder(QDataStream::LittleEndian);
	stream<<QString("Start time : ")<<startTime;
	stream << testParameters;
	stream<<QString("Finish time : ")<<finishTime;
	file.close();

	return 0;
}

int BaseTest::loadTest(const QString &filename)
{
	qDebug("\n\nAfter Writing File:\n\n");
	//QHash <QString, QVariant> testParameters2;
	QFile file2(filename);
	if(!file2.open(QIODevice::ReadOnly))
	{
		qDebug("File is not open for reading");
		return -ENOENT;
	}
	QDataStream stream2(&file2);
	stream2.setByteOrder(QDataStream::LittleEndian);
	QString str,str2;
	QDateTime start,finish;
	stream2>>str>>start;
	stream2 >> testParameters;
	stream2>>str2>>finish;
	qDebug()<<str<<" "<<start<<"\n"<<testParameters<<"\n"<<str2<<" "<<finish;
	file2.close();
	return 0;
}
