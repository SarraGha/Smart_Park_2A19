#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //initialisations
    ui->setupUi(this);
    ui->tabWidget->setTabEnabled(1, false);
    ui->tableView_BD_V->setModel(Vte.afficher());
    setWindowTitle("Smart Zoo");
    setWindowIcon(QIcon("C:/Users/MSI/Desktop/2021-2022/semestre 1/projet c++/travail perso/intégration/gestionVisites/ressources/logo_App_1.png"));


    //contraintes de saisie
    ui->dateEdit_dateVisite_V->setDate(QDate::currentDate());
    ui->lineEdit_PrixTicket_V->setValidator(new QIntValidator(0, 99, this));
    ui->lineEdit_PrixTicket_V->setMaxLength(2);
    ui->lineEdit_IdentifiantTicket_V->setMaxLength(8);
    ui->lineEdit_IdentifiantVisiteur_V->setMaxLength(8);
    ui->lineEdit_rechercher_V->setMaxLength(8);
    ui->lineEdit_IdentifiantAnimal_V->setValidator(new QIntValidator(0, 99, this));


    //camera
    Camera=new QCamera(this);
    CameraViewfinder = new QCameraViewfinder(this);
    CameraImageCapture = new QCameraImageCapture(Camera, this);
    Layout = new QVBoxLayout;
    //Layout = new QVBoxLayout(CameraViewfinder);

    menuOptions = new QMenu("Options", this);
    demarrerCamera = new QAction("Démarrer", this);
    stopperCamera = new QAction("Pause", this);
    captureCamera =new QAction("Capturer", this);

    menuOptions->addActions({demarrerCamera, stopperCamera, captureCamera});
    ui->optionsCamera_V->setMenu(menuOptions);

    Camera->setViewfinder(CameraViewfinder);
    Layout->addWidget(CameraViewfinder);
    Layout->setMargin(0);
    ui->scrollArea_Camera_V->setLayout(Layout);

    //connection des options
    connect(demarrerCamera, &QAction::triggered, [&](){
        Camera->start();
    });

    connect(stopperCamera, &QAction::triggered, [&](){
        Camera->stop();
    });

    connect(captureCamera, &QAction::triggered, [&](){
         auto filename = QFileDialog::getSaveFileName(this, "Capturer", "/", "Imagen (*ipg; *jpeg)");
         if(filename.isEmpty()){
             return ;
         }
        CameraImageCapture->setCaptureDestination(
                    QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600, 1200);
        CameraImageCapture->setEncodingSettings(imageEncoderSettings);
        Camera->setCaptureMode(QCamera::CaptureStillImage);
        Camera->start();
        Camera->searchAndLock();

        CameraImageCapture->capture(filename);
        Camera->unlock();
    });



    //Arduino
    int ret=A.connect_arduino();
    switch (ret) {
    case(0):qDebug()<<"arduino is available and connected to :"<<A.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available but not connected to :"<<A.getarduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available ";
        break;
    }
        /*QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update()));
        qDebug()<<"données reçus d'arduino"<<A.read_from_arduino();*/




}

