#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QMdiSubWindow>
#include <QMap>
#include <QGridLayout>

#include "Logic/casetable.h"
#include "Logic/logic.h"
#include "Logging/logger.h"
#include "Logging/mocklogger.h"
#include "caselistwidget.h"
#include "mdisubwindoweventfilter.h"
#include "Utils/appexception.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const Logic &logic, QWidget *parent = nullptr);
    ~MainWindow();

    Logger *logger() const;
    void setLogger(Logger *logger);

    QTextEdit *getContexForGuoLogger();

private:
    void updateTable(const CaseTable &table);
    void loadCaseList(const QString &path);
    void loadCaseTable(const QString &path);
    void exportCases(const CaseList &lst);
    void logException(const std::exception &e);
private slots:

    void addCaseList(const CaseList &lst, const QString &name);
    void onSubWindowChanged(QMdiSubWindow *window);
    void onSubwindowClosed(QString name);
    void onNewDataFileLoadOption(bool checked);
    void onTableLoadOption(bool checked);
    void onExportAction();
    void about();

private:

    void initComboBox();
    void setupSlots();

    Ui::MainWindow *ui;
    QVector<QTableWidgetItem> m_tableItems;
    Logic m_logic;
    Logger *m_logger = &MockLogger::instance();
    QMap<QString, CaseListWidget *> m_mdiWidgets;
    MdiSubwindowEventFilter m_mdiEventFilter;
    CaseListWidget *m_activeWidget = nullptr;
};

#endif // MAINWINDOW_H
