#ifndef CASELIST_H
#define CASELIST_H

#include "case.h"
#include <QString>
#include <QMap>

class CaseList
{
public:
    CaseList();

    void addCase(const QString &word, Case case_);
    Case findCase(const QString &word);

private:
    QMap<QString, Case> m_casesMap;
};

#endif // CASELIST_H
