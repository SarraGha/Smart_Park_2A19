#include "connection.h"

Connection::Connection(){}

bool Connection::createConnection()

{
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données ODBC
db.setUserName("sarra");//inserer nom de l'utilisateur
db.setPassword("sarra");//inserer mot de passe de cet utilisateur

if (db.open())
{
   test=true;

}


    return  test;
}

void Connection::closeConnection(){db.close();}
