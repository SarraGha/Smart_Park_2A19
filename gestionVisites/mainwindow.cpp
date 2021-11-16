#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "connexion.h"
#include "visite.h"

#include <QMessageBox>
#include <QApplication>
#include "exportexcel.h"
#include <QDesktopServices>

#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>


#include <QDebug>
#include <iostream>
using namespace std;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_BD->setModel(Vte.afficher());
    setWindowTitle("Smart Zoo");
    setWindowIcon(QIcon("C:/Users/MSI/Desktop/2021-2022/semestre 1/projet c++/travail perso/icone/1x/logo_App_1.png"));



    ui->dateEdit_dateVisite->setDate(QDate::currentDate());
    ui->lineEdit_PrixTicket->setValidator(new QIntValidator(0, 99, this));
    ui->lineEdit_PrixTicket->setMaxLength(2);
    ui->lineEdit_IdentifiantTicket->setMaxLength(8);
    ui->lineEdit_IdentifiantVisiteur->setMaxLength(8);
    ui->lineEdit_rechercher->setMaxLength(8);


    //camera
    Camera=new QCamera(this);
    CameraViewfinder = new QCameraViewfinder(this);
    CameraImageCapture = new QCameraImageCapture(Camera, this);
    Layout = new QVBoxLayout;

    //Layout->addItem(CameraViewfinder);

}


void MainWindow::on_pushButton_Ajouter_clicked()
{

    QString identifiantTicket = ui->lineEdit_IdentifiantTicket->text();
    int prixTicket = ui->lineEdit_PrixTicket->text().toInt();
    QString identifiantVisiteur = ui->lineEdit_IdentifiantVisiteur->text();
    int nombreVisites = ui->spinBox_nbrVisites->text().toInt();
    QString dateVisite = ui->dateEdit_dateVisite->date().toString();
    QString abonnement = ui->comboBox_abonnement->currentText();
    QString idAnimal = ui->lineEdit_IdentifiantAnimal->text();




    qDebug()<<identifiantTicket;
    qDebug()<<prixTicket;
    qDebug()<<identifiantVisiteur;
    qDebug()<<nombreVisites;
    qDebug()<<dateVisite;
    qDebug()<<abonnement;
    qDebug()<<idAnimal;



    bool test_idTicket=true;
    bool test_idVisiteur=true;
    bool test_idAnimal=true;

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



        for(int i =0 ; i < idAnimal.size(); i++)
        {
            if(idAnimal[i] != '0' && idAnimal[i] != '1' && idAnimal[i] != '2' && idAnimal[i] != '3'
                    && idAnimal[i] != '4' && idAnimal[i] != '5' && idAnimal[i] != '6' && idAnimal[i] != '7'
                    && idAnimal[i] != '8' && idAnimal[i] != '9')
            {
                test_idAnimal=false;
                qDebug()<<idAnimal[i];
                qDebug()<<test_idAnimal;
            }

        }


    if(test_idTicket == false || prixTicket == 0 || test_idVisiteur == false || test_idAnimal == false)
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
        if(test_idAnimal == false)
            QMessageBox::critical(nullptr, QObject::tr("Erreur id_animal"),
                                     QObject::tr("Identifiant Animal ne doit contenir que des CHIFFRES."), QMessageBox::Cancel);

    }

    else
    {
        Visite V(identifiantTicket, prixTicket, identifiantVisiteur, nombreVisites, dateVisite, abonnement, idAnimal);

        bool test = V.ajouter();

        if(test)
        {
            //actualisation de l'affichage
            ui->tableView_BD->setModel(Vte.afficher());

            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Ajout effectué.\n""Cliquez sur 'Cancel' pour quitter."), QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Ajout non effectué.\n""Vérifiez l'Identifiant Ticket."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_Supprimer_clicked()
{

    int reponse = QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer cette Visite (ou ces Visites) ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        bool test ;

        QString idT ;
        QModelIndex index ;
        QModelIndexList selection = ui->tableView_BD->selectionModel()->selectedRows();

        //parcourir les index. Utile particulièrement pour une sélection multiple
        //selection.count() permet de parcourir les données sélectionnés
        for (int i =0;i<selection.count();i++)
        {
            index=selection.at(i);


            //QVariant().toString = Retourne le QVariant sous forme d'un QString
            //index.row() car l'index est de type QModelIndex et on doit connaître la ligne exacte du tab en tant que int

            idT=QVariant(ui->tableView_BD->model()->index(index.row(),0).data()).toString();

            test = Vte.supprimer(idT) ;

                if (test)
                {
                    //actualisation de l'affichage
                    ui->tableView_BD->setModel(Vte.afficher());

                    QMessageBox::information(nullptr, QObject::tr("Supprimer une Visite"),
                    QObject::tr("Visite supprimée.\n"
                                 "Cliquez sur 'Cancel' pour quitter."), QMessageBox::Cancel);
                }
        }

    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::critical(this, "Annulation", "La suppression de cette Visite (ou ces Visites) a été annuler !");
    }



    /*
     * ancien code supprimer
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
                                     QObject::tr("Suppression effectuée\n", "Cliquez sur 'Cancel' pour quitter."), QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Suppression non effectuée\n", "Vérifiez l'Identifiant Ticket."), QMessageBox::Cancel);
        }
    }*/

}

void MainWindow::on_pushButton_Modifier_clicked()
{
    QString identifiantTicket = ui->lineEdit_IdentifiantTicket->text();
    int prixTicket = ui->lineEdit_PrixTicket->text().toInt();
    QString identifiantVisiteur = ui->lineEdit_IdentifiantVisiteur->text();
    int nombreVisites = ui->spinBox_nbrVisites->text().toInt();
    QString dateVisite = ui->dateEdit_dateVisite->date().toString();
    QString abonnement = ui->comboBox_abonnement->currentText();
    QString idAnimal = ui->lineEdit_IdentifiantAnimal->text();

    bool test_idTicket=true;
    bool test_idVisiteur=true;
    bool test_idAnimal=true;

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


    for(int i =0 ; i < idAnimal.size(); i++)
    {
        if(idAnimal[i] != '0' && idAnimal[i] != '1' && idAnimal[i] != '2' && idAnimal[i] != '3'
                && idAnimal[i] != '4' && idAnimal[i] != '5' && idAnimal[i] != '6' && idAnimal[i] != '7'
                && idAnimal[i] != '8' && idAnimal[i] != '9')
        {
            test_idAnimal=false;
            qDebug()<<idAnimal[i];
            qDebug()<<test_idAnimal;
        }

    }


    if(test_idTicket == false || prixTicket == 0 || test_idVisiteur == false || test_idAnimal == false)
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
        Visite V(identifiantTicket, prixTicket, identifiantVisiteur, nombreVisites, dateVisite, abonnement, idAnimal);

        bool test= V.modifier(identifiantTicket);

        if(test)
        {
            //actualisation de l'affichage
            ui->tableView_BD->setModel(Vte.afficher());

            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Modification effectuée\n", "Cliquez sur 'Cancel' pour quitter."), QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Modification non effectuée\n", "Vérifiez les données."), QMessageBox::Cancel);
        }
    }

}

