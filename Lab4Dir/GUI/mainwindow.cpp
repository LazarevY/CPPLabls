#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Utils/dataparsing.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include "Utils/appexception.h"

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
    setupSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTable(const CaseTable &table)
{
    m_logic.setCaseTable(table);

    if (table.isEmpty()){
        m_logger->log("Table is empty", Logger::LogMessageType::WARNING);
        return;
    }

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

    m_logger->log("Table loaded", Logger::LogMessageType::OK);

}

void MainWindow::loadCaseList(const QString &path)
{
    if (m_mdiWidgets.contains(path)){
        QString text = QString("File '%1' already loaded").arg(path);
        m_logger->log(text,
                      Logger::LogMessageType::FAIL);
        QMessageBox msg;
        msg.setText(text);
        msg.exec();
    }
    CaseList lst;
    try {
        DataParsing::readCaseList(lst, path);
        addCaseList(lst, path);
    } catch (std::exception &e) {
        m_logger->log(QString("Exception occured: %1").arg(e.what()), Logger::LogMessageType::FAIL);
    }
}

void MainWindow::loadCaseTable(const QString &path)
{
    CaseTable t;
    try {
        DataParsing::fillCaseTableFromFile(t, path);
        updateTable(t);
    } catch (std::exception &e) {
        m_logger->log(QString("Exception occured: %1").arg(e.what()), Logger::LogMessageType::FAIL);
    }

}

void MainWindow::addCaseList(const CaseList &lst, const QString &name)
{
    if (lst.isEmpty()){
        m_logger->log(
                    QString("Read '%1',  but no words founded")
                    .arg(name),
                    Logger::LogMessageType::WARNING);
        return;
    }
    CaseListWidget *w = new CaseListWidget(lst, name, ui->mdiArea);
    QObject::connect(w, &CaseListWidget::beforeClose, this, &MainWindow::onSubwindowClosed);
    m_mdiWidgets[name] = w;
    auto subWindow = ui->mdiArea->addSubWindow(w);
    subWindow->installEventFilter(&m_mdiEventFilter);
    subWindow->setAttribute(Qt::WA_DeleteOnClose, true);
    w->show();
    m_logger->log(QString("Add new doc '%1'").arg(name), Logger::LogMessageType::OK);
}

void MainWindow::onSubWindowChanged(QMdiSubWindow *window)
{
    if (!window){
        ui->exportButton->setEnabled(window);
        return;
    }
    m_activeWidget = dynamic_cast<CaseListWidget *>(window->widget());
}

void MainWindow::onSubwindowClosed(QString name)
{
    m_logger->log(QString("Doc '%1' has been closed").arg(name),
                  Logger::LogMessageType::INFO);
    auto w = m_mdiWidgets.take(name);
}

void MainWindow::onNewDataFileLoadOption(bool checked)
{
    QString file = QFileDialog::getOpenFileName();
    if (file != "")
        loadCaseList(file);
}

void MainWindow::onTableLoadOption(bool checked)
{
    QString file = QFileDialog::getOpenFileName();
    if (file != "")
        loadCaseTable(file);
}

void MainWindow::setupSlots()
{
    QObject::connect(ui->mdiArea, &QMdiArea::subWindowActivated, this, &MainWindow::onSubWindowChanged);
    QObject::connect(ui->actionLoad_New_Data_File, &QAction::triggered, this, &MainWindow::onNewDataFileLoadOption);
    QObject::connect(ui->actionLoad_Table, &QAction::triggered, this, &MainWindow::onTableLoadOption);
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
