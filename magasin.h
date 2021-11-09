#ifndef MAGASIN_H
#define MAGASIN_H
#include<QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QSqlQueryModel>
class magasin
{
public:
    magasin();

    magasin(int,int,int,QString,QString);

    int getID_MAG();
    int getID_LOC();
    int getPRIX();
    QString getETAT();
    QString getTYPE();
    void setID_MAG(int);
    void setID_LOC(int);
    void setPRIX(int);
    void setETAT(QString);
    void setTYPE(QString);
    bool ajout_mag();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier (int);


private:
    int ID_MAG,ID_LOC;
    int PRIX;
    QString ETAT,TYPE;
};

#endif // MAGASIN_H
