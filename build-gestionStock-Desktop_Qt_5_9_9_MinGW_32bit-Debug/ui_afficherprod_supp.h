/********************************************************************************
** Form generated from reading UI file 'afficherprod_supp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHERPROD_SUPP_H
#define UI_AFFICHERPROD_SUPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AfficherProd_Supp
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *AfficherProd_Supp)
    {
        if (AfficherProd_Supp->objectName().isEmpty())
            AfficherProd_Supp->setObjectName(QStringLiteral("AfficherProd_Supp"));
        AfficherProd_Supp->resize(400, 400);
        groupBox = new QGroupBox(AfficherProd_Supp);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 341, 361));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 100, 71, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 170, 71, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 250, 121, 20));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 100, 141, 20));
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 160, 141, 20));
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 250, 131, 20));
        lineEdit_3->setReadOnly(true);

        retranslateUi(AfficherProd_Supp);

        QMetaObject::connectSlotsByName(AfficherProd_Supp);
    } // setupUi

    void retranslateUi(QDialog *AfficherProd_Supp)
    {
        AfficherProd_Supp->setWindowTitle(QApplication::translate("AfficherProd_Supp", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("AfficherProd_Supp", "Afficher Produits Supprim\303\251s", Q_NULLPTR));
        label->setText(QApplication::translate("AfficherProd_Supp", "Id_Produit", Q_NULLPTR));
        label_2->setText(QApplication::translate("AfficherProd_Supp", "Nom_Produit", Q_NULLPTR));
        label_3->setText(QApplication::translate("AfficherProd_Supp", "Nbre_Exemp supprim\303\251s", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AfficherProd_Supp: public Ui_AfficherProd_Supp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHERPROD_SUPP_H
