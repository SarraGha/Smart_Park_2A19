#include "connexion.h"

connexion::connexion()
{

}

bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");//initialisation de l'attribut
db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données ODBC
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("201JFT4940a");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
//void connexion::createconnect(){db.close();} // close db

