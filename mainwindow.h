#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariant>

#include "testselectionwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	QString name;
	QString filename;

public slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

private slots:
	void on_pushButton_3_clicked();

private:
	Ui::MainWindow *ui;
	TestSelectionWidget wTest;
};

#endif // MAINWINDOW_H
