#ifndef CASE_H
#define CASE_H

#include<QVector>
#include <QObject>

enum class Case{
    Nominative, Genitive, Dative, Accusative, Creative, Prepositional
};

namespace CaseTools {
QVector<Case> allCases();
QString caseEnumToStr(Case case_);
}

#endif // CASE_H
