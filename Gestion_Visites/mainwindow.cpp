#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDate>

#include "visite.h"
#include "connection.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Vte.afficher());
    ui->dateEdit->setDate(QDate::currentDate());
}



void MainWindow::on_ajouter_clicked()
{

    QString identifiantTicket = ui->lineEdit_idT->text();
    float prixTicket = ui->lineEdit_prixTicket->text().toFloat();
    QString identifiantVisiteur = ui->lineEdit_idVisiteur->text();
    QString dateVisite = ui->dateEdit->date().toString();
    int nbrVisites = ui->spinBox->text().toInt();
    //int abonnement = ui->spinBox->text().toInt();


    int abonnement=0;


    if(ui->checkBox_oui->checkState() == true)
    {
        abonnement=1;
    }

    Visite V(identifiantTicket, prixTicket, identifiantVisiteur, nbrVisites, abonnement, dateVisite);

    bool test = V.ajouter();

    if(test)
    {
        //actualisation de l'affichage
        ui->tableView->setModel(Vte.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n", "Click cancel to exit."), QMessageBox::Cancel);

    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Ajout non effectué\n", "Click cancel to exit."), QMessageBox::Cancel);
    }

};


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_supprimer_clicked()
{
    int idT = ui->lineEdit_idT->text().toInt();

    bool test=Vte.supprimer(idT);

    if(test)
    {
        //actualisation de l'affichage
        ui->tableView->setModel(Vte.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectué\n", "Click cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Suppression non effectué\n", "Click cancel to exit."), QMessageBox::Cancel);
    }

};








void MainWindow::on_modifier_clicked()
{

};


