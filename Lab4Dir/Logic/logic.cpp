#include "logic.h"
#include "nocasefoundexception.h"
#include <QDebug>

Logic::Logic()
{

}

CaseTable Logic::caseTable() const
{
    return m_caseTable;
}

void Logic::setCaseTable(const CaseTable &caseTable)
{
    m_caseTable = caseTable;
}

QString Logic::findCase(Case case_, const QString &word)
{
    return m_caseTable.findCase(case_, word);
}

QVector<QString> Logic::allWordsCase(const CaseList &lst, Case case_)
{
    auto words = lst.cases();

    QVector<QString> result;

    for (auto word : words){
        try {
            QString founded = m_caseTable.findCase(case_, word);
            result.push_back(founded);
        } catch (NoCaseFoundException &e) {
            m_logger->log(
                        e.msg(),
                        Logger::LogMessageType::WARNING);
        }
    }
    return result;
}

Logger *Logic::logger() const
{
    return m_logger;
}

void Logic::setLogger(Logger *logger)
{
    m_logger = logger;
}
