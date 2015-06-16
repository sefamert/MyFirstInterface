#ifndef BASETEST_H
#define BASETEST_H

#include <QHash>
#include <QList>
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QVariant>

class BaseTest
{
public:
	BaseTest();

	enum TestState {
		STATE_IDLE,
		STATE_STARTING,
		STATE_RUNNING,
		STATE_STOPPING,
	};

	virtual int start();//+
	virtual int stop();//+
	TestState getState();
	void setTestParameter(QString &name, QVariant &par,QString &filename);

	/*içleri doldurulacak*/
	const QHash<QString, QVariant> getTestParameter();
	int saveTest(const QString &filename);
	int loadTest(const QString &filename);


protected:
	int run(); /* protected yapalim */

	void setState(TestState s);
	QStringList log;							/* will be filled by sub-classes  */
	QHash<QString, QVariant> testParameters;    /* will be set by sub-class users */
	QStringList site;
private:
	TestState state;					//yapıldı
	QDateTime startTime;				//yapıldı
	QDateTime finishTime;				//yapıldı
	/* run time */
};

#endif // BASETEST_H

/*değişiklik yapılan*/
