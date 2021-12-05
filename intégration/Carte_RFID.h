#ifndef CARTE_RFID_H
#define CARTE_RFID_H
#include <QApplication>
#include <QtCore>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include<QtSerialPort>
#include<QSerialPortInfo>
#include<iostream>
#include <QSqlRecord>
#include<QString>

int checkCard(QString UID, QSerialPort *arduino);
#endif // CARTE_RFID_H
