#ifndef TESTSELECTIONWIDGET_H
#define TESTSELECTIONWIDGET_H

#include <QWidget>

namespace Ui {
class TestSelectionWidget;
}

class TestSelectionWidget : public QWidget
{
	Q_OBJECT

public:
	explicit TestSelectionWidget(QWidget *parent = 0);
	~TestSelectionWidget();

	int choose;
	QString name;
	QString surname;
	QString site;
private slots:

	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();

protected:
	int closeEvent(int ev);
private:
	Ui::TestSelectionWidget *ui;
};

#endif // TESTSELECTIONWIDGET_H
