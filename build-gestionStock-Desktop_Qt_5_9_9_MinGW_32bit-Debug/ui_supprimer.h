/********************************************************************************
** Form generated from reading UI file 'supprimer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMER_H
#define UI_SUPPRIMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_supprimer
{
public:
    QDialogButtonBox *Valider;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_IdS;
    QLineEdit *lineEdit_typeS;
    QLabel *label_4;
    QLineEdit *lineEdit_nbrS;

    void setupUi(QDialog *supprimer)
    {
        if (supprimer->objectName().isEmpty())
            supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->resize(400, 300);
        Valider = new QDialogButtonBox(supprimer);
        Valider->setObjectName(QStringLiteral("Valider"));
        Valider->setGeometry(QRect(290, 20, 81, 241));
        Valider->setOrientation(Qt::Vertical);
        Valider->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(supprimer);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 371, 281));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 110, 61, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 180, 61, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 180, 47, 14));
        lineEdit_IdS = new QLineEdit(groupBox);
        lineEdit_IdS->setObjectName(QStringLiteral("lineEdit_IdS"));
        lineEdit_IdS->setGeometry(QRect(190, 110, 131, 20));
        lineEdit_typeS = new QLineEdit(groupBox);
        lineEdit_typeS->setObjectName(QStringLiteral("lineEdit_typeS"));
        lineEdit_typeS->setGeometry(QRect(190, 170, 131, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 244, 151, 20));
        lineEdit_nbrS = new QLineEdit(groupBox);
        lineEdit_nbrS->setObjectName(QStringLiteral("lineEdit_nbrS"));
        lineEdit_nbrS->setGeometry(QRect(190, 240, 131, 20));

        retranslateUi(supprimer);
        QObject::connect(Valider, SIGNAL(accepted()), supprimer, SLOT(accept()));
        QObject::connect(Valider, SIGNAL(rejected()), supprimer, SLOT(reject()));

        QMetaObject::connectSlotsByName(supprimer);
    } // setupUi

    void retranslateUi(QDialog *supprimer)
    {
        supprimer->setWindowTitle(QApplication::translate("supprimer", "GestionStock", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("supprimer", "Supprimer Produit", Q_NULLPTR));
        label->setText(QApplication::translate("supprimer", "Id_produit", Q_NULLPTR));
        label_2->setText(QApplication::translate("supprimer", "Type produit", Q_NULLPTR));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("supprimer", "nbre_Exemplaires \303\240 supprimer ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class supprimer: public Ui_supprimer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMER_H
