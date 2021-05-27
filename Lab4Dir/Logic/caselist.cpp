#include "caselist.h"

CaseList::CaseList()
{

}

CaseList::CaseList(QMap<QString, Case> casesMap) : m_casesMap(casesMap)
{

}

void CaseList::addCase(const QString &word, Case case_)
{
    m_casesMap[word] = case_;
}

Case CaseList::findCase(const QString &word)
{
    return m_casesMap[word];
}

bool CaseList::isEmpty() const
{
    return m_casesMap.isEmpty();
}

QMap<QString, Case> CaseList::casesMap() const
{
    return m_casesMap;
}
