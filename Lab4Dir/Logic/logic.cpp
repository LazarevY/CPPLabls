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
    auto map = lst.casesMap();

    QVector<QString> result;

    for (auto kv = map.begin(); kv != map.end(); ++kv){
        try {
            QString founded = m_caseTable.findCase(case_, kv.key());
            result.push_back(founded);
        } catch (NoCaseFoundException &e) {
            m_logger->log(
                        QString("No found case %1 to word %2").arg(
                            CaseTools::caseEnumToStr(e.case_())).arg(e.word()),
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
