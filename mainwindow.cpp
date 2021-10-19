#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include"dialog.h"
//test coonexion
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Id->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_Idf->setValidator(new QIntValidator(0,999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
Produit p;
p.setId(ui->lineEdit_Id->text());
p.setnom(ui->lineEdit_nom->text());
p.settype(ui->lineEdit_type->text());
p.setprix(ui->lineEdit_prix->text());
p.setnbE(ui->lineEdit_nbE->text());
p.setIdf(ui->lineEdit_Idf->text());

Dialog d ;
d.setproduit(p);
d.exec();
}
