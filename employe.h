#ifndef EMPLOYE_H
#define EMPLOYE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QTimer>
#include<QComboBox>


class employe
{
public:
    employe();
    employe(int,QString,QString,QString,QString);
    int get_id_emp();
    QString get_firstname();
    QString get_lastname();
    QString get_grade();
    QString get_salaire();

    bool ajouter();
    bool modifier();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * sort_employe();
    QSqlQueryModel * rechercher(int id_emp);
private:
    int id_emp;
    QString firstname,lastname,grade,salaire;

};

#endif // EMPLOYE_H
