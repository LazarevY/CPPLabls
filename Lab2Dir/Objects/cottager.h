#ifndef COTTAGER_H
#define COTTAGER_H

#include <QStack>

#include "movingobject.h"

using Path = QStack<IntegerVector>;

class Cottager : public MovingObject
{
public:
    Cottager();
    Cottager(
            int speed,
            const IntegerVector &position,
            const IntegerVector &direction);

    // BaseObject interface
public:
    int digitCode() override;
    Path m_currentPath;
};

#endif // COTTAGER_H
