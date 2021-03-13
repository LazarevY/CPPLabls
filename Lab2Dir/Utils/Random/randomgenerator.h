#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <QRandomGenerator>
#include <QDateTime>

class RandomGenerator
{
public:
    RandomGenerator();

    static QRandomGenerator getNewRandom();
};

#endif // RANDOM_H
