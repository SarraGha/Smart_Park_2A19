/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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

class Ui_GestionStock
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_IdD;
    QLineEdit *lineEdit_nomD;
    QLineEdit *lineEdit_typeD;
    QLineEdit *lineEdit_prixD;
    QLineEdit *lineEdit_nbED;
    QLabel *label_6;
    QLineEdit *lineEdit_Idf;

    void setupUi(QDialog *GestionStock)
    {
        if (GestionStock->objectName().isEmpty())
            GestionStock->setObjectName(QStringLiteral("GestionStock"));
        GestionStock->resize(400, 351);
        groupBox = new QGroupBox(GestionStock);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 291, 331));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 71, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 110, 71, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 170, 71, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 220, 47, 14));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 260, 91, 20));
        lineEdit_IdD = new QLineEdit(groupBox);
        lineEdit_IdD->setObjectName(QStringLiteral("lineEdit_IdD"));
        lineEdit_IdD->setGeometry(QRect(120, 50, 113, 20));
        lineEdit_IdD->setReadOnly(true);
        lineEdit_nomD = new QLineEdit(groupBox);
        lineEdit_nomD->setObjectName(QStringLiteral("lineEdit_nomD"));
        lineEdit_nomD->setGeometry(QRect(120, 110, 113, 20));
        lineEdit_nomD->setReadOnly(true);
        lineEdit_typeD = new QLineEdit(groupBox);
        lineEdit_typeD->setObjectName(QStringLiteral("lineEdit_typeD"));
        lineEdit_typeD->setGeometry(QRect(120, 170, 113, 20));
        lineEdit_typeD->setReadOnly(true);
        lineEdit_prixD = new QLineEdit(groupBox);
        lineEdit_prixD->setObjectName(QStringLiteral("lineEdit_prixD"));
        lineEdit_prixD->setGeometry(QRect(120, 220, 113, 20));
        lineEdit_prixD->setReadOnly(true);
        lineEdit_nbED = new QLineEdit(groupBox);
        lineEdit_nbED->setObjectName(QStringLiteral("lineEdit_nbED"));
        lineEdit_nbED->setGeometry(QRect(120, 260, 113, 20));
        lineEdit_nbED->setReadOnly(true);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 310, 81, 16));
        lineEdit_Idf = new QLineEdit(groupBox);
        lineEdit_Idf->setObjectName(QStringLiteral("lineEdit_Idf"));
        lineEdit_Idf->setGeometry(QRect(120, 300, 113, 20));
        lineEdit_Idf->setReadOnly(true);

        retranslateUi(GestionStock);

        QMetaObject::connectSlotsByName(GestionStock);
    } // setupUi

    void retranslateUi(QDialog *GestionStock)
    {
        GestionStock->setWindowTitle(QApplication::translate("GestionStock", "afficher produit", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("GestionStock", "Afficher Produit", Q_NULLPTR));
        label->setText(QApplication::translate("GestionStock", "Id_produit ", Q_NULLPTR));
        label_2->setText(QApplication::translate("GestionStock", "Nom_produit", Q_NULLPTR));
        label_3->setText(QApplication::translate("GestionStock", "Type_produit", Q_NULLPTR));
        label_4->setText(QApplication::translate("GestionStock", "Prix ", Q_NULLPTR));
        label_5->setText(QApplication::translate("GestionStock", "Nbre_Exemplaires ", Q_NULLPTR));
        label_6->setText(QApplication::translate("GestionStock", "Id_Fournisseur ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GestionStock: public Ui_GestionStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
