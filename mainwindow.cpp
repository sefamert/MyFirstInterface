#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testselectionwidget.h"
#include "nameandsite.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->groupBox->setVisible(false);
	finalchoose=0;
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	TestSelectionWidget t;
	t.show();
	while (t.isVisible())
		QApplication::processEvents();
	name=t.name;
	surname=t.surname;
	site=t.site;
	finalchoose = t.choose;
}

void MainWindow::on_pushButton_2_clicked()
{
	QMessageBox::information(this, "", "I will close now!");
	close();
}
