#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "connexion.h"
#include "visite.h"

#include <QMessageBox>
#include <QApplication>



#include <QDebug>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_BD->setModel(Vte.afficher());
    ui->dateEdit_dateVisite->setDate(QDate::currentDate());
    setWindowTitle("Smart Zoo");
}


void MainWindow::on_pushButton_Ajouter_clicked()
{

    QString identifiantTicket = ui->lineEdit_IdentifiantTicket->text();
    float prixTicket = ui->lineEdit_PrixTicket->text().toFloat();
    QString identifiantVisiteur = ui->lineEdit_IdentifiantVisiteur->text();
    int nombreVisites = ui->spinBox_nbrVisites->text().toInt();
    QString dateVisite = ui->dateEdit_dateVisite->date().toString();
    QString abonnement = ui->comboBox_abonnement->currentText();



    qDebug()<<identifiantTicket;
    qDebug()<<prixTicket;
    qDebug()<<identifiantVisiteur;
    qDebug()<<nombreVisites;
    qDebug()<<dateVisite;
    qDebug()<<abonnement;




    Visite V(identifiantTicket, prixTicket, identifiantVisiteur, nombreVisites, dateVisite, abonnement);

    bool test = V.ajouter();

    if(test)
    {
        //actualisation de l'affichage
        ui->tableView_BD->setModel(Vte.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué.\n""Click cancel to exit."), QMessageBox::Cancel);
    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Ajout non effectué.\n""Click cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_Supprimer_clicked()
{
    QString idT = ui->lineEdit_supprimer->text();

    bool test=Vte.supprimer(idT);

    if(test)
    {
        //actualisation de l'affichage
        ui->tableView_BD->setModel(Vte.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n", "Click cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Suppression non effectuée\n", "Click cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_Modifier_clicked()
{
    QString identifiantTicket = ui->lineEdit_IdentifiantTicket->text();
    float prixTicket = ui->lineEdit_PrixTicket->text().toFloat();
    QString identifiantVisiteur = ui->lineEdit_IdentifiantVisiteur->text();
    int nombreVisites = ui->spinBox_nbrVisites->text().toInt();
    QString dateVisite = ui->dateEdit_dateVisite->date().toString();
    QString abonnement = ui->comboBox_abonnement->currentText();

    Visite V(identifiantTicket, prixTicket, identifiantVisiteur, nombreVisites, dateVisite, abonnement);

    bool test= V.modifier(identifiantTicket);

    if(test)
    {
        //actualisation de l'affichage
        ui->tableView_BD->setModel(Vte.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuée\n", "Click cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Modification non effectuée\n", "Click cancel to exit."), QMessageBox::Cancel);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


