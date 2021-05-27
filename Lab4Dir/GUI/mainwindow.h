#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "Logic/casetable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void updateTable(const CaseTable &table);

private:
    Ui::MainWindow *ui;
    QVector<QTableWidgetItem> m_tableItems;
};

#endif // MAINWINDOW_H
