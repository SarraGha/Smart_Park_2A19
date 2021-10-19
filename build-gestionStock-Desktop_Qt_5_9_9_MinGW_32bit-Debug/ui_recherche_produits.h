/********************************************************************************
** Form generated from reading UI file 'recherche_produits.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECHERCHE_PRODUITS_H
#define UI_RECHERCHE_PRODUITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Recherche_Produits
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_idR;
    QLineEdit *lineEdit_TypeR;

    void setupUi(QDialog *Recherche_Produits)
    {
        if (Recherche_Produits->objectName().isEmpty())
            Recherche_Produits->setObjectName(QStringLiteral("Recherche_Produits"));
        Recherche_Produits->resize(400, 300);
        groupBox = new QGroupBox(Recherche_Produits);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 331, 251));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 90, 71, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 200, 71, 16));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 80, 75, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 130, 75, 23));
        lineEdit_idR = new QLineEdit(groupBox);
        lineEdit_idR->setObjectName(QStringLiteral("lineEdit_idR"));
        lineEdit_idR->setGeometry(QRect(90, 90, 121, 20));
        lineEdit_TypeR = new QLineEdit(groupBox);
        lineEdit_TypeR->setObjectName(QStringLiteral("lineEdit_TypeR"));
        lineEdit_TypeR->setGeometry(QRect(90, 200, 113, 20));

        retranslateUi(Recherche_Produits);

        QMetaObject::connectSlotsByName(Recherche_Produits);
    } // setupUi

    void retranslateUi(QDialog *Recherche_Produits)
    {
        Recherche_Produits->setWindowTitle(QApplication::translate("Recherche_Produits", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Recherche_Produits", "Recherche_Produit", Q_NULLPTR));
        label->setText(QApplication::translate("Recherche_Produits", "Id_Produit", Q_NULLPTR));
        label_2->setText(QApplication::translate("Recherche_Produits", "Type_Produit", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Recherche_Produits", "Rechercher", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Recherche_Produits", "Quitter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Recherche_Produits: public Ui_Recherche_Produits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECHERCHE_PRODUITS_H
