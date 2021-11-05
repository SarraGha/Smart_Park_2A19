#ifndef VISITE_H
#define VISITE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Visite
{
    QString identifiantTicket;
    int prixTicket;
    QString identifiantVisiteur;
    int nombreVisites;
    QString dateVisite;
    QString abonnement;

public:
    //Constructeurs
    Visite();
    Visite(QString, int, QString, int, QString, QString);

    //Getters
    QString get_identifiantTicket(){return identifiantTicket;};
    float get_prixTicket(){return prixTicket;};
    QString get_identifiantVisiteur(){return identifiantVisiteur;};
    int get_nombreVisites(){return nombreVisites;};
    QString get_dateVisite(){return dateVisite;};
    QString get_abonnement(){return abonnement;};

    //Setters
    void set_identifiantTicket(QString idT){identifiantTicket=idT;};
    void set_prixTicket(float prixT){prixTicket=prixT;};
    void set_identifiantVisiteur(QString idV){identifiantVisiteur=idV;};
    void set_nombreVisites(int nbrV){nombreVisites=nbrV;};
    void set_dateVisite(QString dateV){dateVisite=dateV;};
    void set_abonnement(QString ab){abonnement=ab;};

    //CRUDs
    bool ajouter();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel* afficher();
    bool rechercher(QString critere);
    void trier(QString ordre);
};

#endif // VISITE_H
