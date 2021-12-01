#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "produit.h"
#include <QtGui>
#include"QMessageBox"
#include <QDebug>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include "smtp.h"
#include<chrono>
#include<thread>
produit Ptmp;

MainWindow::MainWindow(QWidget *parent)//constructeur Fenetre
    : QMainWindow(parent) ,
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox_p->setValue(5);//par defaut
    refresh();
    //ui->tableView->setModel((Ptmp.afficher()));
    ui->lineEdit_Nom_p->setMaxLength(20);
    ui->lineEdit_Id_p->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_Idf_p->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_Prix_p->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_nbre_E_p->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_Prix_p->setMaxLength(8);
    ui->lineEdit_nbre_E_p->setMaxLength(2);
    int ret=A.connect_arduino();
        switch (ret) {
        case(0):qDebug()<<"arduino is available and connected to :"<<A.getarduino_port_name();
            break;
        case(1):qDebug()<<"arduino is available but not connected to :"<<A.getarduino_port_name();
            break;
        case(-1):qDebug()<<"arduino is not available ";
            break;
        }
            QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update()));
            qDebug()<<"données reçus d'arduino"<<A.read_from_arduino();
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
        Sleep (100);

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


void MainWindow::refresh()
{
    //triii
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

void MainWindow::on_lineEdit_4_p_textChanged(const QString &arg1)
{
     ui->tableView_p->setModel((Ptmp.Recherche(arg1)));
}
QT_CHARTS_USE_NAMESPACE

void MainWindow::on_pushButton_Stat_p_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from GS_PRODUITS where PRIX < 50 ");
       float salaire=model->rowCount();
       model->setQuery("select * from GS_PRODUITS where PRIX  between 50 and 200 ");
       float salairee=model->rowCount();
       model->setQuery("select * from GS_PRODUITS where PRIX > 200 ");
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
       {QPieSlice *slice = series->slices().at(0);
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

void MainWindow::on_pushButton_6_p_clicked()
{
    ui->stackedWidget_p->setCurrentIndex(0);
}

void MainWindow::on_pushButton_mail_p_clicked()
{
    ui->stackedWidget_p->setCurrentIndex(3);
}





void MainWindow::on_alerter_p_clicked()
{
    refresh();
}