void MainWindow::update()
{
        data=A.read_from_arduino();
        qDebug()<<"données reçus d'arduino"<<data;

    if(data=="1")
    {
        QMessageBox msgBoxArduino;
        msgBoxArduino.setText("Attention!La porte d'une cage est ouverte!");
        msgBoxArduino.setInformativeText("Voulez-vous la fermer?");
        QPushButton *bouttonOui =msgBoxArduino.addButton(tr("Fermer"), QMessageBox::AcceptRole);
        QPushButton *bouttonNon =msgBoxArduino.addButton(tr("Non"), QMessageBox::RejectRole);
        msgBoxArduino.addButton(bouttonOui, QMessageBox::AcceptRole);
        msgBoxArduino.addButton(bouttonNon, QMessageBox::RejectRole);
        msgBoxArduino.setIcon(QMessageBox::Warning);

        msgBoxArduino.exec();
        Sleep(100);

        if(msgBoxArduino.clickedButton()==bouttonOui){
            A.write_to_arduino("1");
            QMessageBox::information(this, QObject::tr("Appuyer sur cancel pour quitter."),
                                     QObject::tr("Porte fermée Avec Succès!"), QMessageBox::Cancel);
        }
        else if(msgBoxArduino.clickedButton()==bouttonNon){
            QMessageBox::warning(this, QObject::tr("Appuyer sur cancel pour quitter."),
                                     QObject::tr("Porte ouverte!"), QMessageBox::Cancel);
        }


        /*int ret=msgBoxArduino.exec();
        switch (ret) {
        case QMessageBox::Yes:
            A.write_to_arduino("1");
            break;
        case QMessageBox::No:
            A.write_to_arduino("0");
            break;
        }*/
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_acceder_clicked()
{

    /*  QString userName = ui->identifiantAccueil->text();
    QString password = ui->motDePasseAccueil->text();
    QSqlQuery query;

    query.prepare("SELECT identifiant FROM Comptes where identifiant= :userName and mdp= :password");
    query.bindValue(":userName", userName);
    query.bindValue(":password", password);

    bool test = query.exec();

    if(test)
        ui->tabWidget->setCurrentIndex(2);
    */

    QString userName = ui->identifiantAccueil->text();
    QString password = ui->motDePasseAccueil->text();
    if(userName=="admin" && password=="admin")
    {
        QMessageBox::information(this, "Accès", "Accès autorisé");
        ui->tabWidget->setCurrentIndex(1);
        ui->tabWidget->setTabEnabled(1, true);
        ui->tabWidget->setTabEnabled(2, true);
    }
    else if(userName!="admin")
    {
        QMessageBox::warning(this, "Accès non autorisé!", "Vérifiez le nom d'utilisateur.");
    }
    else if(userName=="admin" && password!="admin")
    {
        QMessageBox::warning(this, "Accès non autorisé!", "nom d'utilisateur ou mot de passe incorrecte.");
    }
}

void MainWindow::on_pushButton_Ajouter_V_clicked()
{
    QString identifiantTicket = ui->lineEdit_IdentifiantTicket_V->text();
    int prixTicket = ui->lineEdit_PrixTicket_V->text().toInt();
    QString identifiantVisiteur = ui->lineEdit_IdentifiantVisiteur_V->text();
    int nombreVisites = ui->spinBox_nbrVisites_V->text().toInt();
    QString dateVisite = ui->dateEdit_dateVisite_V->date().toString();
    QString abonnement = ui->comboBox_abonnement_V->currentText();
    int idAnimal = ui->lineEdit_IdentifiantAnimal_V->text().toInt();

    qDebug()<<identifiantTicket;
    qDebug()<<prixTicket;
    qDebug()<<identifiantVisiteur;
    qDebug()<<nombreVisites;
    qDebug()<<dateVisite;
    qDebug()<<abonnement;
    qDebug()<<idAnimal;

    bool test_idTicket=true;
    bool test_idVisiteur=true;

    //test idTicket
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

    //test idVisiteur
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
        Visite V(identifiantTicket, prixTicket, identifiantVisiteur, nombreVisites, dateVisite, abonnement, idAnimal);

        bool test = V.ajouter();

        if(test)
        {
            //actualisation de l'affichage
            ui->tableView_BD_V->setModel(Vte.afficher());

            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Ajout effectué.\n""Cliquez sur 'Cancel' pour quitter."), QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Ajout non effectué.\n""Vérifiez l'Identifiant Ticket."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_Modifier_V_clicked()
{
    QString identifiantTicket = ui->lineEdit_IdentifiantTicket_V->text();
    int prixTicket = ui->lineEdit_PrixTicket_V->text().toInt();
    QString identifiantVisiteur = ui->lineEdit_IdentifiantVisiteur_V->text();
    int nombreVisites = ui->spinBox_nbrVisites_V->text().toInt();
    QString dateVisite = ui->dateEdit_dateVisite_V->date().toString();
    QString abonnement = ui->comboBox_abonnement_V->currentText();
    int idAnimal = ui->lineEdit_IdentifiantAnimal_V->text().toInt();

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
        Visite V(identifiantTicket, prixTicket, identifiantVisiteur, nombreVisites, dateVisite, abonnement, idAnimal);

        bool test= V.modifier(identifiantTicket);

        if(test)
        {
            //actualisation de l'affichage
            ui->tableView_BD_V->setModel(Vte.afficher());

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

void MainWindow::on_pushButton_Supprimer_V_clicked()
{
    int reponse = QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer cette Visite (ou ces Visites) ?", QMessageBox ::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        bool test ;

        QString idT ;
        QModelIndex index ;
        QModelIndexList selection = ui->tableView_BD_V->selectionModel()->selectedRows();

        //parcourir les index. Utile particulièrement pour une sélection multiple
        //selection.count() permet de parcourir les données sélectionnés
        for (int i =0;i<selection.count();i++)
        {
            index=selection.at(i);


            //QVariant().toString = Retourne le QVariant sous forme d'un QString
            //index.row() car l'index est de type QModelIndex et on doit connaître la ligne exacte du tab en tant que int

            idT=QVariant(ui->tableView_BD_V->model()->index(index.row(),0).data()).toString();

            test = Vte.supprimer(idT) ;

                if (test)
                {
                    //actualisation de l'affichage
                    ui->tableView_BD_V->setModel(Vte.afficher());

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

void MainWindow::on_lineEdit_rechercher_V_textChanged(const QString &critere)
{
    ui->tableView_BD_V->setModel(Vte.rechercher(critere));
}

void MainWindow::on_comboBox_trier_V_currentIndexChanged(int index)
{
    QString critere;
    if(index==2)
    {
        critere="select * from Visites order by prixTicket DESC";
        ui->tableView_BD_V->setModel(Vte.trier(critere));
    }

    if(index==1)
    {
        critere="select * from Visites order by prixTicket ASC";
        ui->tableView_BD_V->setModel(Vte.trier(critere));
    }

    if(index==0)
    {
        ui->tableView_BD_V->setModel(Vte.afficher());
    }
}

void MainWindow::on_comboBox_Remise_V_currentIndexChanged(int index)
{
    QString critere;
    int prixTicket = ui->lineEdit_PrixTicket_V->text().toInt();

    if(index==4)
    {
        prixTicket=prixTicket*0.5;
        QString prixTicketString = QString::number(prixTicket);
        ui->lineEdit_PrixTicket_V->setText(prixTicketString);
    }
    if(index==3)
    {
        prixTicket=prixTicket*0.7;
        QString prixTicketString = QString::number(prixTicket);
        ui->lineEdit_PrixTicket_V->setText(prixTicketString);
    }

    if(index==2)
    {
        prixTicket=prixTicket*0.8;
        QString prixTicketString = QString::number(prixTicket);
        ui->lineEdit_PrixTicket_V->setText(prixTicketString);
    }

    if(index==1)
    {
        prixTicket=prixTicket*0.9;
        QString prixTicketString = QString::number(prixTicket);
        ui->lineEdit_PrixTicket_V->setText(prixTicketString);
    }
}

void MainWindow::on_genererPDF_V_clicked()
{
    QString identifiantTicket = ui->lineEdit_IdentifiantTicket_V->text();
    int prixTicket = ui->lineEdit_PrixTicket_V->text().toInt();
    QString identifiantVisiteur = ui->lineEdit_IdentifiantVisiteur_V->text();
    int nombreVisites = ui->spinBox_nbrVisites_V->text().toInt();
    QString dateVisite = ui->dateEdit_dateVisite_V->date().toString();
    QString abonnement = ui->comboBox_abonnement_V->currentText();
    int idAnimal = ui->lineEdit_IdentifiantAnimal_V->text().toInt();



    Visite V(identifiantTicket, prixTicket, identifiantVisiteur, nombreVisites, dateVisite, abonnement, idAnimal);

    V.genererPDF(V);
}

void MainWindow::on_genererEXCEL_V_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
    qDebug()<<fileName;

        if (fileName.isEmpty())
            return;
        ExportExcelObject obj(fileName, "mydata", ui->tableView_BD_V);
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


        //QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}


