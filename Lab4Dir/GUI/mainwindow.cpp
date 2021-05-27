#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Utils/dataparsing.h"
#include <QDebug>
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

    CaseTable caseTable;

    DataParsing::fillCaseTableFromFile(caseTable,
                                       "/home/lazarev/LazarevY/Learn/CPPLabls/Lab4Dir/resources/table.ctab");

    updateTable(caseTable);

    CaseList lst;
    lst.addCase("wdeded", Case::Nominative);
    lst.addCase("wdeded1", Case::Genitive);
    lst.addCase("wdeded2", Case::Dative);
    lst.addCase("wdeded3", Case::Accusative);
    lst.addCase("wdeded4", Case::Creative);
    lst.addCase("wdeded5", Case::Prepositional);

    CaseListWidget *w1 = new CaseListWidget(
                lst, "n1", ui->mdiArea);
    CaseListWidget *w2 = new CaseListWidget(
                lst, "n2", ui->mdiArea);

    m_mdiWidgets["n1"] = w1;
    m_mdiWidgets["n2"] = w2;

    ui->mdiArea->addSubWindow(w1);
    ui->mdiArea->addSubWindow(w2);
    w1->show();
    w2->show();

    setupSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTable(const CaseTable &table)
{
    m_logic.setCaseTable(table);

    QMap<Case, int> casesIndicesMap = {
        {Case::Nominative, 0},
        {Case::Genitive, 1},
        {Case::Dative, 2},
        {Case::Accusative, 3},
        {Case::Creative, 4},
        {Case::Prepositional, 5},
    };

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    QVector<WordCases> uniq = table.getUnique();
    ui->tableWidget->setRowCount(uniq.size());
    m_tableItems.resize(uniq.size() * 6);

    int row = 0;
    for (auto wordCases: uniq){
        for (auto caseKv = wordCases.begin(); caseKv != wordCases.end(); ++caseKv){
            m_tableItems[row * 6 + casesIndicesMap[caseKv.key()]].setText(caseKv.value());
        }
        row++;
    }

    for (int ind = 0; ind < m_tableItems.size(); ++ind){
        ui->tableWidget->setItem(ind / 6, ind % 6, &m_tableItems[ind]);
    }

}

void MainWindow::loadCaseList(const QString &path)
{
    CaseList lst;
    DataParsing::readCaseList(lst, path);
}

void MainWindow::onSubWindowChanged(QMdiSubWindow *window)
{
    if (!window){
        ui->exportButton->setEnabled(window);
        return;
    }
    m_activeWidget = dynamic_cast<CaseListWidget *>(window->widget());
}

void MainWindow::setupSlots()
{
    QObject::connect(ui->mdiArea, &QMdiArea::subWindowActivated, this, &MainWindow::onSubWindowChanged);
}

Logger *MainWindow::logger() const
{
    return m_logger;
}

void MainWindow::setLogger(Logger *logger)
{
    m_logger = logger;
}

QTextEdit *MainWindow::getContexForGuoLogger()
{
    return ui->logTextArea;
}
