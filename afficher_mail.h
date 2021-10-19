#ifndef AFFICHER_MAIL_H
#define AFFICHER_MAIL_H

#include <QDialog>

namespace Ui {
class Afficher_mail;
}

class Afficher_mail : public QDialog
{
    Q_OBJECT

public:
    explicit Afficher_mail(QWidget *parent = nullptr);
    ~Afficher_mail();

private:
    Ui::Afficher_mail *ui;
};

#endif // AFFICHER_MAIL_H
