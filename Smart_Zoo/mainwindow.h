#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QSortFilterProxyModel>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtGui>
#include "animaux.h"
#include<QtSerialPort>
#include<QSerialPortInfo>
#include <QMessageBox>


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

    void on_AjouterRepas_clicked();

    void on_lineEdit_id_textChanged(const QString &arg1);

    void on_SuppRepas_clicked();

    void on_Genpdf_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);


    void on_LineEdit_Info_textChanged(const QString &arg1);

    void on_RechCage_clicked();

    void readSerial();

private:
    Ui::MainWindow *ui;
    QStandardItemModel * model;
    Animaux A;
    QGraphicsItem *item;
    QGraphicsScene *scene;
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_ID = 9025;
    static const quint16 arduino_uno_product_ID = 67;

    QString arduino_port_name;
    bool arduino_available;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data;
    QString UID;
};
#endif // MAINWINDOW_H
