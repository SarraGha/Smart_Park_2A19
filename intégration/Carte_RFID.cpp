#include"Carte_RFID.h"

int checkCard(QString UID, QSerialPort *Arduino)
{
    int x;
    QSqlQueryModel* model= new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT Nom, Prenom FROM Employe WHERE (IDENTIFIANTE LIKE :UID)");
    query.bindValue(":UID", UID);
    query.exec();
    model->setQuery(query);
    //model->setQuery("SELECT Nom, Prenom FROM Employe WHERE IDENTIFIANTE LIKE '211.33.134.25'");

    QSqlRecord row = model->record(0);
    x = QString::compare(row.value(0).toString(), "", Qt::CaseInsensitive);
    if(x == 0)
    {
        Arduino->write("0");
        return 1;
    }
    else
    {
        QString output = row.value(0).toString() +" "+ row.value(1).toString();

        qDebug()<< output;
        Arduino->write(output.toStdString().c_str());
        return 0;
    }
}
