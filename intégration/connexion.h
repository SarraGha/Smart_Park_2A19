#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>


class Connexion
{
    QSqlDatabase db;

public:
    Connexion(){};
    bool createConnection();
    void closeConnection();
};

#endif // CONNEXION_H
