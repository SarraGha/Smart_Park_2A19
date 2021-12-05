
#include "PDF.h"

QString currDate()
{
    QDate date = QDate::currentDate();
    return date.toString("dd.MM.yyyy");
}

void pdf(QString filename)
{
    filename = QFileDialog::getSaveFileName(0, QString::fromUtf8("Générer Ticket PDF"), QCoreApplication::applicationDirPath(), "*.pdf");
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
    Painter.setFont(QFont("Calibri", 18, QFont::ExtraBold));
    Painter.drawText(3250,1200,"Liste des Animaux");
    QSqlQueryModel* model= new QSqlQueryModel();
    model->setQuery("SELECT ID_ANIMAL, TYPE, NUMERO_CAGE, NOURITURE, AGE, RECLAMATION FROM Animaux");
    Painter.setFont(QFont("Calibri", 12, QFont::Bold));
    QTableWidget tab;
    int i;
    int y = 2000;
    QString output;
    QSqlRecord row;
    for(i = 0, row= model->record(i); row.isNull(0) == 0; i++, row = model->record(i))
    {
        output = ("ID Animal : "+ QString::number(row.value(0).toInt())+ "/ Type Animal :"+ row.value(1).toString() +"/ Numero de cage :"+QString::number(row.value(2).toInt())+"/ Nouriture : "+row.value(3).toString()+"/ Age : "+QString::number(row.value(4).toInt())+" Ans");
        Painter.drawText(0,y, output);
        y += 500;
    }






    Painter.end();
}

QString info(QString rech)
{
    //QFile animInfo("C:/Users/omare/Downloads/ProjetC++/Project/Info.txt");
    //QFile animInfo("E:/Downloads/ProjetC++/Project/Info.txt");
    QFile animInfo(":/ressources/Info.txt");
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

