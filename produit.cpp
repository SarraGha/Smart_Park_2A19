#include "produit.h"
#include "QString"

produit::produit()
{

}

produit::produit(int Id ,QString nom, QString Libelle , double prix,int nbr_E,int Idf)
{
    this->Id=Id;
    this->nom=nom;
    this->Libelle=Libelle;
    this->prix=prix;
    this->nbr_E=nbr_E;
    this->Idf=Idf;

}

bool produit::ajouter()
{
   QSqlQuery query;
  query.prepare("INSERT INTO PRODUIT (ID,NOM ,LIBELLE,PRIX,NBR_E,IDF)" "VALUES(:id,:nom,:Libelle,:prix,:nbr_e,:idf)");
  query.bindValue(":id",Id);
  query.bindValue(":nom", nom);
  query.bindValue(":libelle", Libelle);
  query.bindValue(":prix", prix);
  query.bindValue(":nbr_e", nbr_E);
  query.bindValue(":idf", Idf);

  return  query.exec();


}

bool produit::supprimer(int Id)
{
   QSqlQuery query;
   QString res=QString::number(Id);
   
  query.prepare("Delete from PRODUIT where ID = :id ");
   query.bindValue(":id",res);
   return query.exec();

}
QSqlQueryModel * produit::afficher()
{
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select * from PRODUIT ");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Libelle"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Nbr_Exp"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IdF"));
return model ;
}


bool produit::modifier(int id)
{   QSqlQuery query;
    query.prepare( "UPDATE Produit SET ID=:id,NOM=:nom,LIBELLE=:libelle,PRIX=:prix,NBR_E=:nbr_E,IDF=:IdF WHERE ID=:id;");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":libelle",Libelle);
    query.bindValue(":prix", prix);
    query.bindValue(":nbr_E",nbr_E);
    query.bindValue(":IdF", Idf);



 return query.exec();
}

