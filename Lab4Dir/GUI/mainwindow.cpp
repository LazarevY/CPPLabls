#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setItem(1,1, new QTableWidgetItem("Some Text"));
    ui->tableWidget->setHorizontalHeaderItem(0,
                                             new QTableWidgetItem("Nominative"));
    ui->tableWidget->setHorizontalHeaderItem(1,
                                             new QTableWidgetItem("Genetive"));
    ui->tableWidget->setHorizontalHeaderItem(2,
                                             new QTableWidgetItem("Dative"));
    ui->tableWidget->setHorizontalHeaderItem(3,
                                             new QTableWidgetItem("Accusative"));
    ui->tableWidget->setHorizontalHeaderItem(4,
                                             new QTableWidgetItem("Creative"));
    ui->tableWidget->setHorizontalHeaderItem(5,
                                             new QTableWidgetItem("Prepositional"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
