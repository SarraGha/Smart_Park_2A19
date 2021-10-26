#ifndef VISITE_H
#define VISITE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


/*typedef struct
{
    int jour;
    int mois;
    int annee;
}Date;*/


class Visite
{

    QString identifiantTicket;
    float prixTicket;
    QString identifiantVisiteur;
    int nbrVisites;
    bool abonnement;
    QString dateVisite;

public:
    //Constructeurs
    Visite();
    Visite(QString identifiantTicket, float prixTicket, QString identifiantVisiteur, bool abonnement, QString dateVisite);

    //Getters
    QString get_identifiantTicket(){return identifiantTicket;};
    float get_prixTicket (float prixTicket){return prixTicket;};
    QString get_identifiantVisiteur(){return identifiantVisiteur;};
    int get_nbrVisites(){return nbrVisites;};
    bool get_abonnement (){return abonnement;};
    QString get_dateVisite(){return dateVisite;};

    //Setters
    void set_identifiantTicket(QString idT){identifiantTicket=idT;};
    void set_prixTicket (float prixT){prixTicket=prixT;};
    void set_identifiantVisiteur(QString idV){ identifiantVisiteur=idV;};
    void set_nbrVisites(int nbrV){nbrVisites=nbrV;};
    void set_abonnement (bool ab){abonnement=ab;};
    void set_dateVisite(QString dateV){dateVisite=dateV;};


    //CRUDs
    bool ajouter();
    bool supprimer(QString idT); //Suppression selon l'identifiant de ticket passe parametre
    bool modifier(QString idT); //Modifier selon l'identifiant de ticket passe en parametre
    void afficher();
    void trier(QString ordre);
    bool rechercher(QString critere);
};

#endif // VISITE_H
