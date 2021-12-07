#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QDateTime>
#include <QPainter>
#include <QPdfWriter>
#include <QUrl>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_employes->setModel(tmpemploye.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id_emp = ui->idemp->text().toInt();
           QString firstname= ui->first->text();
           QString lastname= ui->last->text();
           QString grade= ui->grade->text();
           QString salaire= ui->sallaire->text();
             employe p(id_emp,firstname,lastname,grade,salaire);
         bool test=p.ajouter();
         if(test)
       {
       QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                         QObject::tr("Ajoute success.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_employes->setModel(tmpemploye.afficher());
       }
         else
             QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tab_employes_activated(const QModelIndex &index)
{
    QString val = ui->tab_employes->model()->data(index).toString() ;
       QSqlQuery qry;
       qry.prepare(" SELECT * from EMPLOYE where id_emp = '"+val+"'");
             int id_emp = ui->idemp->text().toInt();
              QString firstname= ui->first->text();
              QString lastname= ui->last->text();
              QString grade= ui->grade->text();
              QString salaire= ui->sallaire->text();
       if (qry.exec())
       {
           while (qry.next()) {
              ui->idemp->setText(qry.value(0).toString()) ;
               ui->first->setText(qry.value(0).toString()) ;
               ui->last->setText(qry.value(1).toString()) ;
               ui->grade->setText(qry.value(2).toString()) ;
               ui->sallaire->setText(qry.value(3).toString()) ;
              ui->tab_employes->setModel(tmpemploye.afficher());
           }
      }
}

void MainWindow::on_pb_modifier_clicked()
{
    int id_emp = ui->idemp->text().toInt();
           QString firstname= ui->first->text();
           QString lastname= ui->last->text();
           QString grade= ui->grade->text();
           QString salaire= ui->sallaire->text();
            employe p(id_emp,firstname,lastname,grade,salaire);
  bool test=p.modifier();
  if(test)
{
QMessageBox::information(nullptr, QObject::tr("modifier un EMPLOYE"),
                  QObject::tr("EMPLOYE modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un EMPLOYE"),
                  QObject::tr("Erreur !.\n" "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tab_employes->setModel(tmpemploye.afficher());
}

void MainWindow::on_pb_supprimer_clicked()
{
    int id_emp = ui->idemp->text().toInt();
    bool test=tmpemploye.supprimer(id_emp);
    if (test)
    {ui->tab_employes->setModel(tmpemploye.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimer un EMPLOYE"),
                          QObject::tr("EMPLOYE supprimé.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        }
          else
              QMessageBox::critical(nullptr, QObject::tr("Supprimer un EMPLOYE"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_employes->setModel(tmpemploye.afficher());

}



void MainWindow::on_pushButton_clicked()
{

    QDateTime datecreation = date.currentDateTime();
        QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;

           QPdfWriter pdf("C:/PDFemploye.pdf");
           QPainter painter(&pdf);
          int i = 4000;


               painter.setPen(Qt::blue);
               painter.setFont(QFont("Arial", 30));
               painter.drawText(1100,1200,"Liste Des EMPLOYE");
               painter.setPen(Qt::black);
               painter.setFont(QFont("Arial", 15));
               painter.drawText(1100,2000,afficheDC);
               painter.drawRect(100,100,7300,2600);
               painter.drawRect(0,3000,9600,500);
               painter.setFont(QFont("Arial", 9));
               painter.drawText(200,3300,"ID emolye");
               painter.drawText(1300,3300,"nom emolye");
               painter.drawText(2200,3300,"prenom emolye");
                painter.drawText(3200,3300,"grade ");
                 painter.drawText(4500,3300,"salaire ");

               QSqlQuery query;
               query.prepare("select * from EMPLOYE ");
               query.exec();
               while (query.next())
               {

                   painter.drawText(200,i,query.value(0).toString());
                   painter.drawText(1300,i,query.value(1).toString());
                   painter.drawText(2200,i,query.value(2).toString());
                   painter.drawText(3200,i,query.value(3).toString());
                   painter.drawText(4500,i,query.value(4).toString());
                   painter.drawText(7700,i,query.value(5).toString());

                  i = i + 500;


               }
               int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);



                   if (reponse == QMessageBox::Yes)
                   {
                       service.openUrl(QUrl("C:/"));
                       painter.end();
                   }
                   if (reponse == QMessageBox::No)
                   {
                        painter.end();
                   }

}


void MainWindow::on_recherchee_2_clicked()
{
    int id_emp=ui->lineRech->text().toInt() ;
         ui->tab_employes->setModel(tmpemploye.afficher());
        QMessageBox::information(nullptr, QObject::tr("succes"),
                    QObject::tr(" affiche  dans le tableau !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    {
        if(index==1)
              {
                   ui->tab_employes->setModel(tmpemploye.sort_employe());
              }else
                  ui->tab_employes->setModel(tmpemploye.sort_employe());
    }
}

void MainWindow::on_label_2_linkActivated(const QString &link)
{

}

void MainWindow::on_comboBox_activated(const QString &arg1)
{

}


