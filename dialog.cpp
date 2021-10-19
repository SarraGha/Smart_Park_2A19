#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setproduit(Produit p);
{
ui->lineEdit_IdD->setText(p.get_Id());
ui->lineEdit_nomD->setText(p.get_nom());
ui->lineEdit_typeD->setText(p.get_type());
ui->lineEdit_prixD->setText(p.get_prix());
ui->lineEdit_nbED->setText(p.get_nbE());
ui->lineEdit_IdfD->setText(p.get_Idf());
}
