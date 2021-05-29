#include "caselist.h"

CaseList::CaseList()
{

}

CaseList::CaseList(const QVector<QString> &cases) : m_cases(cases)
{

}

void CaseList::addCase(const QString &word)
{
    m_cases.append(word);
}

bool CaseList::isEmpty() const
{
    return m_cases.isEmpty();
}

QVector<QString> CaseList::cases() const
{
    return m_cases;
}
