#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>

#include "connexion.h"
#include"arduino.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion cnx;
    bool test=cnx.createConnection();
    MainWindow w;
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connetion successful.\n""Click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Database is not open"),
                                 QObject::tr("Connetion failed.\n""Click cancel to exit."), QMessageBox::Cancel);
    }


    //arduino
    Arduino arduino;
    bool testA=arduino.connect_arduino();
        if(testA)
        {
            w.show();
            QMessageBox::information(nullptr, QObject::tr("Arduino is open"),
                              QObject::tr("connection to Arduino succeful\n"),QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Arduino is not open"),
                        QObject::tr("connection to Arduino failed.\n"),
                                  QMessageBox::Cancel);




    return a.exec();
}
