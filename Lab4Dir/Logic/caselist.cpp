#include "caselist.h"

CaseList::CaseList()
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
