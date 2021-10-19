#include "mailing.h"
#include "ui_mailing.h"

mailing::mailing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mailing)
{
    ui->setupUi(this);
}

mailing::~mailing()
{
    delete ui;
}
