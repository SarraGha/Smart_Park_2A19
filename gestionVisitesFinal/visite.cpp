#include "visite.h"

Visite::Visite()
{
    identifiantTicket="";
    prixTicket=0;
    identifiantVisiteur="";
    nombreVisites=0;
    dateVisite="";
    abonnement="";
    idAnimal=0;
}

Visite::Visite(QString identifiantTicket, int prixTicket, QString identifiantVisiteur, int nombreVisites, QString dateVisite, QString abonnement, int idAnimal)
{
    this->identifiantTicket=identifiantTicket;
    this->prixTicket=prixTicket;
    this->identifiantVisiteur=identifiantVisiteur;
    this->nombreVisites=nombreVisites;
    this->dateVisite=dateVisite;
    this->abonnement=abonnement;
    this->idAnimal=idAnimal;
}

bool Visite::ajouter()
{
    QSqlQuery query;

    if(idAnimal==0)
    {
        query.prepare("INSERT INTO VISITES(IDENTIFIANTTICKET, PRIXTICKET, IDENTIFIANTVISITEUR, NOMBREVISITES, DATEVISITE, ABONNEMENT)"
                      "VALUES(:identifiantTicket, :prixTicket, :identifiantVisiteur, :nombreVisites, :dateVisite, :abonnement)");
        query.bindValue(":identifiantTicket", identifiantTicket);
        query.bindValue(":prixTicket", prixTicket);
        query.bindValue(":identifiantVisiteur", identifiantVisiteur);
        query.bindValue(":nombreVisites", nombreVisites);
        query.bindValue(":dateVisite", dateVisite);
        query.bindValue(":abonnement", abonnement);
    }
    else
    {
        query.prepare("INSERT INTO VISITES(IDENTIFIANTTICKET, PRIXTICKET, IDENTIFIANTVISITEUR, NOMBREVISITES, DATEVISITE, ABONNEMENT, ID_ANIMAL_FK1)"
                      "VALUES(:identifiantTicket, :prixTicket, :identifiantVisiteur, :nombreVisites, :dateVisite, :abonnement, :IdAnimal)");

        query.bindValue(":identifiantTicket", identifiantTicket);
        query.bindValue(":prixTicket", prixTicket);
        query.bindValue(":identifiantVisiteur", identifiantVisiteur);
        query.bindValue(":nombreVisites", nombreVisites);
        query.bindValue(":dateVisite", dateVisite);
        query.bindValue(":abonnement", abonnement);
        query.bindValue(":IdAnimal", idAnimal);
    }

    return query.exec();
}

bool Visite::supprimer(QString identifiantTicket)
{
    QSqlQuery query;

    query.prepare("DELETE FROM VISITES where identifiantTicket= :identifiantTicket");
    query.bindValue(":identifiantTicket", identifiantTicket);

    return query.exec();

}

bool Visite::modifier(QString identifiantTicket)
{
    QSqlQuery query;

   /* query.prepare("UPDATE VISITES SET prixTicket= :prixTicket, identifiantVisiteur= :identifiantVisiteur, nombreVisites= :nombreVisites, dateVisite= :dateVisite, abonnement= :abonnement where identifiantTicket= :identifiantTicket");

    query.bindValue(":identifiantTicket", identifiantTicket);
    query.bindValue(":prixTicket", prixTicket);
    query.bindValue(":identifiantVisiteur", identifiantVisiteur);
    query.bindValue(":nombreVisites", nombreVisites);
    query.bindValue(":dateVisite", dateVisite);
    query.bindValue(":abonnement", abonnement);
*/
    if(idAnimal==0)
    {
        query.prepare("UPDATE VISITES SET prixTicket= :prixTicket, identifiantVisiteur= :identifiantVisiteur, nombreVisites= :nombreVisites, dateVisite= :dateVisite, abonnement= :abonnement where identifiantTicket= :identifiantTicket");

        query.bindValue(":identifiantTicket", identifiantTicket);
        query.bindValue(":prixTicket", prixTicket);
        query.bindValue(":identifiantVisiteur", identifiantVisiteur);
        query.bindValue(":nombreVisites", nombreVisites);
        query.bindValue(":dateVisite", dateVisite);
        query.bindValue(":abonnement", abonnement);
    }
    else
    {
        query.prepare("UPDATE VISITES SET prixTicket= :prixTicket, identifiantVisiteur= :identifiantVisiteur, nombreVisites= :nombreVisites, dateVisite= :dateVisite, abonnement= :abonnement, ID_ANIMAL_FK1= :idAnimal where identifiantTicket= :identifiantTicket");

        query.bindValue(":identifiantTicket", identifiantTicket);
        query.bindValue(":prixTicket", prixTicket);
        query.bindValue(":identifiantVisiteur", identifiantVisiteur);
        query.bindValue(":nombreVisites", nombreVisites);
        query.bindValue(":dateVisite", dateVisite);
        query.bindValue(":abonnement", abonnement);
        query.bindValue(":IdAnimal", idAnimal);
    }
    return query.exec();


}

