#ifndef PRODUIT_H
#define PRODUIT_H
#include<QString>

class Produit
{
public:
    void setId(QString n);
    void setnom(QString n);
    void settype(QString n);
    void setprix(QString n);
    void setnbE(QString n);
    void setIdf(QString n);
    QString get_Id();
    QString get_nom();
    QString get_type();
    QString get_prix();
    QString get_nbE();
    QString get_Idf();

    Produit();
private:
    QString Id ,nom, type, prix, nbE , Idf;
};

#endif // PRODUIT_H
