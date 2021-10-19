/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_Id;
    QLineEdit *lineEdit_type;
    QLineEdit *lineEdit_prix;
    QLineEdit *lineEdit_nbE;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QLineEdit *lineEdit_Idf;
    QLabel *label_6;
    QLineEdit *lineEdit_nom;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 451, 301));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 81, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 120, 71, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 170, 47, 14));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 230, 101, 16));
        lineEdit_Id = new QLineEdit(groupBox);
        lineEdit_Id->setObjectName(QStringLiteral("lineEdit_Id"));
        lineEdit_Id->setGeometry(QRect(150, 30, 113, 20));
        lineEdit_Id->setMaxLength(6);
        lineEdit_type = new QLineEdit(groupBox);
        lineEdit_type->setObjectName(QStringLiteral("lineEdit_type"));
        lineEdit_type->setGeometry(QRect(150, 120, 113, 20));
        lineEdit_prix = new QLineEdit(groupBox);
        lineEdit_prix->setObjectName(QStringLiteral("lineEdit_prix"));
        lineEdit_prix->setGeometry(QRect(150, 170, 113, 20));
        lineEdit_nbE = new QLineEdit(groupBox);
        lineEdit_nbE->setObjectName(QStringLiteral("lineEdit_nbE"));
        lineEdit_nbE->setGeometry(QRect(152, 220, 111, 20));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 80, 75, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 190, 75, 23));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 280, 91, 16));
        lineEdit_Idf = new QLineEdit(groupBox);
        lineEdit_Idf->setObjectName(QStringLiteral("lineEdit_Idf"));
        lineEdit_Idf->setGeometry(QRect(150, 270, 113, 20));
        lineEdit_Idf->setMaxLength(6);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 70, 61, 16));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(150, 70, 113, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GestionStock", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajouter _produit ", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Id produit", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Type produit ", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Nombre Exemplaires ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Quittre", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Id_Fournisseur ", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Nom produit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
