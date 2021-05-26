#include "casetable.h"
#include "nocasefoundexception.h"

CaseTable::CaseTable()
{

}

void CaseTable::addCase(Case case_, const QString &existingCase, const QString &caseWordValue)
{
    checkWordCasesCreated(existingCase);
    m_caseTableData[existingCase]->operator[](case_) = caseWordValue;
}

void CaseTable::setCases(const QMap<Case, QString> &cases)
{
    if (!cases.size())
        return;
    for (auto kv = cases.constKeyValueBegin(); kv != cases.constKeyValueEnd(); ++kv)
        deleteCases(kv.base().value());
    WordCases *newCases = new QMap<Case, QString>(cases);
    for (auto kv = cases.constKeyValueBegin(); kv != cases.constKeyValueEnd(); ++kv)
        m_caseTableData[kv.base().value()] = newCases;

}

void CaseTable::expandCases(const QMap<Case, QString> &cases)
{
    if (!cases.size())
        return;
    WordCases *oldCases = nullptr;

    for (auto kv = cases.constKeyValueBegin(); kv != cases.constKeyValueEnd() && !oldCases; ++kv)
        oldCases = m_caseTableData[kv.base().value()];

    if (!oldCases){
        setCases(cases);
        return;
    }

    for (auto kv = cases.constKeyValueBegin(); kv != cases.constKeyValueEnd(); ++kv)
        oldCases->operator[](kv.base().key()) = kv.base().value();
}

QString CaseTable::findCase(Case case_, const QString &word)
{
    if (!m_caseTableData.contains(word) || !m_caseTableData[word]->contains(case_)){
        throw NoCaseFoundException(case_, word);
    }

    return m_caseTableData[word]->operator[](case_);

}

QVector<WordCases> CaseTable::getUnique()
{
   auto u =  m_caseTableData.values().toSet();
   QVector<WordCases> cases;
   for (auto case_ : u)
       cases.push_back(*case_);
   return cases;
}

void CaseTable::checkWordCasesCreated(const QString &word)
{
    if (!m_caseTableData.contains(word)){
        m_caseTableData[word] = new QMap<Case, QString>();
    }
}

void CaseTable::deleteCases(const QString &word)
{
    if (m_caseTableData.contains(word)){
        WordCases *cases = m_caseTableData[word];
        for (auto kv = cases->keyValueBegin(); kv != cases->keyValueEnd(); ++kv)
            m_caseTableData.remove(kv.base().value());
        delete cases;
    }
}
