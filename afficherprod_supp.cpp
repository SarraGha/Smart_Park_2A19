#include "afficherprod_supp.h"
#include "ui_afficherprod_supp.h"

AfficherProd_Supp::AfficherProd_Supp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AfficherProd_Supp)
{
    ui->setupUi(this);
}

AfficherProd_Supp::~AfficherProd_Supp()
{
    delete ui;
}
