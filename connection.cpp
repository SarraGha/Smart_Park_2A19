#include "connection.h"

Connection::Connection()
{

}

bool Connection::createConnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Smart_Zoo");//inserer le nom de la source de données ODBC
db.setUserName("omar");//inserer nom de l'utilisateur
db.setPassword("17072002");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

void Connection::closeConnection(){db.close();}
