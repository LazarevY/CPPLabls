#include "probabilitychecker.h"

ProbabilityChecker::ProbabilityChecker()
{

}

bool ProbabilityChecker::check(int value)
{
    return m_gen.bounded(0, 100) < value;
}
