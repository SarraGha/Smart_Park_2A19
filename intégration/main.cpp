#include "mainwindow.h"
#include "connexion.h"


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



    return a.exec();
}