QSqlQueryModel * Visite::afficher()
{
    QSqlQueryModel*model = new QSqlQueryModel();
    model->setQuery("select * from VISITES");

    model->setHeaderData(0,Qt::Horizontal, QObject::tr("identifiantTicket"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("prixTicket"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("identifiantVisiteur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombreVisites"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("dateVisite"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("abonnement"));

    return model;
}

QSqlQueryModel * Visite::rechercher(const QString &critere)
{
    QSqlQueryModel*model = new QSqlQueryModel();

    model->setQuery("select * from VISITES where (identifiantTicket LIKE '"+critere+"%')");

    model->setHeaderData(0,Qt::Horizontal, QObject::tr("identifiantTicket"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("prixTicket"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("identifiantVisiteur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombreVisites"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("dateVisite"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("abonnement"));

    return model;
}

QSqlQueryModel * Visite::trier(QString critere)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;

    query->prepare(critere);
    query->exec();

    model->setQuery(*query);
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("identifiantTicket"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("prixTicket"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("identifiantVisiteur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombreVisites"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("dateVisite"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("abonnement"));

    return model;
}

void Visite::genererPDF(Visite V)
{
    /*
    QString nomFichier = QFileDialog::getSaveFileName(0, QString::fromUtf8("Générer PDF"), QCoreApplication::applicationDirPath(), "*.pdf");

        int id(20);
        if (!nomFichier.isEmpty())
        {
            if (QFileInfo(nomFichier).suffix().isEmpty())
                nomFichier.append(".pdf");

            QPrinter printer(QPrinter::HighResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(nomFichier);
            printer.setOrientation(QPrinter::Portrait);
            printer.setPaperSize(QPrinter::A4);
            printer.setPageSize(QPrinter::A4);
            printer.setPageMargins(15,15,15,15,QPrinter::Millimeter);

            qDebug() << "Page px :" << printer.pageRect() << printer.paperRect();
            qDebug() << "Page mm :" << printer.pageRect(QPrinter::Millimeter) << printer.paperRect(QPrinter::Millimeter);
            qreal left, top, right, bottom;
            printer.getPageMargins(&left, &top, &right, &bottom, QPrinter::DevicePixel);
            qDebug() << "Marges px :" << left << top << right << bottom;
            printer.getPageMargins(&left, &top, &right, &bottom, QPrinter::Millimeter);
            qDebug() << "Marges mm :" << left << top << right << bottom;

            QPainter painter(&printer);


                painter.drawText(0, printer.pageRect().y()*2, QString::fromUtf8("TICKET"));
                painter.drawText(1, printer.pageRect().y()*3, QString::fromUtf8("IDENTIFIANT TICKET:"));
                painter.drawText(3, printer.pageRect().y()*4, QString::fromUtf8("PRIX TICKET:"));
                painter.drawText(4, printer.pageRect().y()*5, QString::fromUtf8("IDENTIFIANT VISITEUR"));
        }
*/


    QString nomFichier = QFileDialog::getSaveFileName(0, QString::fromUtf8("Générer Ticket PDF"), QCoreApplication::applicationDirPath(), "*.pdf");
    QPdfWriter writer(nomFichier);
    writer.setPageSize(QPagedPaintDevice::A4);
    writer.setPageMargins(QMargins(75, 75, 75, 75));
    QPainter Painter(&writer);
    QRect r = Painter.viewport();
    //logo
    Painter.drawPixmap(QRect(70,70,2000,708),QPixmap("C:/Users/MSI/Desktop/2021-2022/semestre 1/projet c++/1x/logo_fondBlanc_App.png"));

    //date + adresse + email + telephone
    Painter.setPen(Qt::black);
    Painter.setFont(QFont("Calibri Light", 10));
    QString date = "Tunis, ";
    date += V.dateVisite;
    date+= "\n\n Adresse : 18, rue de l'Usine \n ZI Aéroport Charguia II 2035 Ariana";
    date+="\n\nTel : +216 53.100.100";
    Painter.drawText(r, Qt::AlignRight, date);

    //titre
    Painter.setPen(Qt::black);
    Painter.setFont(QFont("Calibri", 30, QFont::ExtraBold));
    Painter.drawText(r, Qt::AlignHCenter,"\n\n\nTICKET");


    //contenu ticket
    Painter.setPen(Qt::black);
    Painter.setFont(QFont("Calibri Light", 13, QFont::Bold));
    Painter.drawText(0,3500, "Identifiant Ticket : ");
    Painter.drawText(0,3800, "Prix Ticket : ");
    Painter.drawText(0,4100, "Identifiant Visiteur : ");

    Painter.setPen(Qt::black);
    Painter.setFont(QFont("Calibri Light", 13));


    QString prixTicket=QString::number(V.prixTicket);


    Painter.drawText(1630,3500, V.identifiantTicket);
    Painter.drawText(1050,3800, prixTicket);
    Painter.drawText(1770,4100, V.identifiantVisiteur);

    //affichage du pdf
    QDesktopServices::openUrl(QUrl::fromLocalFile(nomFichier));


    Painter.end();

}

int Visite::calculOffre(int prixTicket, int offre)
{
    return prixTicket*offre;
}


