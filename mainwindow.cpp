#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"magasin.h"
#include<QMessageBox>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlRecord>
#include"modifier.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlQuery aez;
        aez.prepare("SELECT ID_MAG FROM MAG");
        aez.exec();
        aez.first();
        int groupID_MAG = aez.record().indexOf("ID_MAG");
        ui->comboBox->addItem(aez.value(0).toString());

        while (aez.next()) {
              ui->comboBox->addItem(aez.value(groupID_MAG).toString());

  }
        qDebug()<<"test";

        QSqlQuery aezr;
            aezr.prepare("SELECT ID_MAG FROM MAG");
            aezr.exec();
            aezr.first();
            int groupID_MAGc = aezr.record().indexOf("ID_MAG");
            ui->comboBox_2->addItem(aezr.value(0).toString());

            while (aezr.exec()) {
                  ui->comboBox_2->addItem(aezr.value(groupID_MAGc).toString());


      }
    }


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajout_clicked()
{
    int ID_MAG=ui->idm->text().toInt();
    int ID_LOC=ui->idl->text().toInt();
     int PRIX=ui->prix->text().toInt();
     QString TYPE=ui->type->text();
     QString ETAT=ui->etat->text();

     qDebug()<<ID_LOC;
     qDebug()<<ID_MAG;
     qDebug()<<PRIX;
     qDebug()<<TYPE;
     qDebug()<<ETAT;

     magasin m(ID_MAG,ID_LOC,PRIX,TYPE,ETAT);
     QMessageBox msg;
     bool test=m.ajout_mag();



     if(test)
     {
         QMessageBox::critical(nullptr, QObject::tr("Statut d'ajout"),
                     QObject::tr("id deja exist.\n"), QMessageBox::Cancel);

 }
     else if(ui->idm->text().isEmpty()){

         QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                     QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

     }
     else
        { QMessageBox::information(nullptr, QObject::tr("Statut d'ajout"),
                     QObject::tr("Ajout avec succes.\n"), QMessageBox::Cancel);}
}

void MainWindow::on_afficher_clicked()
{
    magasin m;
    QSqlQueryModel * modal=m.afficher();
    ui->tableView->setModel(modal);
}

void MainWindow::on_supprimer_clicked()
{
    magasin m;
   m.setID_MAG(ui->comboBox->currentText().toInt());
   bool test=m.supprimer(m.getID_MAG());
   if(!test)
   {
       QMessageBox::critical(nullptr, QObject::tr("Statut de suppression"),
                   QObject::tr("Erreur de suppression.\n"), QMessageBox::Cancel);

}
   else if(ui->comboBox->currentText().isEmpty()){

       QMessageBox::critical(nullptr, QObject::tr("EMPTY!"),
                   QObject::tr("ID Obligatoire.\n"), QMessageBox::Cancel);

   }
   else
       QMessageBox::information(nullptr, QObject::tr("Statut de suppression"),
                   QObject::tr("suppression avec succes.\n"), QMessageBox::Cancel);

                   ui->comboBox->clear();
                   QSqlQuery qry;
                       qry.prepare("SELECT ID_MAG FROM MAG");
                       qry.exec();
                       qry.first();
                       int groupID_MAG = qry.record().indexOf("ID_MAG");
                        ui->comboBox->addItem(qry.value(0).toString());
                       while (qry.next()) {
                             ui->comboBox->addItem(qry.value(groupID_MAG).toString());
                       }


}


void MainWindow::on_Modifier_clicked()
{
    modifier m;

    m.setID_MAG(ui->comboBox_2->currentText().toInt());
    QSqlQuery qry;
    int ID_MAG=ui->comboBox_2->currentText().toInt();
      QString ID_MAG_STRING= QString::number(ID_MAG);
      qry.prepare("SELECT * from MAG where ID_MAG='"+ID_MAG_STRING+"'");
       if (qry.exec())
          {
           while (qry.exec()) {
              int ac=qry.value(1).toString().toInt();
              QString ac_STRING= QString::number(ac);
            m.setID_LOC(ac);
            int sa=qry.value(2).toString().toInt();
            QString sa_STRING= QString::number(sa);
          m.setPRIX(sa);
          QString ev=qry.value(3).toString();
            m.setETAT(ev);
            QString ty=qry.value(4).toString();
              m.setTYPE(ty);

              ui->comboBox_2->clear();
              QSqlQuery qry;
                  qry.prepare("SELECT ID_MAG FROM MAG");
                  qry.exec();
                  qry.first();
                  int groupID_MAG = qry.record().indexOf("ID_MAG");
                   ui->comboBox_2->addItem(qry.value(0).toString());
                  while (qry.next()) {
                        ui->comboBox_2->addItem(qry.value(groupID_MAG).toString());
             bool test=m.exec();
             m.close();


 }
 }
}}
