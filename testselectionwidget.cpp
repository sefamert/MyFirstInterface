#include "testselectionwidget.h"
#include "ui_testselectionwidget.h"
#include "nameandsite.h"

#include <QDebug>

TestSelectionWidget::TestSelectionWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TestSelectionWidget)
{
	ui->setupUi(this);
}

TestSelectionWidget::~TestSelectionWidget()
{
	delete ui;
}



void TestSelectionWidget::on_pushButton_clicked()
{
	NameAndSite n;
	n.show();
	while (n.isVisible())
		QApplication::processEvents();
	name=n.name;
	surname=n.surname;
	site=n.site;
	qDebug() << n.name << n.surname<<n.site;
	choose=1;
}

void TestSelectionWidget::on_pushButton_2_clicked()
{
	NameAndSite n;
	n.show();
	while (n.isVisible())
		QApplication::processEvents();
	name=n.name;
	surname=n.surname;
	site=n.site;
	qDebug() << n.name << n.surname<<n.site;
	choose=2;
}

void TestSelectionWidget::on_pushButton_3_clicked()
{
	NameAndSite n;
	n.show();
	while (n.isVisible())
		QApplication::processEvents();
	name=n.name;
	surname=n.surname;
	site=n.site;
	qDebug() << n.name << n.surname<<n.site;
	choose=3;

}

void TestSelectionWidget::on_pushButton_4_clicked()
{
	close();
}
