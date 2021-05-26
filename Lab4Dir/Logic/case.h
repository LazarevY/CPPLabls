#ifndef CASE_H
#define CASE_H

#include<QVector>

enum class Case{
    Nominative, Genitive, Dative, Accusative, Creative, Prepositional
};

namespace CaseTools {
QVector<Case> allCases();
}

#endif // CASE_H
