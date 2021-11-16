
#include "PDF.h"

QString currDate()
{
    QDate date = QDate::currentDate();
    return date.toString("dd.MM.yyyy");
}

void pdf(QString filename)
{
    QPdfWriter writer(filename);
    writer.setPageSize(QPagedPaintDevice::A4);
    writer.setPageMargins(QMargins(30, 30, 30, 30));

    QPainter Painter(&writer);
    Painter.setPen(Qt::black);
    Painter.setFont(QFont("Times", 10));

    QRect r = Painter.viewport();

    QString citydate = "Tunis, ";
    citydate += currDate();

    Painter.drawText(r, Qt::AlignRight, citydate);


    QString sender = "SMART ZOO\n";
    sender += "Random Street 12/314A\n";
    sender += "123-1232 City\n";

    Painter.drawText(r, Qt::AlignLeft, sender);



    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT ID_ANIMAL, TYPE, NUMERO_CAGE, NOURITURE, AGE, RECLAMATION FROM Animaux");
    QTableView tab;
    tab.setModel(model);
    Painter.scale(20,20);

    tab.render(&Painter);

    Painter.end();
}

QString info(QString rech)
{
    QFile animInfo("E:\\Downloads\\ProjetC++\\Project\\Info.txt");
    animInfo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(animInfo.isOpen())
    {
        QTextStream in(&animInfo);
        bool readEnabled = false;
        QString outputText, startToken = rech, endToken = "*";
        while(!in.atEnd())
        {
            QString getLine = in.readLine();
            if(getLine == endToken)
            {
                readEnabled = false;
            }
            if(readEnabled)
            {
                outputText.append(getLine +"\n");
            }
            if(getLine == startToken)
            {
                readEnabled = true;
            }
        }
        animInfo.flush();
        animInfo.close();
        return outputText;
    }
}

