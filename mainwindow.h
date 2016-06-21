#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_optNone_clicked();

    void on_optDesc_clicked();

    void on_optAsc_clicked();

private:
    Ui::MainWindow *ui;
    int fnFindSum(QString strNumberValue);
    void fnSetSorting();
};

#endif // MAINWINDOW_H
