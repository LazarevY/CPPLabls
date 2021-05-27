#ifndef CASELISTWIDGET_H
#define CASELISTWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QString>
#include "Logic/caselist.h"
#include <QTextEdit>

class CaseListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CaseListWidget(const CaseList& list,
                            const QString name,
                            QWidget *parent = nullptr);

    QString name() const;
    void setName(const QString &name);

    CaseList list() const;
    void setList(const CaseList &list);

    void updateText();

    void callBeforeClose();

signals:
    void beforeClose(QString name);

private:
    QTextEdit *m_edit;
    CaseList m_list;
    QString m_name;
    QGridLayout *m_layout;
};

#endif // CASELISTWIDGET_H
