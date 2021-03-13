#include "cottager.h"

Cottager::Cottager()
{

}

Cottager::Cottager(
        int speed,
        const IntegerVector &position,
        const IntegerVector &direction,
        int damageRadius)
    :
    MovingObject(
        speed,
        position,
        direction),
  m_damageRaduis(damageRadius)
{

}


int Cottager::digitCode()
{
    return 0x1;
}

Path Cottager::currentPath() const
{
    return m_currentPath;
}

void Cottager::setCurrentPath(const Path &currentPath)
{
    m_currentPath = currentPath;
}

int Cottager::damageRaduis() const
{
    return m_damageRaduis;
}

void Cottager::setDamageRaduis(int damageRaduis)
{
    m_damageRaduis = damageRaduis;
}
