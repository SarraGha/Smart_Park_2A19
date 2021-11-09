#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "produit.h"
#include <QtGui>
#include"QMessageBox"
produit Ptmp;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) ,
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->tableView->setModel((Ptmp.afficher()));
    refresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::refresh()
{
    QString cls;
    if (ui->croissant->isChecked()) cls="ASC";
            else if  (ui->decroissant->isChecked()) cls="DESC";
    switch (ui->tri->currentIndex()){
    case 0:
        ui->tableView->setModel((Ptmp.TriParNom(cls)));
        break;
    case 1:
        ui->tableView->setModel((Ptmp.TriParPrix(cls)));
        break;
     case 2:
        ui->tableView->setModel((Ptmp.TriParNbr_E(cls)));
        break;

    }
}



void MainWindow::on_pushButton_Ajouter_clicked()
{
    int Id= ui ->lineEdit_Id->text().toInt();//conversion QString to int
    QString Nom= ui ->lineEdit_Nom->text();
    QString Libelle= ui ->comboBox_Libelle->currentText();
    double Prix= ui ->lineEdit_Prix->text().toDouble();
    int Nbr_E= ui ->lineEdit_nbre_E->text().toInt();
    int Idf= ui ->lineEdit_Idf->text().toInt();
    produit p(Id, Nom , Libelle , Prix , Nbr_E , Idf);//instancier l'objet

    bool test=p.ajouter();//insertion de l'objet instancié dans la table

        if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("success"),
                    QObject::tr("produit ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel((Ptmp.afficher()));


}
    else
        QMessageBox::critical(nullptr, QObject::tr("fail"),
                    QObject::tr("probleme d'ajout.\n"
                                "quitter."), QMessageBox::Cancel);

}




void MainWindow::on_pushButton_supprimer_clicked()
{
    int id = ui->lineEdit_Id->text().toInt();
    bool test=Ptmp.supprimer(id);
    if (test)
    {
    QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("Suppression effectuée\n"
                        "Click Cancel non to exit.") , QMessageBox :: Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
    ui->tableView->setModel((Ptmp.afficher()));


}





void MainWindow::on_pushButton_modifier_clicked()
{
    int Id= ui ->lineEdit_Id->text().toInt();//conversion QString to int
    QString Nom= ui ->lineEdit_Nom->text();
    QString Libelle= ui ->comboBox_Libelle->currentText();
    double Prix= ui ->lineEdit_Prix->text().toDouble();
    int Nbr_E= ui ->lineEdit_nbre_E->text().toInt();
    int Idf= ui ->lineEdit_Idf->text().toInt();
    produit p(Id, Nom , Libelle , Prix , Nbr_E , Idf);
    bool test=p.modifier(Id);
    if (test)
    {
    QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("Modification effectuée\n"
                        "Click Cancel non to exit.") , QMessageBox :: Cancel);

    ui->tableView->setModel((Ptmp.afficher()));


    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("Modification non effectuée.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
    ui->tableView->setModel((Ptmp.afficher()));

}

