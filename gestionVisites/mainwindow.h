#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <visite.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//camera
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Supprimer_clicked();

    void on_pushButton_Modifier_clicked();

    void on_lineEdit_rechercher_textChanged(const QString &critere);

    void on_comboBox_trier_currentIndexChanged(int index);

    void on_genererPDF_clicked();

    void on_genererEXCEL_clicked();

    void on_comboBox_Remise_currentIndexChanged(int index);

    //void on_pushButton_acceder_clicked();

private:
    Ui::MainWindow *ui;

    Visite Vte;

    //camera
    QCamera *Camera;
    QCameraViewfinder *CameraViewfinder;
    QCameraImageCapture *CameraImageCapture;
    QVBoxLayout *Layout;
};
#endif // MAINWINDOW_H
