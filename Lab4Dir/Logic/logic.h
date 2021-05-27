#ifndef LOGIC_H
#define LOGIC_H

#include "casetable.h"
#include "caselist.h"
#include "Logging/logger.h"
#include "Logging/mocklogger.h"

class Logic
{
public:
    Logic();

    CaseTable caseTable() const;
    void setCaseTable(const CaseTable &caseTable);

    QString findCase(Case case_, const QString &word);
    QVector<QString> allWordsCase(const CaseList &lst, Case case_);

    Logger *logger() const;
    void setLogger(Logger *logger);

private:
    CaseTable m_caseTable;
    Logger *m_logger = &MockLogger::instance();
};

#endif // LOGIC_H
