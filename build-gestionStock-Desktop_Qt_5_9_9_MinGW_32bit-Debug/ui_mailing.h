/********************************************************************************
** Form generated from reading UI file 'mailing.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAILING_H
#define UI_MAILING_H

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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_mailing
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_mail;
    QLineEdit *lineEdit_objet;
    QTextEdit *text;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *mailing)
    {
        if (mailing->objectName().isEmpty())
            mailing->setObjectName(QStringLiteral("mailing"));
        mailing->resize(400, 300);
        groupBox = new QGroupBox(mailing);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 341, 281));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 47, 14));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 47, 14));
        lineEdit_mail = new QLineEdit(groupBox);
        lineEdit_mail->setObjectName(QStringLiteral("lineEdit_mail"));
        lineEdit_mail->setGeometry(QRect(50, 50, 191, 20));
        lineEdit_objet = new QLineEdit(groupBox);
        lineEdit_objet->setObjectName(QStringLiteral("lineEdit_objet"));
        lineEdit_objet->setGeometry(QRect(50, 80, 191, 20));
        text = new QTextEdit(groupBox);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(50, 120, 191, 151));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 120, 75, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 170, 75, 23));

        retranslateUi(mailing);

        QMetaObject::connectSlotsByName(mailing);
    } // setupUi

    void retranslateUi(QDialog *mailing)
    {
        mailing->setWindowTitle(QApplication::translate("mailing", "Mailing", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("mailing", "Envoyer un mail", Q_NULLPTR));
        label->setText(QApplication::translate("mailing", "E-mail :", Q_NULLPTR));
        label_2->setText(QApplication::translate("mailing", "Objet :", Q_NULLPTR));
        pushButton->setText(QApplication::translate("mailing", "Envoyer", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("mailing", "Quitter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mailing: public Ui_mailing {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAILING_H
