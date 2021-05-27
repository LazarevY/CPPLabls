#include "case.h"

QVector<Case> CaseTools::allCases()
{
    return {Case::Nominative, Case::Genitive, Case::Dative,Case::Accusative, Case::Creative, Case::Prepositional};
}

QString CaseTools::caseEnumToStr(Case case_)
{
    switch (case_) {
    case Case::Nominative:return "nominative";
    case Case::Genitive:return "genetive";
    case Case::Dative:return "dative";
    case Case::Accusative: return "accusative";
    case Case::Creative : return "creative";
    case Case::Prepositional : return "prepositional";
    }
}
