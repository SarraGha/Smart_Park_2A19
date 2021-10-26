#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>

#include "visite.h"
#include "connection.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



void MainWindow::on_ajouter_clicked()
{
    QString identifiantTicket = ui->lineEdit_idT->text();
    float prixTicket = ui->lineEdit_prixTicket->text().toFloat();
    QString identifiantVisiteur = ui->lineEdit_idVisiteur->text();
    QString dateVisite = ui->dateEdit->text();
    int nbrVisites = ui->spinBox->text().toUInt();

    Visite V(identifiantTicket, prixTicket, identifiantVisiteur, nbrVisites, dateVisite);

    bool test = V.ajouter();

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n", "Click canncel to exit."), QMessageBox::Cancel);

    }

};


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_supprimer_clicked()
{
    /*QSqlQuery query;
    QString*/
}








void MainWindow::on_modifier_clicked()
{

}

