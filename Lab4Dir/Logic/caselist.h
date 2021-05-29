#ifndef CASELIST_H
#define CASELIST_H

#include "case.h"
#include <QString>
#include <QVector>

class CaseList
{
public:
    CaseList();
    CaseList(const QVector<QString> &cases);

    void addCase(const QString &word);
    bool isEmpty() const;

    QVector<QString> cases() const;

private:
    QVector<QString> m_cases;
};

#endif // CASELIST_H
