#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animaux.h"
#include "PDF.h"
#include "Carte_RFID.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->NumCage_2->setValidator(new QIntValidator(0, 999,this));
    ui->lineEdit_id->setValidator(new QIntValidator(0, 999,this));
    ui->lineEdit_Type_2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z_]{0,255}"), this ));
    ui->tab_animaux_2->setModel(A.afficher());
    ui->tab_animaux_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(A.afficher());
    ui->tab_animaux_2->setModel(m);
    ui->tab_animaux_2->setSortingEnabled(true);

    //QImage image("C:/Users/omare/Downloads/ProjetC++/Project/Plan.jpg");
    QImage image("E:/Downloads/ProjetC++/Project/Plan.jpg");
    image.scaled(1241, 731, Qt::IgnoreAspectRatio);
    item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene = new QGraphicsScene(this);
    ui->Map->setScene(scene);
    scene->addItem(item);


    ui->Tab_repas->setModel(A.Afficher_repas());
    ui->Tab_repas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    arduino = new QSerialPort;
    arduino_available = false;
    arduino_port_name = "";
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
        {
            if(serialPortInfo.vendorIdentifier()== arduino_uno_vendor_ID)
            {
                if(serialPortInfo.productIdentifier()== arduino_uno_product_ID)
                {
                    arduino_port_name = serialPortInfo.portName();
                    arduino_available = true;
                }
            }
        }
    }
    if(arduino_available)
    {
        qDebug() << "Found the arduino port...\n";
        arduino->setPortName(arduino_port_name);
        if(!arduino->open(QSerialPort::ReadWrite))
        {
            qDebug()<<"can't open";

        }
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));

    }
    else{QMessageBox::warning(this, "Port Error", "Couldn't find Arduino!");}

}

MainWindow::~MainWindow()
{
    if(arduino->isOpen())
    {
        arduino->close();
    }
    delete ui;
}


void MainWindow::on_Ajout_Button_clicked()
{
    int id = 0;
    QString reclam = NULL;
    QString type = ui->lineEdit_Type_2->text();
    int num_cage = ui->NumCage_2->text().toInt();
    QString nouriture = ui->Nourriture_2->currentText();
    int Age = 2021 - ui->Date_2->date().year();
    Animaux A(id,type, num_cage, Age, nouriture, reclam);
    A.ajouterA();
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(A.afficher());
    ui->tab_animaux_2->setModel(m);
    ui->tab_animaux_2->setSortingEnabled(true);
}



void MainWindow::on_Del_Button_clicked()
{
    int index;
    QModelIndex temp = ui->tab_animaux_2->selectionModel()->currentIndex();
    QVariant value;
    index = ui->tab_animaux_2->selectionModel()->currentIndex().row();
    value = temp.sibling(index, 0).data();
    int del = value.toInt();
    Animaux A(del, "Rien", 0, 0,"Rien", "Rien");
    A.supprimerA();
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(A.afficher());
    ui->tab_animaux_2->setModel(m);
    ui->tab_animaux_2->setSortingEnabled(true);
}

void MainWindow::on_Edit_Button_clicked()
{
    int row, column, id;
    QString edit;
    int Iedit;
    QModelIndex temp = ui->tab_animaux_2->selectionModel()->currentIndex();
    QVariant value;
    row = ui->tab_animaux_2->selectionModel()->currentIndex().row();
    column = ui->tab_animaux_2->selectionModel()->currentIndex().column();
    value = temp.sibling(row, 0).data();
    id = value.toInt();
    Animaux A;
    switch(column)
    {
    case 0:
        Iedit = ui->lineEdit_Edit_2->text().toInt();
        A.setid(Iedit);
        A.modifierA(column, id);
        break;
    case 1:
        edit = ui->lineEdit_Edit_2->text();
        A.setType(edit);
        A.modifierA(column, id);
        break;
    case 2:
        Iedit = ui->lineEdit_Edit_2->text().toInt();
        A.setnumCage(Iedit);
        A.modifierA(column, id);
        break;
    case 3:
        edit = ui->lineEdit_Edit_2->text();
        A.setNouriture(edit);
        A.modifierA(column, id);
        break;
    case 4:
        Iedit = ui->lineEdit_Edit_2->text().toInt();
        A.setAge(Iedit);
        A.modifierA(column, id);
        break;
    case 5:
        edit = ui->lineEdit_Edit_2->text();
        A.setReclam(edit);
        A.modifierA(column, id);
        break;
    }
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(A.afficher());
    ui->tab_animaux_2->setModel(m);
    ui->tab_animaux_2->setSortingEnabled(true);
}


