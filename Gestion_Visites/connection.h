#ifndef CONNECTION_H
#define CONNECTION_H


#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>


class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createConnection();
    void closeConnection();
};

#endif // CONNECTION_H


