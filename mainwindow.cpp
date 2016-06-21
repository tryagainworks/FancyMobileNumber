#include "mainwindow.h"
#include "ui_mainwindow.h"

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
	ui->listWidget_2->clear();
	QString strText="";
	int intSumValue = ui->plainTextEdit->toPlainText().toInt();
	for(int i=0; i<ui->listWidget->count(); i++)
	{
		strText = ui->listWidget->item(i)->text();
		if(fnFindSum(strText)==intSumValue)
		{
			ui->listWidget_2->addItem(strText);
		}
	}
}

int MainWindow::fnFindSum(QString strNumberValue)
{
	if(strNumberValue.length()==1)
	{
		return strNumberValue.toInt();
	}
	else
	{
		long lngValue=0;
		for(int i=0; i<strNumberValue.length(); i++)
		{
			//lngValue += QString::toInt(""+strNumberValue.at(i));
			QChar c = strNumberValue.at(i);
			if(c.isDigit())
			{
				lngValue += c.digitValue();
			}
		}
		return fnFindSum(QString::number(lngValue));
	}
}


void MainWindow::on_pushButton_2_clicked()
{
	QString strValue = QInputDialog::getMultiLineText(this,"Number list","Enter the number list separated by comma");
	if(strValue.trimmed()!="")
	{
        QStringList strLst;
       if (ui->optDelimitNonly->isChecked())
            strLst = strValue.split("\n");
       else if(ui->optDelimitNandR->isChecked())
           strLst = strValue.split("\r\n");
       else if(ui->optDelimitColon->isChecked())
           strLst = strValue.split(":");
       else if(ui->optDelimitComa->isChecked())
           strLst = strValue.split(",");
       else if(ui->optDelimitPipe->isChecked())
           strLst = strValue.split("|");
       else if(ui->optDelimitSemicolon->isChecked())
           strLst = strValue.split(";");
       else if(ui->optDelimitSlash->isChecked())
           strLst = strValue.split("/");
       else if(ui->optDelimitTab->isChecked())
           strLst = strValue.split("");

		ui->listWidget->clear();
		ui->listWidget->addItems(strLst);
	}
}

void MainWindow::fnSetSorting()
{
    if(ui->optAsc->isChecked())
	{
        ui->listWidget_2->setSortingEnabled(true);
		ui->listWidget_2->sortItems(Qt::AscendingOrder);
    }else if(ui->optDesc->isChecked())
    {
        ui->listWidget_2->setSortingEnabled(true);
        ui->listWidget_2->sortItems(Qt::DescendingOrder);
    }
	else
	{
		ui->listWidget_2->setSortingEnabled(false);
	}
}

void MainWindow::on_optNone_clicked()
{
    fnSetSorting();
}

void MainWindow::on_optDesc_clicked()
{
    fnSetSorting();
}

void MainWindow::on_optAsc_clicked()
{
    fnSetSorting();
}
