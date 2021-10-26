#include "visite.h"

//Constructeurs
Visite::Visite()
{
    identifiantTicket="";
    prixTicket=0;
    identifiantVisiteur="";
    nbrVisites=0;
    abonnement=false;
    dateVisite="";

    /*dateVisite.jour=0;
    dateVisite.mois=0;
    dateVisite.annee=0;*/
}

Visite::Visite(QString identifiantTicket, float prixTicket, QString identifiantVisiteur, bool abonnement, QString dateVisite)
{
    this->identifiantTicket=identifiantTicket;
    this->prixTicket=prixTicket;
    this->identifiantVisiteur=identifiantVisiteur;
    this->abonnement=abonnement;
    this->dateVisite=dateVisite;
}




//CRUDs
bool Visite::ajouter()
{
   QSqlQuery query;
   //QString res = QString::number(identifiantTicket);

   query.prepare("insert into visite(identifiantTicket, prixTicket, identifiantVisiteur, nbrVisites, abonnement, dateVisite)""values(:identifiantTicket, :prixTicket, :identifiantVisiteur, :nbrVisites, :abonnement, :dateVisite)");

   //création des variables liées
   query.bindValue(":identifiantTicket", identifiantTicket);
   query.bindValue(":prixTicket", prixTicket);
   query.bindValue(":identifiantVisiteur", identifiantVisiteur);
   query.bindValue(":nbrVisites", nbrVisites);
   query.bindValue(":abonnement", abonnement);
   query.bindValue(":dateVisite", dateVisite);

}

bool Visite::supprimer(QString idT) //Suppression selon l'identifiant de ticket passe parametre
{

}

bool Visite::modifier(QString idT) //Modifier selon l'identifiant de ticket passe en parametre
{

}

void Visite::afficher()
{

}



void Visite::trier(QString ordre)
{

}
bool Visite::rechercher(QString critere)
{

}
