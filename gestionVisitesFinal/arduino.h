#ifndef ARDUINO_H
#define ARDUINO_H


#include <QtSerialPort/QSerialPort>   //classe d'echange de donnes dans une liaison serie
#include <QtSerialPort/QSerialPortInfo> //classe fournissaznt des infos sue les ports disponibles
#include <QDebug>

class Arduino
{
public:
    Arduino();
    int connect_arduino() ;//connecter PC Arduino
    int close_arduino();//fermer la connexion
    int write_to_arduino(QByteArray);//envoyer des données vers Arduino
    QByteArray read_from_arduino();//recevoir des données de Arduino
    QSerialPort* getserial ();   //accesseur
    QString getarduino_port_name();

private :
QSerialPort *serial;//Cet objet rassemble des informations (vitesse , bits de données ...)
//et les fonctions (envoi, lecture de réception ...) sur ce qu'est une voie série pour Arduino
static const quint16 arduino_uno_vendor_id = 9025;//connaitre le hardware (carte Arduino)
static const quint16 arduino_uno_producy_id = 67 ;
QString arduino_port_name;//numero de port
bool arduino_is_avaible;//verification de l'existence d'Arduino
QByteArray data;//sauvegarder  les valeurs d' Arduino
};

#endif // ARDUINO_H
