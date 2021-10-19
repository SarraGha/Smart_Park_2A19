#ifndef RECHERCHE_PRODUITS_H
#define RECHERCHE_PRODUITS_H

#include <QDialog>

namespace Ui {
class Recherche_Produits;
}

class Recherche_Produits : public QDialog
{
    Q_OBJECT

public:
    explicit Recherche_Produits(QWidget *parent = nullptr);
    ~Recherche_Produits();

private:
    Ui::Recherche_Produits *ui;
};

#endif // RECHERCHE_PRODUITS_H
