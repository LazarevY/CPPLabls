#include "randomgenerator.h"

RandomGenerator::RandomGenerator()
{

}

QRandomGenerator RandomGenerator::getNewRandom()
{
    return QRandomGenerator(QDateTime::currentMSecsSinceEpoch());
}
