#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QMdiSubWindow>
#include <QMap>
#include "Logic/casetable.h"
#include "Logic/logic.h"
#include "Logging/logger.h"
#include "Logging/mocklogger.h"
#include "caselistwidget.h"
#include <QGridLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Logger *logger() const;
    void setLogger(Logger *logger);

    QTextEdit *getContexForGuoLogger();

private:
    void updateTable(const CaseTable &table);
    void loadCaseList(const QString &path);
private slots:

    void onSubWindowChanged(QMdiSubWindow *window);

private:

    void setupSlots();

    Ui::MainWindow *ui;
    QVector<QTableWidgetItem> m_tableItems;
    Logic m_logic;
    Logger *m_logger = &MockLogger::instance();
    QMap<QString, CaseListWidget *> m_mdiWidgets;
    CaseListWidget *m_activeWidget = nullptr;
};

#endif // MAINWINDOW_H
