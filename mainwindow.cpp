#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testselectionwidget.h"
#include "nameandsite.h"
#include "basetest.h"
#include "filename.h"

#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	TestSelectionWidget t;
	BaseTest base;
	t.show();
	while (t.isVisible())
		QApplication::processEvents();
	name=t.name;
	name.append(" ");
	name.append(t.surname);
	filename=t.filename;
	QVariant ch=t.choose;
	base.setTestParameter(name,ch,filename);
}

void MainWindow::on_pushButton_2_clicked()
{
	QMessageBox::information(this, "", "I will close now!");
	BaseTest basetest;
	basetest.stop();
	close();
}

void MainWindow::on_pushButton_3_clicked()
{
	FileName fname;
	fname.show();
	while (fname.isVisible())
		QApplication::processEvents();
	filename=fname.fileName;
	qDebug()<<filename;
	BaseTest base;
	base.loadTest(filename);
	qDebug()<< base.getTestParameter();
}
