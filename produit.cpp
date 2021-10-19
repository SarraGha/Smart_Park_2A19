#include "produit.h"

Produit::Produit()
{
Id="";
nom="";
type="";
prix="";
nbE="";
Idf="";
}
void Produit::setId(QString n){Id=n;}
void Produit::setnom(QString n){nom=n;}
void Produit::settype(QString n){type=n;}
void Produit::setprix(QString n){prix=n;}
void Produit::setnbE(QString n){nbE=n;}
void Produit::setIdf(QString n){Idf=n;}



QString Produit::get_Id(){return Id;}
QString Produit::get_nom(){return nom;}
QString Produit::get_type(){return type;}
QString Produit::get_prix(){return prix;}
QString Produit::get_nbE(){return nbE;}
QString Produit::get_Idf(){return Idf;}
