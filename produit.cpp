#include "produit.h"
#include "QString"

produit::produit()
{

}

produit::produit(int ID_PRODUITS ,QString NOM_PRODUIT, QString LIBELLE_PRODUIT , double PRIX,
                int NBRE_EXEMPLAIRE,int ID_FOURNISSEUR)
{
    this->ID_PRODUITS=ID_PRODUITS;//constructeur
    this->NOM_PRODUIT=NOM_PRODUIT;
    this->LIBELLE_PRODUIT=LIBELLE_PRODUIT;
    this->PRIX=PRIX;
    this->NBRE_EXEMPLAIRE=NBRE_EXEMPLAIRE;
    this->ID_FOURNISSEUR=ID_FOURNISSEUR;

}

bool produit::ajouter()
{
   QSqlQuery query;// requette sql
  query.prepare("INSERT INTO GS_PRODUITS (ID_PRODUITS,NOM_PRODUIT,LIBELLE_PRODUIT,PRIX,NBR_EXEMPLAIRE,ID_FOURNISSEUR)"
                "VALUES(:ID_PRODUITS,:NOM_PRODUIT ,:LIBELLE_PRODUIT,:PRIX,:NBRE_EXEMPLAIRE,:ID_FOURNISSEUR)");
  query.bindValue(0,ID_PRODUITS);        //prepare et variables temporaires (:)
  query.bindValue(1, NOM_PRODUIT);//val saisies dans lineEdit
  query.bindValue(2, LIBELLE_PRODUIT); //les attributs privés recevoient les valeurs reels
  query.bindValue(3, PRIX);
  query.bindValue(4, NBRE_EXEMPLAIRE);
  query.bindValue(5, ID_FOURNISSEUR);// remplacer les bindValue par des variables (mesure de securité)
//eviter sql injection // bindValue liaison nommée
  //addBindValue()marqueur nominatif
  return  query.exec(); //execution de la requete


}

bool produit::supprimer(int Id)     //
{
   QSqlQuery query;
   QString res=QString::number(Id);// conversion
   
  query.prepare("Delete from GS_PRODUITS where ID_PRODUITS = :id ");
   query.bindValue(":id",res);
   return query.exec();

}
QSqlQueryModel * produit::afficher()
{
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select * from GS_PRODUITS ");  //comme un tableau de données en ligne , on l affiche sur table view
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Libelle"));//set header data titre les colonnes
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Nbr_Exp"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IdF"));
return model ;
}


bool produit::modifier(int ID_PRODUITS)
{   QSqlQuery query;
    query.prepare( "UPDATE GS_PRODUITS SET ID_PRODUITS=:id,NOM_PRODUIT=:nom,LIBELLE_PRODUIT=:libelle,PRIX=:prix,NBR_EXEMPLAIRE=:nbr_E,ID_FOURNISSEUR=:IdF WHERE ID_PRODUITS=:id;");
    query.bindValue(":id", ID_PRODUITS);
    query.bindValue(":nom", NOM_PRODUIT);
    query.bindValue(":libelle",LIBELLE_PRODUIT);
    query.bindValue(":prix", PRIX);
    query.bindValue(":nbr_E",NBRE_EXEMPLAIRE);
    query.bindValue(":IdF", ID_FOURNISSEUR);



 return query.exec();
}


QSqlQueryModel * produit::TriNom(QString nom)//cls=ASC ou DESC
{
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select * from GS_PRODUITS ORDER BY NOM_PRODUIT "+nom);  //comme un tableau de données en ligne , on l affiche sur table view
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Libelle"));//set header data titre les colonnes
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Nbr_Exp"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IdF"));
return model ;
}


QSqlQueryModel * produit::TriPrix(QString nom)//cls=ASC ou DESC
{
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select * from GS_PRODUITS ORDER BY PRIX "+nom);  //comme un tableau de données en ligne , on l affiche sur table view
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Libelle"));//set header data titre les colonnes
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Nbr_Exp"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IdF"));
return model ;
}


QSqlQueryModel * produit::TriNbr_E(QString nom)//cls=ASC ou DESC
{
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select * from GS_PRODUITS ORDER BY NBR_EXEMPLAIRE "+nom);  //comme un tableau de données en ligne , on l affiche sur table view
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Libelle"));//set header data titre les colonnes
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Nbr_Exp"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IdF"));
return model ;
}






QSqlQueryModel * produit::Recherche(QString a)//cls=ASC ou DESC
{
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select * from GS_PRODUITS WHERE (ID_PRODUITS LIKE '%"+a+"%' OR NOM_PRODUIT LIKE '%"+a+"%' OR LIBELLE_PRODUIT LIKE '%"+a+"%' "
    "OR PRIX LIKE '%"+a+"%' OR NBR_EXEMPLAIRE LIKE '%"+ a +"%' OR ID_FOURNISSEUR LIKE '%"+a+"%' ) ");  //comme un tableau de données en ligne , on l affiche sur table view
 //ajouter a à la requette a l'aide de + // colonne =a
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Libelle"));//set header data titre les colonnes
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Nbr_Exp"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("IdF"));
return model ;

}


void produit::alerte(QString nom_produit)
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("Alerte produit grib yakml ","nbr dexmp mtaa lproduit "+nom_produit+" a9al ml seuil",QSystemTrayIcon::Information,15000);
}


QSqlQueryModel * produit::GetProduits_inf_a_seuil(int seuil)
{
QSqlQueryModel *model=new QSqlQueryModel();
QString res=QString::number(seuil);
model->setQuery("select * from GS_PRODUITS where NBR_EXEMPLAIRE <"+res);
return model ;
}


void produit::alerts()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("Alerte barcha produiyet ","barcha produiyet nbr ex mtaahom akal m seuil",QSystemTrayIcon::Information,15000);
}






