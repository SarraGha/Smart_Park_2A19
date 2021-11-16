#ifndef PRODUIT_H
#define PRODUIT_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>

class produit
{
private :
    int ID_PRODUITS , NBRE_EXEMPLAIRE , ID_FOURNISSEUR;
    double PRIX ;
    QString NOM_PRODUIT, LIBELLE_PRODUIT ;

public:
    //constructeurs
    produit(int,QString, QString , double,int,int);
    produit();
    //les fonctionnalités de base
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * afficher () ;
    QSqlQueryModel * TriNom(QString) ;
    QSqlQueryModel * TriPrix(QString) ;
    QSqlQueryModel * TriNbr_E(QString) ;
    QSqlQueryModel * Recherche(QString) ;
    QSqlQueryModel * GetProduits_inf_a_seuil (int) ;
    void alerte(QString);
    void alerts();

};

#endif // PRODUIT_H
