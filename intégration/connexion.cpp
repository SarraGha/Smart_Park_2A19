#include "connexion.h"

bool Connexion::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;

    //db.setDatabaseName("Source_Projet2A");
    //db.setUserName("sarra");
    //db.setPassword("sarra");
    db.setDatabaseName("Smart_Zoo");
    db.setUserName("omar");
    db.setPassword("17072002");

    if(db.open())
        test=true;

    return test;
}

void Connexion::closeConnection()
{
    db.close();
}
