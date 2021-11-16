#ifndef PDF_H
#define PDF_H
#include <QApplication>
#include <QtCore>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QTableView>
#include <QFont>

QString currDate();
void pdf(QString);
QString info(QString rech);



#endif // PDF_H
