#include "modifier.h"
#include "ui_modifier.h"
#include"QMessageBox"

modifier::modifier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier)
{
    ui->setupUi(this);
}

modifier::~modifier()
{
    delete ui;
}
void modifier::setID_MAG(int ID_MAG){
QString ID_String=QString::number(ID_MAG);

   ui->idm->setText(ID_String);
}
void modifier::setID_LOC(int ID_LOC){
QString ID_String2=QString::number(ID_LOC);

   ui->idl->setText(ID_String2);
}
void modifier::setPRIX(int PRIX){
QString ID_String3=QString::number(PRIX);

   ui->prix->setText(ID_String3);
}
void modifier::setETAT(QString ETAT){


   ui->etat->setText(ETAT);
}
void modifier::setTYPE(QString TYPE){


   ui->type->setText(TYPE);
}



void modifier::on_modifier2_clicked()
{
    int ID_MAG=ui->idm->text().toInt();
    int ID_LOC=ui->idl->text().toInt();
    int PRIX=ui->prix->text().toInt();
    QString ETAT=ui->etat->text();
    QString TYPE=ui->type->text();

    magasin m(ID_MAG,ID_LOC,PRIX,ETAT,TYPE);
    bool test=m.modifier(ID_MAG);
    QMessageBox msgbox;

    if(test)
        msgbox.setText("Modification avec succes");
    else
        msgbox.setText("Echec de modification");
    msgbox.exec();
}