void MainWindow::on_AjouterRepas_clicked()
{
    Animaux A;
    int id = ui->lineEdit_id->text().toInt();
    A.setid(id);
    A.ajouterR();
    ui->Tab_repas->setModel(A.rechercher_R(ui->lineEdit_id->text()));
    ui->Tab_repas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_lineEdit_id_textChanged(const QString &arg1)
{
    Animaux A;
    ui->Tab_repas->setModel(A.rechercher_R(arg1));
    ui->Tab_repas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}



void MainWindow::on_SuppRepas_clicked()
{
    int index;
    QModelIndex temp = ui->Tab_repas    ->selectionModel()->currentIndex();
    QVariant value;
    index = ui->Tab_repas->selectionModel()->currentIndex().row();
    value = temp.sibling(index, 0).data();
    int del = value.toInt();
    Animaux A;
    A.setid(del);
    A.supprimerR();
    ui->Tab_repas->setModel(A.rechercher_R(ui->lineEdit_id->text()));
    ui->Tab_repas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_Genpdf_clicked()
{
    //pdf("C:/Users/omare/Downloads/ProjetC++/animaux.pdf");
    pdf("E:/Downloads/ProjetC++/Project/animaux.pdf");
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    Animaux A;
    ui->tab_animaux_2->setModel(A.rechercher(arg1));
    ui->tab_animaux_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(A.rechercher(arg1));
    ui->tab_animaux_2->setModel(m);
    ui->tab_animaux_2->setSortingEnabled(true);
}


void MainWindow::on_LineEdit_Info_textChanged(const QString &arg1)
{
    QString outputInfo = info(arg1);
    ui->infoList->clear();
    QFont font = ui->infoList->font();
    font.setPointSize(15);
    font.setBold(true);
    ui->infoList->setFont(font);

    ui->infoList->addItem(outputInfo);
}

void MainWindow::on_RechCage_clicked()
{
    int rech = ui->numCage->text().toInt();
    qDebug() << rech;
    if(rech == NULL)
    {
        //QImage image("C:/Users/omare/Downloads/ProjetC++/Project/Plan.jpg");
        QImage image("E:/Downloads/ProjetC++/Project/Plan.jpg");
        //image.scaled(1241, 731, Qt::IgnoreAspectRatio);
        item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        scene = new QGraphicsScene(this);
        ui->Map->setScene(scene);
        scene->addItem(item);
    }
    else{
        //QString path = ("C:/Users/omare/Downloads/ProjetC++/Project/"+QString::number(rech)+".jpg");
        QString path = ("E:/Downloads/ProjetC++/Project/"+QString::number(rech)+".jpg");
        path = path.simplified();
        path.replace(" ","");
        qDebug() << path;
        QImage image(path);
        image.scaled(1241, 731, Qt::IgnoreAspectRatio);
        item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        scene = new QGraphicsScene(this);
        ui->Map->setScene(scene);
        scene->addItem(item);
    }
}

void MainWindow::readSerial()
{
    QStringList buffer_split = serialBuffer.split(",");
    if(buffer_split.length()< 2)
    {
        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
        qDebug()<< serialBuffer;
        serialData.clear();
    }
    buffer_split = serialBuffer.split(",");
    if(serialBuffer.lastIndexOf(QChar(',')) != -1)
    {
        qDebug()<< buffer_split<<"\n";
        parsed_data = buffer_split[0];
        UID = parsed_data;
        qDebug()<< "UID :"<< UID<< "\n";
        parsed_data = UID;
        serialBuffer ="";
        checkCard(UID, arduino);

    }

}