void MainWindow::on_lineEdit_rechercher_textChanged(const QString &critere)
{
    ui->tableView_BD->setModel(Vte.rechercher(critere));
}

void MainWindow::on_comboBox_trier_currentIndexChanged(int index)
{
    QString critere;
    if(index==2)
    {
        critere="select * from Visites order by prixTicket DESC";
        ui->tableView_BD->setModel(Vte.trier(critere));
    }

    if(index==1)
    {
        critere="select * from Visites order by prixTicket ASC";
        ui->tableView_BD->setModel(Vte.trier(critere));
    }

    if(index==0)
    {
        ui->tableView_BD->setModel(Vte.afficher());
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_genererPDF_clicked()
{


    QString identifiantTicket = ui->lineEdit_IdentifiantTicket->text();
    int prixTicket = ui->lineEdit_PrixTicket->text().toInt();
    QString identifiantVisiteur = ui->lineEdit_IdentifiantVisiteur->text();
    int nombreVisites = ui->spinBox_nbrVisites->text().toInt();
    QString dateVisite = ui->dateEdit_dateVisite->date().toString();
    QString abonnement = ui->comboBox_abonnement->currentText();
    QString idAnimal = ui->lineEdit_IdentifiantAnimal->text();



    Visite V(identifiantTicket, prixTicket, identifiantVisiteur, nombreVisites, dateVisite, abonnement, idAnimal);

    V.genererPDF(V);
}


void MainWindow::on_genererEXCEL_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
    qDebug()<<fileName;

        if (fileName.isEmpty())
            return;
        ExportExcelObject obj(fileName, "mydata", ui->tableView_BD);
        //colums to export
        obj.addField(0, "IdentifiantTicket", "char(20)");
        obj.addField(1, "PrixTicket", "char(20)");
        obj.addField(2, "IdentifiantVisiteur", "char(20)");
        obj.addField(3, "NombreVisites", "char(20)");
        obj.addField(4, "DateVisite", "char(20)");
        obj.addField(5, "Abonnement", "char(20)");
        obj.addField(6, "ID_Animal", "char(20)");

        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),QString(tr("%1 records exported!")).arg(retVal));
        }


        QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));

}

void MainWindow::on_comboBox_Remise_currentIndexChanged(int index)
{

    QString critere;
    int prixTicket = ui->lineEdit_PrixTicket->text().toInt();

    if(index==4)
    {
        prixTicket=prixTicket*0.5;
        QString prixTicketString = QString::number(prixTicket);
        ui->lineEdit_PrixTicket->setText(prixTicketString);
    }
    if(index==3)
    {
        prixTicket=prixTicket*0.7;
        QString prixTicketString = QString::number(prixTicket);
        ui->lineEdit_PrixTicket->setText(prixTicketString);
    }

    if(index==2)
    {
        prixTicket=prixTicket*0.8;
        QString prixTicketString = QString::number(prixTicket);
        ui->lineEdit_PrixTicket->setText(prixTicketString);
    }

    if(index==1)
    {
        prixTicket=prixTicket*0.9;
        QString prixTicketString = QString::number(prixTicket);
        ui->lineEdit_PrixTicket->setText(prixTicketString);
    }

}

/*
void MainWindow::on_pushButton_acceder_clicked()
{

    *  QString userName = ui->identifiantAccueil->text();
    QString password = ui->motDePasseAccueil->text();
    QSqlQuery query;

    query.prepare("SELECT identifiant FROM Comptes where identifiant= :userName and mdp= :password");
    query.bindValue(":userName", userName);
    query.bindValue(":password", password);

    bool test = query.exec();

    if(test)
        ui->tabWidget->setCurrentIndex(2);




}*/
