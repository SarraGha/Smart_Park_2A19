#include "magasin.h"
#include <QVariant>
magasin::magasin()
{ 
    ID_MAG=0;ID_LOC=0;TYPE="";ETAT="";PRIX=0;
}
magasin::magasin(int ID_MAG,int ID_LOC,int PRIX,QString ETAT,QString TYPE)
{
    this->ID_MAG=ID_MAG;
    this->ID_LOC=ID_LOC;
    this->PRIX=PRIX;
    this->ETAT=ETAT;
    this->TYPE=TYPE;

}
int magasin::getID_MAG(){return ID_MAG;}
int magasin::getID_LOC(){return ID_LOC;}
int magasin::getPRIX(){return PRIX;}
QString magasin::getETAT(){return ETAT;}
QString magasin::getTYPE(){return TYPE;}

void magasin::setID_MAG(int ID_MAG){this->ID_MAG=ID_MAG;}
void magasin::setID_LOC(int ID_LOC){this->ID_LOC=ID_LOC;}
void magasin::setPRIX(int PRIX){this->PRIX=PRIX;}
void magasin::setETAT(QString ETAT){this->ETAT=ETAT;}
void magasin::setTYPE(QString TYPE){this->TYPE=TYPE;}

bool magasin::ajout_mag(){
    bool test=false;
    QSqlQuery query;

  query.prepare("insert into MAG(ID_MAG ,ID_LOC ,PRIX ,ETAT ,TYPE ) values (:ID_MAG ,:ID_LOC ,:PRIX ,:ETAT ,:TYPE)");
    query.bindValue(":ID_MAG",ID_MAG);
    query.bindValue(":ID_LOC",ID_LOC);
    query.bindValue(":PRIX",PRIX);
    query.bindValue(":ETAT",ETAT);
    query.bindValue(":TYPE",TYPE);


    query.exec();

return test;
}

QSqlQueryModel *  magasin::afficher(){
     QSqlQuery query;
     QSqlQueryModel *model = new QSqlQueryModel;
     model->setQuery("select * from MAG");
     return model;



};
bool magasin::supprimer(int){

    QSqlQuery query;
          query.prepare("Delete from MAG where ID_MAG=:ID_MAG");
          query.bindValue(0, ID_MAG);

         return query.exec();

}
bool magasin::modifier(int ID_MAG)
{
    QSqlQuery query;
    query.prepare("UPDATE MAG set ID_LOC=:ID_LOC,PRIX=:PRIX,ETAT=:ETAT,TYPE=:TYPE where ID_MAG=:ID_MAG ");
    query.bindValue(":ID_MAG",ID_MAG);
    query.bindValue(":ID_LOC",ID_LOC);
    query.bindValue(":PRIX",PRIX);
    query.bindValue(":ETAT",ETAT);
    query.bindValue(":TYPE",TYPE);
    return query.exec();

}
