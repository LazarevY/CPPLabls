#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(6);
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

void MainWindow::updateTable(const CaseTable &table)
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    auto uniq = table.getUnique();
    ui->tableWidget->setRowCount(uniq.size());
}
