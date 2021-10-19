#include "afficher_mail.h"
#include "ui_afficher_mail.h"

Afficher_mail::Afficher_mail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Afficher_mail)
{
    ui->setupUi(this);
}

Afficher_mail::~Afficher_mail()
{
    delete ui;
}
