/********************************************************************************
** Form generated from reading UI file 'afficher_mail.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFFICHER_MAIL_H
#define UI_AFFICHER_MAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Afficher_mail
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *textA;
    QLineEdit *lineEdit_ObjetA;
    QLineEdit *lineEdit_mailA;

    void setupUi(QDialog *Afficher_mail)
    {
        if (Afficher_mail->objectName().isEmpty())
            Afficher_mail->setObjectName(QStringLiteral("Afficher_mail"));
        Afficher_mail->resize(400, 300);
        groupBox = new QGroupBox(Afficher_mail);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 341, 271));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 70, 47, 14));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 47, 14));
        textA = new QTextBrowser(groupBox);
        textA->setObjectName(QStringLiteral("textA"));
        textA->setGeometry(QRect(60, 110, 221, 161));
        textA->setReadOnly(true);
        lineEdit_ObjetA = new QLineEdit(groupBox);
        lineEdit_ObjetA->setObjectName(QStringLiteral("lineEdit_ObjetA"));
        lineEdit_ObjetA->setGeometry(QRect(60, 70, 221, 20));
        lineEdit_ObjetA->setReadOnly(true);
        lineEdit_mailA = new QLineEdit(groupBox);
        lineEdit_mailA->setObjectName(QStringLiteral("lineEdit_mailA"));
        lineEdit_mailA->setGeometry(QRect(60, 40, 221, 20));
        lineEdit_mailA->setReadOnly(true);

        retranslateUi(Afficher_mail);

        QMetaObject::connectSlotsByName(Afficher_mail);
    } // setupUi

    void retranslateUi(QDialog *Afficher_mail)
    {
        Afficher_mail->setWindowTitle(QApplication::translate("Afficher_mail", "Mailing", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Afficher_mail", "Afficher mail", Q_NULLPTR));
        label->setText(QApplication::translate("Afficher_mail", "Objet : ", Q_NULLPTR));
        label_2->setText(QApplication::translate("Afficher_mail", "E-mail :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Afficher_mail: public Ui_Afficher_mail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFFICHER_MAIL_H
