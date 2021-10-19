#include "recherche_produits.h"
#include "ui_recherche_produits.h"

Recherche_Produits::Recherche_Produits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recherche_Produits)
{
    ui->setupUi(this);
}

Recherche_Produits::~Recherche_Produits()
{
    delete ui;
}
