#include "animaux.h"

Animaux::Animaux()
{
    id = 0; numCage = 0; Age = 0;
}

Animaux::Animaux( int id, QString Type, int numCage, int Age, QString Nouriture, QString Reclam)
{
    this->id = id;
    this->type = Type;
    this->numCage = numCage;
    this->Age = Age;
    this->nouriture = Nouriture;
    this->reclam = Reclam;

}
int Animaux::getid()
{
    return id;
}
int Animaux::getnumCage(){return numCage;}
int Animaux::getAge(){return Age;}
QString Animaux::getType(){return type;}
QString Animaux::getNouriture(){return nouriture;}
QString Animaux::getReclam(){return reclam;}
void Animaux::setid(int id){this->id=id;}
void Animaux::setAge(int Age){this->Age=Age;}
void Animaux::setnumCage(int numCage){this->numCage=numCage;}
void Animaux::setType(QString type){this->type=type;}
void Animaux::setNouriture(QString nouriture){this->nouriture=nouriture;}
void Animaux::setReclam(QString reclam){this->reclam=reclam;}
bool Animaux::ajouterA()
{
    QSqlQuery query;
    query.prepare("insert into ANIMAUX (type, numero_cage, nouriture, Age)""values( :type, :numero_cage, :nouriture, :age)");
    query.bindValue(":type", type);
    query.bindValue(":numero_cage", numCage);
    query.bindValue(":nouriture", nouriture);
    query.bindValue(":age", Age);
    return query.exec();
}
QSqlQueryModel * Animaux::afficher()
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT ID_ANIMAL, TYPE, NUMERO_CAGE, NOURITURE, AGE, RECLAMATION FROM Animaux");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Type Animal"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("N°Cage"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Nouriture"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Reclamation"));
    return model;
}
bool Animaux::supprimerA()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Animaux WHERE ID_ANIMAL = :id");
    query.bindValue(":id", id);
    return query.exec();

}
bool Animaux::modifierA(int Col, int idS)
{
    QSqlQuery query;
    switch(Col)
    {
    case 0:
        query.prepare("UPDATE Animaux SET ID_ANIMAL = :edit WHERE ID_ANIMAL = :idS");
        query.bindValue(":edit", id);
        query.bindValue(":idS", idS);
        qDebug()<< "id" << id;
        break;
    case 1:
        query.prepare("UPDATE Animaux SET Type = :edit WHERE ID_ANIMAL = :idS");
        query.bindValue(":edit", type);
        query.bindValue(":idS", idS);
        qDebug()<< "type" << type;
        break;
    case 2:
        query.prepare("UPDATE Animaux SET NUMERO_CAGE = :edit WHERE ID_ANIMAL = :idS");
        query.bindValue(":edit", numCage);
        query.bindValue(":idS", idS);
        qDebug()<< "numCage" << numCage;
        break;
    case 3:
        query.prepare("UPDATE Animaux SET NOURITURE = :edit WHERE ID_ANIMAL = :idS");
        query.bindValue(":edit", nouriture);
        query.bindValue(":idS", idS);
        qDebug()<< "nouriture" << nouriture;
        break;
    case 4:
        query.prepare("UPDATE Animaux SET AGE = :edit WHERE ID_ANIMAL = :idS");
        query.bindValue(":edit", Age);
        query.bindValue(":idS", idS);
        qDebug()<< "Age" << Age << idS;
        break;
    case 5:
        query.prepare("UPDATE Animaux SET RECLAMATION = :edit WHERE ID_ANIMAL = :idS");
        query.bindValue(":edit", reclam);
        query.bindValue(":idS", idS);
        qDebug()<< "reclam" << reclam ;
        break;
    }
    return query.exec();
}

QSqlQueryModel * Animaux::rechercher(const QString rech)
{
    QSqlQueryModel* model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_ANIMAL, TYPE, NUMERO_CAGE, NOURITURE, AGE, RECLAMATION FROM Animaux WHERE (TYPE like '%"+rech+"%')");
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Type Animal"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("N°Cage"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Nouriture"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Reclamation"));
    return model;
}
QSqlQueryModel * Animaux::Afficher_repas()
{
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT Nouriture.ID_Meal, Animaux.Nouriture, Nouriture.TEMPS, Nouriture.Animal FROM Nouriture INNER JOIN Animaux ON Animaux.id_animal=Nouriture.Animal order by TEMPS DESC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID Repas"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nouriture"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Temps du repas"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Animal concérné"));

    return model;
}

QSqlQueryModel * Animaux::rechercher_R(const QString rech)
{
    QSqlQueryModel* model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT Nouriture.ID_Meal, Animaux.Nouriture, Nouriture.TEMPS, Nouriture.Animal FROM Nouriture INNER JOIN Animaux ON Animaux.id_animal=Nouriture.Animal WHERE (Animal like '"+rech+"%') order by TEMPS DESC");
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID Repas"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nouriture"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Temps du repas"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Animal concérné"));
    return model;
}

bool Animaux::ajouterR()
{
    QSqlQuery query;
    query.prepare("INSERT into Nouriture (Animal) VALUES (:id);");
    query.bindValue(":id", id);
    return query.exec();
}

bool Animaux::supprimerR()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Nouriture WHERE ID_MEAL = :id");
    query.bindValue(":id", id);
    return query.exec();
}
