#ifndef CASELIST_H
#define CASELIST_H

#include "case.h"
#include <QString>
#include <QMap>

class CaseList
{
public:
    CaseList();
    CaseList(QMap<QString, Case> casesMap);

    void addCase(const QString &word, Case case_);
    Case findCase(const QString &word);

    bool isEmpty() const;

    QMap<QString, Case> casesMap() const;

private:
    QMap<QString, Case> m_casesMap;
};

#endif // CASELIST_H
