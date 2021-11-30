#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "visite.h"
#include "connection.h"

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
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_excel_clicked();

    void on_pdf_clicked();

    void on_rechercher_clicked();

private:
    Ui::MainWindow *ui;

    Visite Vte;
};
#endif // MAINWINDOW_H