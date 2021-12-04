#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts/QChartView>
#include <QtGui>
#include <QSystemTrayIcon>
#include <QtCharts/QAbstractSeries>
#include <QPieSeries>
#include <QPieSlice>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setTabEnabled(2, false);
    ui->tabWidget->setTabEnabled(3, false);
    ui->tabWidget->setTabEnabled(4, false);
    ui->tabWidget->setTabEnabled(5, false);
    ui->tabWidget->setTabEnabled(6, false);

    /************************************Visite************************************/
    //initialisations Visite 
    ui->tableView_BD_V->setModel(Vte.afficher());
    setWindowTitle("Smart Zoo");
    setWindowIcon(QIcon(":/ressources/logo_App_1.png"));

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
    //connexion des options
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




    /************************************Produit************************************/
    ui->spinBox_p->setValue(5);//par defaut
    refresh();
    ui->tableView_p->setModel((Ptmp.afficher()));
    ui->lineEdit_Nom_p->setMaxLength(20);
    ui->lineEdit_Id_p->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_Idf_p->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_Prix_p->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_nbre_E_p->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_Prix_p->setMaxLength(8);
    ui->lineEdit_nbre_E_p->setMaxLength(2);






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




/************************************Arduino************************************/
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
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



/************************************************************************Visite************************************************************************/
void MainWindow::on_pushButton_acceder_clicked()
{
    QString userName = ui->identifiantAccueil->text();
    QString password = ui->motDePasseAccueil->text();
    if(userName=="admin" && password=="admin")
    {
        QMessageBox::information(this, "Accès", "Accès autorisé");
        ui->tabWidget->setCurrentIndex(1);
        ui->tabWidget->setTabEnabled(1, true);
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


/*****ajouter*****/
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

/*****modifier*****/
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

/*****supprimer*****/
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
}

/*****rechercher*****/
void MainWindow::on_lineEdit_rechercher_V_textChanged(const QString &critere)
{
    ui->tableView_BD_V->setModel(Vte.rechercher(critere));
}

/*****tri*****/
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

/*****remise*****/
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

/*****pdf*****/
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

/*****excel*****/
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

void MainWindow::on_acces_V_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
    ui->tabWidget->setTabEnabled(2, true);
}

void MainWindow::on_pushButton_Retour_V_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setTabEnabled(2, false);
}

void MainWindow::on_acces_P_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
    ui->tabWidget->setTabEnabled(3, true);
}

void MainWindow::on_pushButton_Retour_P_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setTabEnabled(3, false);
}


void MainWindow::on_acces_A_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
    ui->tabWidget->setTabEnabled(4, true);
}

void MainWindow::on_pushButton_Retour_A_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setTabEnabled(4, false);
}

void MainWindow::on_acces_E_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
    ui->tabWidget->setTabEnabled(5, true);
}

void MainWindow::on_pushButton_Retour_E_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setTabEnabled(5, false);
}

void MainWindow::on_acces_M_clicked()
{
    ui->tabWidget->setCurrentIndex(6);
    ui->tabWidget->setTabEnabled(6, true);
}

void MainWindow::on_pushButton_Retour_M_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setTabEnabled(6, false);
}

void MainWindow::on_pushButton_retourS_p_clicked()
{
    ui->stackedWidget_p->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retourA_p_clicked()
{
    ui->stackedWidget_p->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retourM_p_clicked()
{
    ui->stackedWidget_p->setCurrentIndex(0);
}

/************************************************************************Produit************************************************************************/
/*****refresh*****/
void MainWindow::refresh()
{
    //tri
    QString a;
    if (ui->croissant_p->isChecked()) a="ASC";
    else if (ui->decroissant_p->isChecked()) a="DESC";


    switch (ui->comboBox_Tri_p->currentIndex()) {
    case 0:
        ui->tableView_p->setModel((Ptmp.TriNom(a)));
        break;
    case 1:
        ui->tableView_p->setModel((Ptmp.TriNbr_E(a)));
        break;
    case 2:
        ui->tableView_p->setModel((Ptmp.TriPrix(a)));
        break;
    default:
    ui->tableView_p->setModel((Ptmp.afficher()));
        break;
    }

    //systeme d'alerte
    int seuil = ui->spinBox_p->value();
    QSqlQueryModel * model= new QSqlQueryModel();
    model = Ptmp.GetProduits_inf_a_seuil(seuil);
    if (model->rowCount() == 1){
        QString nomProduit = model->data(model->index(0,1)).toString();
        Ptmp.alerte(nomProduit);
    }else if (model->rowCount() > 1)
        Ptmp.alerts();
   // ui->treeView->setModel(Ptmp.afficher());

}

/*****ajouter*****/
void MainWindow::on_pushButton_Ajouter_p_clicked()
{
    int Id= ui ->lineEdit_Id_p->text().toInt();//conversion QString to int
    QString Nom= ui ->lineEdit_Nom_p->text();
    QString Libelle= ui ->comboBox_Libelle_p->currentText();
    double Prix= ui ->lineEdit_Prix_p->text().toDouble();//constructeur
    int Nbr_E= ui ->lineEdit_nbre_E_p->text().toInt();
    int Idf= ui ->lineEdit_Idf_p->text().toInt();
    produit p(Id, Nom , Libelle , Prix ,Nbr_E , Idf);//instancier l'objet

    bool test=p.ajouter();
        if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("success"),
                    QObject::tr("produit ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        //ui->tableView->setModel((Ptmp.afficher())); //refresh
        refresh();

}
    else
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr("probleme d'ajout.\n"
                                "quitter."), QMessageBox::Cancel);
}

/*****supprimer*****/
void MainWindow::on_pushButton_supprimer_p_clicked()
{
    int id = ui->lineEdit_Id_p->text().toInt();
    bool test=Ptmp.supprimer(id);//appel de la methode supp()
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Suppression effectuée\n"
                            "Click Cancel non to exit.") , QMessageBox :: Cancel);
       //ui->tableView->setModel((Ptmp.afficher()));//refrerch
       refresh();
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                  QObject::tr("Suppression non effectuée.\n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
        ui->tableView_p->setModel((Ptmp.afficher()));
}

