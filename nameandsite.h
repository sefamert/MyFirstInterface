#ifndef NAMEANDSITE_H
#define NAMEANDSITE_H

#include <QWidget>

namespace Ui {
class NameAndSite;
}

class NameAndSite : public QWidget
{
	Q_OBJECT

public:
	explicit NameAndSite(QWidget *parent = 0);
	~NameAndSite();

	QString name;
	QString surname;
	QString filename;
protected:
	void closeEvent(QCloseEvent *ev);
private slots:
	void on_pushButton_clicked();

private:
	Ui::NameAndSite *ui;
};

#endif // NAMEANDSITE_H
