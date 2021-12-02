#ifndef PRODUIT_H
#define PRODUIT_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>

class produit
{
private :
    int ID_PRODUIT , NBRE_EXEMPLAIRE , ID_FOURNISSEUR;
    double PRIX ;
    QString NOM_PRODUIT, LIBELLE_PRODUIT ;

public:
    //constructeurs
    produit(){};
    produit(int,QString, QString , double,int,int);

    //les fonctionnalités de base
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * afficher () ; // afficher tableau de bd
    QSqlQueryModel * TriNom(QString) ;
    QSqlQueryModel * TriPrix(QString) ;
    QSqlQueryModel * TriNbr_E(QString) ;
    QSqlQueryModel * Recherche(QString) ;
    QSqlQueryModel * GetProduits_inf_a_seuil (int) ;//afficher tableau bd des nbre_Ex <seuil
    void alerte(QString); // alerte de 1 seul produit
    void alerts();//alerte de plusieurs produits

};

#endif // PRODUIT_H
