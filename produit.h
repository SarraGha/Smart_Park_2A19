#ifndef PRODUIT_H
#define PRODUIT_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class produit
{
private :
    int Id , nbr_E, Idf;
    double prix ;
    QString nom , Libelle;

public:
    produit(int,QString, QString , double,int,int);
    produit();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * afficher () ;
    void modifier();

};

#endif // PRODUIT_H
