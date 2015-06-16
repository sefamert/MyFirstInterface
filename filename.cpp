#include "filename.h"
#include "ui_filename.h"

FileName::FileName(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::FileName)
{
	ui->setupUi(this);
}

FileName::~FileName()
{
	delete ui;
}
void FileName::closeEvent(QCloseEvent *ev)
{
	fileName=ui->lineEdit_2->text();
	QWidget::closeEvent(ev);
}

void FileName::on_pushButton_clicked()
{
	close();
}
