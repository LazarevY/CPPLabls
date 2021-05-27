#ifndef CASEDATA_H
#define CASEDATA_H

#include <QString>
#include <QMap>
#include <QVector>
#include <QSet>

#include "case.h"

using WordCases = QMap<Case, QString>;

class CaseTable
{
public:
    CaseTable();

    void addCase(Case case_, const QString &existingCase, const QString& caseWordValue);
    void setCases(const QMap<Case, QString> & cases);
    void expandCases(const QMap<Case, QString> & cases);
    QString findCase(Case case_, const QString &word) const;

    QVector<WordCases> getUnique() const;

private:
    void checkWordCasesCreated(const QString &word);
    void deleteCases(const QString &word);

private:
    QMap<QString, WordCases *> m_caseTableData;
};

#endif // CASEDATA_H
