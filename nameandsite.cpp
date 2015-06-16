#include "nameandsite.h"
#include "ui_nameandsite.h"
#include "basetest.h"

NameAndSite::NameAndSite(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::NameAndSite)
{
	ui->setupUi(this);
}

NameAndSite::~NameAndSite()
{
	delete ui;
}

void NameAndSite::closeEvent(QCloseEvent *ev)
{
	name = ui->lineEdit_2->text();
	surname=ui->lineEdit_4->text();
	filename=ui->lineEdit_6->text();
	QWidget::closeEvent(ev);
}

void NameAndSite::on_pushButton_clicked()
{
	BaseTest basetest;
	basetest.start();
	close();
}
