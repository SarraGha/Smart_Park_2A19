#include "mission.h"
#include <QtCore/QString>








mission::mission()
{
idmission=0;
type="";
lieu="";
}


mission::mission(int idmission ,QString type, QDate datee, QString lieu)
{
  this->idmission=idmission;
  this->type=type;
  this->datee=datee;
  this->lieu=lieu;
}



QString get_type();
QDate get_datee();
QString get_lieu();
int get_idmission();



QString mission::get_type(){return  type;}
QDate mission::get_datee(){return  datee;}
QString mission::get_lieu(){return  lieu;}
int mission::get_idmission(){return  idmission;}

bool mission::ajouter_2()
{
QSqlQuery query;
QString res= QString::number(idmission);
query.prepare("INSERT INTO mission (IDMISSION, TYPE, DATEE,LIEU) "
                    "VALUES (:idmission, :type, :datee, :lieu)");
query.bindValue(":idmission", res);
query.bindValue(":type", type);
query.bindValue(":datee", datee);
query.bindValue(":lieu", lieu);


return    query.exec();
}

QSqlQueryModel * mission::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from mission");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idmission"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("lieu"));
    return model;
}

bool mission::supprimer_2(int idd)
{
QSqlQuery query;
int res= int(idd);
query.prepare("Delete from mission where IDMISSION = :idmission ");
query.bindValue(":idmission", res);
return    query.exec();
}

bool mission::modifier_4(int idd)
{
    QSqlQuery query;
    int res= int(idd);
    query.prepare("UPDATE mission SET TYPE=:type,  DATEE=:datee, LIEU=:lieu WHERE IDMISSION=:idmission");
    query.bindValue(":idmission", res);
    query.bindValue(":type", type);
    query.bindValue(":datee", datee);
     query.bindValue(":lieu", lieu);


    return    query.exec();
}

QSqlQueryModel * mission::modifier_5(const QString &idmission)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from mission where(IDMISSION LIKE '"+idmission+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDMISSION"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("lieu"));
        return model;
}
