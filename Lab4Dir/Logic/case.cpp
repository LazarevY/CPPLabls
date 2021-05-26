#include "case.h"

QVector<Case> CaseTools::allCases()
{
    return {Case::Nominative, Case::Genitive, Case::Dative,Case::Accusative, Case::Creative, Case::Prepositional};
}
