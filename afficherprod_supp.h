#ifndef AFFICHERPROD_SUPP_H
#define AFFICHERPROD_SUPP_H

#include <QDialog>

namespace Ui {
class AfficherProd_Supp;
}

class AfficherProd_Supp : public QDialog
{
    Q_OBJECT

public:
    explicit AfficherProd_Supp(QWidget *parent = nullptr);
    ~AfficherProd_Supp();

private:
    Ui::AfficherProd_Supp *ui;
};

#endif // AFFICHERPROD_SUPP_H
