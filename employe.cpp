#include "employe.h"
#include "connexion.h"
employe::employe()
{
id_emp=0;
firstname="";
lastname="";
grade="";
salaire="";
}
employe::employe(int id_emp,QString firstname,QString lastname,QString grade,QString salaire)
{
  this->id_emp=id_emp;
  this->firstname=firstname;
  this->lastname=lastname;
  this->grade=grade;
  this->salaire = salaire;
}
int employe::get_id_emp(){return  id_emp;}
QString employe::get_firstname(){return  firstname;}
QString employe::get_lastname(){return lastname;}
QString employe::get_grade(){return grade;}
QString employe::get_salaire(){return salaire;}

bool employe::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id_emp);
    query.prepare("INSERT INTO EMPLOYE (id_emp, firstname, lastname, grade,salaire) "
                        "VALUES (:id_emp, :firstname, :lastname, :grade,:salaire)");
    query.bindValue(":id_emp", res);
    query.bindValue(":firstname", firstname);
    query.bindValue(":lastname", lastname);
    query.bindValue(":grade", grade);
    query.bindValue(":salaire", salaire);
    return    query.exec();
}

bool employe::modifier()

{
    QSqlQuery query;
    QString res= QString::number(id_emp);
    query.prepare("UPDATE EMPLOYE SET firstname='"+firstname+"',lastname='"+lastname+"',grade='"+grade+"',salaire='"+salaire+"' where id_emp='"+res+"'  ;");
    query.bindValue(":id_emp",id_emp);
    query.bindValue(":firstname", firstname);
    query.bindValue(":lastname", lastname);
    query.bindValue(":grade", grade);
    query.bindValue(":salaire", salaire);
    return    query.exec();
}

QSqlQueryModel * employe::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from EMPLOYE order by code asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_emp "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("firstname "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("lastname"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("grade"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));

    return model;
}


bool employe::supprimer(int id_emp)
{
QSqlQuery query;
QString res= QString::number(id_emp);
query.prepare("Delete from EMPLOYE where id_emp = :id_emp ");
query.bindValue(":id_emp", res);
return    query.exec();
}

QSqlQueryModel *employe::sort_employe()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  employe ORDER BY id_emp");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("id_emp"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr(" firstname"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("lastname"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("grade"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("salaire"));




    return model;
}
QSqlQueryModel * employe::rechercher(int id_emp)
{
QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
QString res=QString::number(id_emp);  //SQLQUERY ONLY TAKES STRING ENTRIES.
query.prepare("SELECT * from employe where id_emp= :id_emp");
query.bindValue(":id_emp",res);

    query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal,QObject::tr("id_emp"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr(" firstname"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("lastname"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("grade"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("salaire"));
return model ;
}
