#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animaux.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->NumCage->setValidator(new QIntValidator(0, 999,this));
    ui->tab_animaux->setModel(A.afficher());
    ui->tab_animaux->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(A.afficher());
    ui->tab_animaux->setModel(m);
    ui->tab_animaux->setSortingEnabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Ajout_Button_clicked()
{
    int id = 0;
    QString reclam = NULL;
    QString type = ui->lineEdit_Type->text();
    int num_cage = ui->NumCage->text().toInt();
    QString nouriture = ui->Nourriture->currentText();
    int Age = 2021 - ui->Date->date().year();
    Animaux A(id,type, num_cage, Age, nouriture, reclam);
    A.ajouterA();
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(A.afficher());
    ui->tab_animaux->setModel(m);
    ui->tab_animaux->setSortingEnabled(true);
}



void MainWindow::on_Del_Button_clicked()
{
    int index;
    QModelIndex temp = ui->tab_animaux->selectionModel()->currentIndex();
    QVariant value;
    index = ui->tab_animaux->selectionModel()->currentIndex().row();
    value = temp.sibling(index, 0).data();
    int del = value.toInt();
    Animaux A(del, "Rien", 0, 0,"Rien", "Rien");
    A.supprimerA();
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(A.afficher());
    ui->tab_animaux->setModel(m);
    ui->tab_animaux->setSortingEnabled(true);
}

void MainWindow::on_Edit_Button_clicked()
{
    int row, column, id;
    QString edit;
    int Iedit;
    QModelIndex temp = ui->tab_animaux->selectionModel()->currentIndex();
    QVariant value;
    row = ui->tab_animaux->selectionModel()->currentIndex().row();
    column = ui->tab_animaux->selectionModel()->currentIndex().column();
    value = temp.sibling(row, 0).data();
    id = value.toInt();
    Animaux A;
    switch(column)
    {
    case 0:
        Iedit = ui->lineEdit_Edit->text().toInt();
        A.setid(Iedit);
        A.modifierA(column, id);
        break;
    case 1:
        edit = ui->lineEdit_Edit->text();
        A.setType(edit);
        A.modifierA(column, id);
        break;
    case 2:
        Iedit = ui->lineEdit_Edit->text().toInt();
        A.setnumCage(Iedit);
        A.modifierA(column, id);
        break;
    case 3:
        edit = ui->lineEdit_Edit->text();
        A.setNouriture(edit);
        A.modifierA(column, id);
        break;
    case 4:
        Iedit = ui->lineEdit_Edit->text().toInt();
        A.setAge(Iedit);
        A.modifierA(column, id);
        break;
    case 5:
        edit = ui->lineEdit_Edit->text();
        A.setReclam(edit);
        A.modifierA(column, id);
        break;
    }
    QSortFilterProxyModel *m=new QSortFilterProxyModel(this);
    m->setDynamicSortFilter(true);
    m->setSourceModel(A.afficher());
    ui->tab_animaux->setModel(m);
    ui->tab_animaux->setSortingEnabled(true);
}
