#include "probabilitychecker.h"
#include <QDateTime>
ProbabilityChecker::ProbabilityChecker()
{

}

bool ProbabilityChecker::check(int value)
{
    m_gen.seed(QDateTime::currentMSecsSinceEpoch());
    return m_gen.bounded(0, 100) < value;
}
