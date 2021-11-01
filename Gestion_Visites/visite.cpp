#include "visite.h"

//Constructeurs
Visite::Visite()
{
    identifiantTicket="";
    prixTicket=0;
    identifiantVisiteur="";
    nbrVisites=0;
    abonnement=0;
    dateVisite="";

    /*dateVisite.jour=0;
    dateVisite.mois=0;
    dateVisite.annee=0;*/
}

Visite::Visite(QString identifiantTicket, float prixTicket, QString identifiantVisiteur, int nbrVisites, int abonnement, QString dateVisite)
{
    this->identifiantTicket=identifiantTicket;
    this->prixTicket=prixTicket;
    this->identifiantVisiteur=identifiantVisiteur;
    this->nbrVisites=nbrVisites;
    this->abonnement=abonnement;
    this->dateVisite=dateVisite;
}




//CRUDs
bool Visite::ajouter()
{
   QSqlQuery query;
   //QString res = QString::number(identifiantTicket);

   query.prepare("insert into Visite(identifiantTicket, prixTicket, identifiantVisiteur, nbrVisites, abonnement, dateVisite)"
                 "values(:identifiantTicket, :prixTicket, :identifiantVisiteur, :nbrVisites, :abonnement, :dateVisite)");

   //création des variables liées
   query.bindValue(":identifiantTicket", identifiantTicket);
   query.bindValue(":prixTicket", prixTicket);
   query.bindValue(":identifiantVisiteur", identifiantVisiteur);
   query.bindValue(":nbrVisites", nbrVisites);
   query.bindValue(":abonnement", abonnement);
   query.bindValue(":dateVisite", dateVisite);

   return query.exec();

};


bool Visite::supprimer(int idT) //Suppression selon l'identifiant de ticket passe parametre
{
    QSqlQuery query;
    QString res=QString::number(idT);

    query.prepare("Delete from visite where identifiantTicket= :idT");
    query.bindValue(":idT", res);

    return query.exec();

};


bool Visite::modifier(QString idT) //Modifier selon l'identifiant de ticket passe en parametre
{
    QSqlQuery query;

    query.prepare("UPDATE Visite SET identifiantTicket=:idT, prixTicket=:prixTicket, identifiantVisiteur=:identifiantVisiteur, nbrVisites=:nbrVisites, abonnement=:abonnement, dateVisite=:dateVisite");
    query.bindValue(":identifiantTicket", idT);
    query.bindValue(":prixTicket", prixTicket);
    query.bindValue(":identifiantVisiteur", identifiantVisiteur);
    query.bindValue(":nbrVisites", nbrVisites);
    query.bindValue(":abonnement", abonnement);
    query.bindValue(":dateVisite", dateVisite);

    return query.exec();
}

QSqlQueryModel * Visite::afficher()
{
    QSqlQueryModel*model = new QSqlQueryModel();
    model->setQuery("select * from VISITES");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("identifiantTicket"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("prixTicket"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("identifiantVisiteur"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("nbrVisites"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("dateVisite"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("abonnement"));
    return model;
}



void Visite::trier(QString ordre)
{

}
bool Visite::rechercher(QString critere)
{

}
