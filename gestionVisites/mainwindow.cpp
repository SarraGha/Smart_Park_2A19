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
    int prixTicket = ui->lineEdit_PrixTicket->text().toInt();
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



    bool test_idTicket=true;
    bool test_idVisiteur=true;

    if(identifiantTicket.isEmpty())
    {
        test_idTicket=false;
    }
    else
    {
        for(int i =0 ; i < identifiantTicket.size(); i++)
        {
            if(identifiantTicket[i]=='0' || identifiantTicket[i] == '1' || identifiantTicket[i] == '2' || identifiantTicket[i] == '3'
                    || identifiantTicket[i] == '4'|| identifiantTicket[i] == '5' || identifiantTicket[i] == '6' || identifiantTicket[i] == '7'
                    || identifiantTicket[i] == '8' || identifiantTicket[i] == '9')
            {
                test_idTicket=false;
                qDebug()<<identifiantTicket[i];
                qDebug()<<test_idTicket;
            }

        }
    }


    if(identifiantVisiteur.isEmpty())
    {
        test_idVisiteur=false;
    }
    else
    {
        for(int i =0 ; i < identifiantVisiteur.size(); i++)
        {
            if(identifiantVisiteur[i] != '0' && identifiantVisiteur[i] != '1' && identifiantVisiteur[i] != '2' && identifiantVisiteur[i] != '3'
                    && identifiantVisiteur[i] != '4' && identifiantVisiteur[i] != '5' && identifiantVisiteur[i] != '6' && identifiantVisiteur[i] != '7'
                    && identifiantVisiteur[i] != '8' && identifiantVisiteur[i] != '9')
            {
                test_idVisiteur=false;
                qDebug()<<identifiantVisiteur[i];
                qDebug()<<test_idVisiteur;
            }

        }
    }


    if(test_idTicket == false || prixTicket == 0 || test_idVisiteur == false)
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Ajout non permis.\n""Vérifiez les données."), QMessageBox::Cancel);

        if(test_idTicket == false)
            QMessageBox::critical(nullptr, QObject::tr("Erreur id_ticket"),
                                     QObject::tr("Identifiant Ticket ne doit contenir que des LETTRES."), QMessageBox::Cancel);

        if(test_idVisiteur == false)
            QMessageBox::critical(nullptr, QObject::tr("Erreur id_visiteur"),
                                     QObject::tr("Identifiant Visiteur ne doit contenir que des CHIFFRES."), QMessageBox::Cancel);

        if(prixTicket == 0)
            QMessageBox::critical(nullptr, QObject::tr("Erreur prix_ticket"),
                                     QObject::tr("Entez un prix ticket."), QMessageBox::Cancel);

    }

    else
    {
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
}

void MainWindow::on_pushButton_Supprimer_clicked()
{
    QString idT = ui->lineEdit_supprimer->text();
    bool test_idT=true;

    if(idT.isEmpty())
    {
        test_idT=false;
    }
    else
    {
        for(int i =0 ; i < idT.size(); i++)
        {
            if(idT[i]=='0' || idT[i] == '1' || idT[i] == '2' || idT[i] == '3'
                    || idT[i] == '4'|| idT[i] == '5' || idT[i] == '6' || idT[i] == '7'
                    || idT[i] == '8' || idT[i] == '9')
            {
                test_idT=false;

                qDebug()<<idT[i];
                qDebug()<<test_idT;
            }

        }
    }

    if(test_idT == false)
    {
            QMessageBox::critical(nullptr, QObject::tr("Erreur id_ticket"),
                                     QObject::tr("Identifiant Ticket ne doit contenir que des LETTRES."), QMessageBox::Cancel);
    }
    else
    {
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

}

void MainWindow::on_pushButton_Modifier_clicked()
{
    QString identifiantTicket = ui->lineEdit_IdentifiantTicket->text();
    int prixTicket = ui->lineEdit_PrixTicket->text().toInt();
    QString identifiantVisiteur = ui->lineEdit_IdentifiantVisiteur->text();
    int nombreVisites = ui->spinBox_nbrVisites->text().toInt();
    QString dateVisite = ui->dateEdit_dateVisite->date().toString();
    QString abonnement = ui->comboBox_abonnement->currentText();


    bool test_idTicket=true;
    bool test_idVisiteur=true;

    if(identifiantTicket.isEmpty())
    {
        test_idTicket=false;
    }
    else
    {
        for(int i =0 ; i < identifiantTicket.size(); i++)
        {
            if(identifiantTicket[i]=='0' || identifiantTicket[i] == '1' || identifiantTicket[i] == '2' || identifiantTicket[i] == '3'
                    || identifiantTicket[i] == '4'|| identifiantTicket[i] == '5' || identifiantTicket[i] == '6' || identifiantTicket[i] == '7'
                    || identifiantTicket[i] == '8' || identifiantTicket[i] == '9')
            {
                test_idTicket=false;
                qDebug()<<identifiantTicket[i];
                qDebug()<<test_idTicket;
            }

        }
    }


    if(identifiantVisiteur.isEmpty())
    {
        test_idVisiteur=false;
    }
    else
    {
        for(int i =0 ; i < identifiantVisiteur.size(); i++)
        {
            if(identifiantVisiteur[i] != '0' && identifiantVisiteur[i] != '1' && identifiantVisiteur[i] != '2' && identifiantVisiteur[i] != '3'
                    && identifiantVisiteur[i] != '4' && identifiantVisiteur[i] != '5' && identifiantVisiteur[i] != '6' && identifiantVisiteur[i] != '7'
                    && identifiantVisiteur[i] != '8' && identifiantVisiteur[i] != '9')
            {
                test_idVisiteur=false;
                qDebug()<<identifiantVisiteur[i];
                qDebug()<<test_idVisiteur;
            }

        }
    }


    if(test_idTicket == false || prixTicket == 0 || test_idVisiteur == false)
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Modification non permise.\n""Vérifiez les données."), QMessageBox::Cancel);

        if(test_idTicket == false)
            QMessageBox::critical(nullptr, QObject::tr("Erreur id_ticket"),
                                     QObject::tr("Identifiant Ticket ne doit contenir que des LETTRES."), QMessageBox::Cancel);

        if(test_idVisiteur == false)
            QMessageBox::critical(nullptr, QObject::tr("Erreur id_visiteur"),
                                     QObject::tr("Identifiant Visiteur ne doit contenir que des CHIFFRES."), QMessageBox::Cancel);

        if(prixTicket == 0)
            QMessageBox::critical(nullptr, QObject::tr("Erreur prix_ticket"),
                                     QObject::tr("Entez un prix ticket."), QMessageBox::Cancel);

    }

    else
    {
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

}

void MainWindow::on_lineEdit_rechercher_textChanged(const QString &critere)
{
    ui->tableView_BD->setModel(Vte.rechercher(critere));
}




void MainWindow::on_pushButton_Trier_clicked()
{
    QString critere;
    if(ui->comboBox_trier->currentData() == "Ordre Croissant")
    {
        critere="ASC";
    }
    else
    {
        critere="DESC";
    }

    ui->tableView_BD->setModel(Vte.trier(critere));
}


MainWindow::~MainWindow()
{
    delete ui;
}
