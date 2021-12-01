#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "produit.h"
#include "smtp.h"
#include "arduino.h"
#include"QString"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void update();


    void refresh();



    void on_croissant_p_clicked();

    void on_decroissant_p_clicked();

    void on_lineEdit_4_p_textChanged(const QString &arg1);







  //  void on_pushButton_clicked(bool checked);




    void on_pushButton_Ajouter_p_clicked();

    void on_pushButton_supprimer_p_clicked();

    void on_pushButton_modifier_p_clicked();


    void on_comboBox_Tri_p_currentIndexChanged(const QString &arg1);

    void on_pushButton_Stat_p_clicked();

    void on_pushButton_alertes_p_clicked();

    void on_pushButton_6_p_clicked();

    void on_alerter_p_clicked();

    void on_pushButton_mail_p_clicked();

    void on_send_p_clicked();



private:
    Ui::MainWindow *ui;
    produit Etmp;//ajout un attribut a la classe mainwindow
    //qui correspond a un objet de la classe produit pour
    //pouvoir faire appel a la methode supprimer()

    Smtp* smtp;
    QString msg;
    QString mail;
  Arduino A;//instancier un objet pour utiliser les methodes d'Arduino
    QByteArray data;//valeur retournée de ReadFrom Arduino
};
#endif // MAINWINDOW_H
