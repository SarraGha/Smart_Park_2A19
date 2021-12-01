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

#include "connexion.h"
#include "visite.h"
#include "arduino.h"
#include "exportexcel.h"



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

    void on_pushButton_Ajouter_V_clicked();

    void on_pushButton_Modifier_V_clicked();

    void on_pushButton_Supprimer_V_clicked();

    void on_lineEdit_rechercher_V_textChanged(const QString &arg1);

    void on_comboBox_trier_V_currentIndexChanged(int index);

    void on_comboBox_Remise_V_currentIndexChanged(int index);

    void on_genererPDF_V_clicked();

    void on_genererEXCEL_V_clicked();

    void on_pushButton_acceder_clicked();

private:
    Ui::MainWindow *ui;

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

};
#endif // MAINWINDOW_H
