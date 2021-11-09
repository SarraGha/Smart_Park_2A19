#ifndef MODIFIER_H
#define MODIFIER_H

#include <QDialog>
#include"magasin.h"
namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT

public:
    explicit modifier(QWidget *parent = nullptr);
    ~modifier();

    void setID_MAG(int);
    void setID_LOC(int);
    void setPRIX(int);
    void setETAT(QString);
    void setTYPE(QString);

private slots:
    void on_modifier2_clicked();

private:
    Ui::modifier *ui;
    int ID_MAG,ID_LOC;
    int PRIX;
    QString ETAT,TYPE;
};

#endif // MODIFIER_H
