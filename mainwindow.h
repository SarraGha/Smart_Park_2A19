#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"magasin.h"
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
    void on_ajout_clicked();

    void on_afficher_clicked();

    void on_supprimer_clicked();

    void on_Modifier_clicked();

private:
    Ui::MainWindow *ui;
    magasin m;
};

#endif // MAINWINDOW_H
