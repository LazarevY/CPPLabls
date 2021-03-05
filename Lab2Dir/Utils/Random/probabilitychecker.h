#ifndef RANDOM_H
#define RANDOM_H

#include <QRandomGenerator>

class ProbabilityChecker
{
public:
    ProbabilityChecker();

    bool check(int value);


private:
    QRandomGenerator m_gen;
};

#endif // RANDOM_H
