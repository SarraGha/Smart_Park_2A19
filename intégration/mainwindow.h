#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QApplication>
#include <QDesktopServices>
#include <QDebug>
#include <windows.h>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <chrono>
#include <thread>
#include <QDebug>
#include <iostream>

#include <QtCharts/QChartView>
#include <QtGui>
#include <QSystemTrayIcon>
#include <QtCharts/QAbstractSeries>
#include <QPieSeries>
#include <QPieSlice>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include "connexion.h"
#include "visite.h"
#include "arduino.h"
#include "exportexcel.h"
#include "produit.h"
#include "smtp.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//camera
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void update();

    /******Visite******/
    void on_pushButton_Ajouter_V_clicked();

    void on_pushButton_Modifier_V_clicked();

    void on_pushButton_Supprimer_V_clicked();

    void on_lineEdit_rechercher_V_textChanged(const QString &arg1);

    void on_comboBox_trier_V_currentIndexChanged(int index);

    void on_comboBox_Remise_V_currentIndexChanged(int index);

    void on_genererPDF_V_clicked();

    void on_genererEXCEL_V_clicked();

    void on_pushButton_acceder_clicked();

    void on_acces_V_clicked();

    void on_acces_P_clicked();

    void on_acces_A_clicked();

    void on_acces_E_clicked();

    void on_pushButton_Retour_V_clicked();

    void on_pushButton_Retour_P_clicked();



    /******Produit******/
    void refresh();

    void on_pushButton_Ajouter_p_clicked();

    void on_pushButton_supprimer_p_clicked();

    void on_pushButton_modifier_p_clicked();

    void on_comboBox_Tri_p_currentIndexChanged(const QString &arg1);

    void on_croissant_p_clicked();

    void on_decroissant_p_clicked();

    void on_lineEdit_rechercher_p_textChanged(const QString &arg1);


    void on_acces_M_clicked();

    void on_pushButton_Retour_A_clicked();

    void on_pushButton_Retour_E_clicked();

    void on_pushButton_Retour_M_clicked();

    void on_pushButton_Stat_p_clicked();

    void on_pushButton_alertes_p_clicked();

    void on_alerter_p_clicked();

    void on_pushButton_mail_p_clicked();

    void on_send_p_clicked();

    void on_pushButton_retourS_p_clicked();

    void on_pushButton_retourA_p_clicked();

    void on_pushButton_retourM_p_clicked();

private:
    Ui::MainWindow *ui;
    /******Visite******/
    Visite Vte;

    //camera
    QCamera *Camera;
    QCameraViewfinder *CameraViewfinder;
    QCameraImageCapture *CameraImageCapture;
    QVBoxLayout *Layout;
    QMenu *menuOptions;
    QAction *demarrerCamera;
    QAction *stopperCamera;
    QAction *captureCamera;

    //Arduino
    QByteArray data; //variable content les données reçues
    Arduino A;


    /******Produit******/
    produit Ptmp;
    Smtp* smtp;
    QString msg;
    QString mail;


};
#endif // MAINWINDOW_H
