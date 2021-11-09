#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QSortFilterProxyModel>
#include "animaux.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajout_Button_clicked();

    void on_Del_Button_clicked();

    void on_Edit_Button_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel * model;
    Animaux A;
};
#endif // MAINWINDOW_H
