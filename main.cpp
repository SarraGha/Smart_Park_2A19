#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;// instance de la classe connexion
   // Arduino ar;//instance de la classe Arduino

    bool test=c.createconnect();//etablir la connexion
    MainWindow w; // appel a la methode afficher

    if(test)//Si la connexion est etablie
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
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

