#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include<QDesktopServices>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QDateTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ajouter_clicked();

    void on_tab_employes_activated(const QModelIndex &index);

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_tab_employes_pressed(const QModelIndex &index);

    void on_tableWidget_2_cellActivated(int row, int column);

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();



    void on_recherchee_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_label_2_linkActivated(const QString &link);

    void on_comboBox_activated(const QString &arg1);

    void on_pb_rechercher_clicked();

private:
    Ui::MainWindow *ui;
    employe tmpemploye;
    QDesktopServices service;
    QDateTime date;
};

#endif // MAINWINDOW_H
