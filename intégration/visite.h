#ifndef VISITE_H
#define VISITE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCore>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>


class Visite
{
    QString identifiantTicket;
    int prixTicket;
    QString identifiantVisiteur;
    int nombreVisites;
    QString dateVisite;
    QString abonnement;
    int idAnimal;

public:
    //Constructeurs
    Visite();
    Visite(QString, int, QString, int, QString, QString, int);

    //Getters
    QString get_identifiantTicket(){return identifiantTicket;};
    int get_prixTicket(){return prixTicket;};
    QString get_identifiantVisiteur(){return identifiantVisiteur;};
    int get_nombreVisites(){return nombreVisites;};
    QString get_dateVisite(){return dateVisite;};
    QString get_abonnement(){return abonnement;};
    int get_idAnimal(){return idAnimal;};

    //Setters
    void set_identifiantTicket(QString idT){identifiantTicket=idT;};
    void set_prixTicket(int prixT){prixTicket=prixT;};
    void set_identifiantVisiteur(QString idV){identifiantVisiteur=idV;};
    void set_nombreVisites(int nbrV){nombreVisites=nbrV;};
    void set_dateVisite(QString dateV){dateVisite=dateV;};
    void set_abonnement(QString ab){abonnement=ab;};
    void set_idAnimal(int idA){idAnimal=idA;};

    //CRUDs
    bool ajouter();
    bool supprimer(QString);
    bool modifier(QString);
    QSqlQueryModel * afficher();


    //Métiers
    QSqlQueryModel * rechercher(const QString &critere);
    QSqlQueryModel * trier(QString critere);
    void genererPDF(Visite V);
    int calculOffre(int prixTicket,int offre);


};

#endif // VISITE_H
