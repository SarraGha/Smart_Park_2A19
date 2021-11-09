#include "visite.h"


Visite::Visite()
{
    identifiantTicket="";
    prixTicket=0;
    identifiantVisiteur="";
    nombreVisites=0;
    dateVisite="";
    abonnement="";
}

Visite::Visite(QString identifiantTicket, int prixTicket, QString identifiantVisiteur, int nombreVisites, QString dateVisite, QString abonnement)
{
    this->identifiantTicket=identifiantTicket;
    this->prixTicket=prixTicket;
    this->identifiantVisiteur=identifiantVisiteur;
    this->nombreVisites=nombreVisites;
    this->dateVisite=dateVisite;
    this->abonnement=abonnement;
}

bool Visite::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO VISITES(IDENTIFIANTTICKET, PRIXTICKET, IDENTIFIANTVISITEUR, NOMBREVISITES, DATEVISITE, ABONNEMENT)"
                  "VALUES(:identifiantTicket, :prixTicket, :identifiantVisiteur, :nombreVisites, :dateVisite, :abonnement)");

    query.bindValue(":identifiantTicket", identifiantTicket);
    query.bindValue(":prixTicket", prixTicket);
    query.bindValue(":identifiantVisiteur", identifiantVisiteur);
    query.bindValue(":nombreVisites", nombreVisites);
    query.bindValue(":dateVisite", dateVisite);
    query.bindValue(":abonnement", abonnement);

    return query.exec();
}

bool Visite::supprimer(QString identifiantTicket)
{
    QSqlQuery query;

    query.prepare("DELETE FROM VISITES where identifiantTicket= :identifiantTicket");
    query.bindValue(":identifiantTicket", identifiantTicket);

    return query.exec();

}

bool Visite::modifier(QString identifiantTicket)
{
    QSqlQuery query;

    query.prepare("UPDATE VISITES SET prixTicket= :prixTicket, identifiantVisiteur= :identifiantVisiteur, nombreVisites= :nombreVisites, dateVisite= :dateVisite, abonnement= :abonnement where identifiantTicket= :identifiantTicket");

    query.bindValue(":identifiantTicket", identifiantTicket);
    query.bindValue(":prixTicket", prixTicket);
    query.bindValue(":identifiantVisiteur", identifiantVisiteur);
    query.bindValue(":nombreVisites", nombreVisites);
    query.bindValue(":dateVisite", dateVisite);
    query.bindValue(":abonnement", abonnement);

    return query.exec();


}

QSqlQueryModel * Visite::afficher()
{
    QSqlQueryModel*model = new QSqlQueryModel();
    model->setQuery("select * from VISITES");

    model->setHeaderData(0,Qt::Horizontal, QObject::tr("identifiantTicket"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("prixTicket"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("identifiantVisiteur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombreVisites"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("dateVisite"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("abonnement"));

    return model;
}

QSqlQueryModel * Visite::rechercher(const QString &critere)
{
    QSqlQueryModel*model = new QSqlQueryModel();

    model->setQuery("select * from VISITES where (identifiantTicket LIKE '"+critere+"%')");

    model->setHeaderData(0,Qt::Horizontal, QObject::tr("identifiantTicket"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("prixTicket"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("identifiantVisiteur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombreVisites"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("dateVisite"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("abonnement"));

    return model;
}

QSqlQueryModel * Visite::trier(QString critere)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;

    query->prepare(critere);
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("identifiantTicket"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("prixTicket"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("identifiantVisiteur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombreVisites"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("dateVisite"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("abonnement"));

    return model;
}

/*
void Visite::ouvrirPDF()
{
    ShellExecuteA(NULL,"open","doc.pdf",0,0,SW_NORMAL);
}
*/



