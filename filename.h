#ifndef FILENAME_H
#define FILENAME_H

#include <QWidget>

namespace Ui {
class FileName;
}

class FileName : public QWidget
{
	Q_OBJECT

public:
	explicit FileName(QWidget *parent = 0);
	~FileName();
	QString fileName;

private slots:
	void on_pushButton_clicked();

protected:
	void closeEvent(QCloseEvent *ev);
private:
	Ui::FileName *ui;
};

#endif // FILENAME_H
