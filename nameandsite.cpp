#include "nameandsite.h"
#include "ui_nameandsite.h"

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
	site=ui->lineEdit_6->text();
	QWidget::closeEvent(ev);
}
