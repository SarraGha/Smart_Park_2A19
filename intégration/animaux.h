#ifndef ANIMAUX_H
#define ANIMAUX_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <stdio.h>
#include <QObject>

class Animaux
{
public:
    Animaux();
    Animaux(int, QString, int, int, QString, QString);
    int getid();
    int getnumCage();
    int getAge();
    QString getType();
    QString getNouriture();
    QString getReclam();
    void setid(int);
    void setAge(int);
    void setnumCage(int);
    void setType(QString);
    void setNouriture(QString);
    void setReclam(QString);
    bool ajouterA();
    QSqlQueryModel * afficher();
    bool supprimerA();
    bool modifierA(int Col, int idS);
    QSqlQueryModel * rechercher(const QString rech);
    QSqlQueryModel * Afficher_repas();
    QSqlQueryModel * rechercher_R(const QString rech);
    bool ajouterR();
    bool supprimerR();

private:
    int id, numCage, Age;
    QString type, nouriture, reclam;

};

#endif // ANIMAUX_H
