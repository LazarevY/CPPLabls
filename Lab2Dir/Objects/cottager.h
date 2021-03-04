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
            const IntegerVector &direction,
            int damageRadius);

    // BaseObject interface
    int damageRaduis() const;
    void setDamageRaduis(int damageRaduis);

    int digitCode() override;
    Path currentPath() const;
    void setCurrentPath(const Path &currentPath);


private:
    Path m_currentPath;
    int m_damageRaduis;
};

#endif // COTTAGER_H