/*****modifier*****/
void MainWindow::on_pushButton_modifier_p_clicked()
{
    int ID_PRODUITS= ui ->lineEdit_Id_p->text().toInt();//conversion QString to int
    QString NOM_PRODUIT= ui ->lineEdit_Nom_p->text();
    QString LIBELLE_PRODUIT= ui ->comboBox_Libelle_p->currentText();
    double PRIX= ui ->lineEdit_Prix_p->text().toDouble();
    int NBRE_EXEMPLAIRE= ui->lineEdit_nbre_E_p->text().toInt();
    int ID_FOURNISSEUR= ui->lineEdit_Idf_p->text().toInt();
    produit p(ID_PRODUITS, NOM_PRODUIT , LIBELLE_PRODUIT , PRIX, NBRE_EXEMPLAIRE ,ID_FOURNISSEUR);
    bool test=p.modifier(ID_PRODUITS);//appel a la methode modifier
    if (test)
{
QMessageBox::information(nullptr,QObject::tr("OK"),
        QObject::tr("Modification effectuée\n"
                    "Click Cancel non to exit.") , QMessageBox :: Cancel);

//ui->tableView->setModel((Ptmp.afficher()));
refresh();

}
else
    QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                          QObject::tr("Modification non effectuée.\n"
                                      "Click Cancel to exit."),QMessageBox::Cancel);
ui->tableView_p->setModel((Ptmp.afficher()));
}

/*****tris*****/
void MainWindow::on_comboBox_Tri_p_currentIndexChanged(const QString &arg1)
{
    refresh();
}

void MainWindow::on_croissant_p_clicked()
{
    refresh();
}

void MainWindow::on_decroissant_p_clicked()
{
    refresh();
}

/*****rechercher*****/
void MainWindow::on_lineEdit_rechercher_p_textChanged(const QString &arg1)
{
    ui->tableView_p->setModel((Ptmp.Recherche(arg1)));
}

QT_CHARTS_USE_NAMESPACE

void MainWindow::on_pushButton_Stat_p_clicked()
{

    //ui->stackedWidget_2->setCurrentIndex(1);
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from PRODUITS where PRIX < 50 ");
       float salaire=model->rowCount();
       model->setQuery("select * from PRODUITS where PRIX  between 50 and 200 ");
       float salairee=model->rowCount();
       model->setQuery("select * from PRODUITS where PRIX > 200 ");
       float salaireee=model->rowCount();
       float total=salaire+salairee+salaireee;

       QString a=QString("moins de 50 DT . "+QString::number((salaire*100)/total,'f',2)+"%" );
       QString b=QString("entre 50 et 200 DT.  "+QString::number((salairee*100)/total,'f',2)+"%" );
       QString c=QString("plus de 200 DT."+QString::number((salaireee*100)/total,'f',2)+"%" );

       QPieSeries *series = new QPieSeries();
       series->append(a,salaire);
       series->append(b,salairee);
       series->append(c,salaireee);
       if (salaire!=0)
       {
           QPieSlice *slice = series->slices().at(0);
           slice->setLabelVisible();
           slice->setPen(QPen());}
       if ( salairee!=0)
       {
           // Add label, explode and define brush for 2nd slice
           QPieSlice *slice1 = series->slices().at(1);
           //slice1->setExploded();
           slice1->setLabelVisible();
       }
       if(salaireee!=0)
       {
           // Add labels to rest of slices
           QPieSlice *slice2 = series->slices().at(2);
           //slice1->setExploded();
           slice2->setLabelVisible();
       }
       // Create the chart widget
       QChart *chart = new QChart();
       // Add data to chart with title and hide legend
       chart->addSeries(series); // widget
       chart->setTitle("Produits par Prix :Nombre Des Produits "+ QString::number(total));
       chart->legend()->hide();
       // Used to display the chart
       QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
       chartView->setRenderHint(QPainter::Antialiasing);
       chartView->resize(1000,500);
       chartView->show();
}


void MainWindow::on_pushButton_alertes_p_clicked()
{
    ui->stackedWidget_p->setCurrentIndex(2);
}

void MainWindow::on_alerter_p_clicked()
{
    refresh();
}

void MainWindow::on_pushButton_mail_p_clicked()
{
    ui->stackedWidget_p->setCurrentIndex(3);
}


void MainWindow::on_send_p_clicked()
{
    smtp = new Smtp("yassproduits@gmail.com" , "yass11042001", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->message_mail->toPlainText();

    smtp->sendMail("yass_test",ui->a_mail->text(),ui->objet_mail->text(),msg);

    QMessageBox::information(nullptr, QObject::tr("SENT"),
                             QObject::tr("Email Sended Successfully.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}


