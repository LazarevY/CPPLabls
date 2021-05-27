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
#include "mdisubwindoweventfilter.h"
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
    void loadCaseTable(const QString &path);
private slots:

    void addCaseList(const CaseList &lst, const QString &name);
    void onSubWindowChanged(QMdiSubWindow *window);
    void onSubwindowClosed(QString name);
    void onNewDataFileLoadOption(bool checked);
    void onTableLoadOption(bool checked);

private:

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
