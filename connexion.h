#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connexion
{  
    QSqlDatabase db; //attribut de la classe connexion

public:
    connexion();

    bool createconnect();
};

#endif // CONNEXION_H
