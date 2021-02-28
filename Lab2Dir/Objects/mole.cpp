#include "mole.h"

Mole::Mole()
{

}

Mole::Mole(int speed,
        const IntegerVector &position,
        const IntegerVector &direction,
        Gender gender,
        bool isChild,
        int damageRadius)
    :
    MovingObject(
        speed,
        position,
        direction),
    m_gender(gender),
    m_isChild(isChild),
    m_damageRadius(damageRadius)
{

}


int Mole::digitCode()
{
    return 0x4;
}

Mole::Gender Mole::gender() const
{
    return m_gender;
}

void Mole::setGender(const Gender &gender)
{
    m_gender = gender;
}

bool Mole::isChild() const
{
    return m_isChild;
}

void Mole::setIsChild(bool isChild)
{
    m_isChild = isChild;
}

Path Mole::currentPath() const
{
    return m_currentPath;
}

void Mole::setCurrentPath(const Path &currentPath)
{
    m_currentPath = currentPath;
}

int Mole::currentTicksUnderGround() const
{
    return m_currentTicksUnderGround;
}

void Mole::setCurrentTicksUnderGround(int currentTicksUnderGround)
{
    m_currentTicksUnderGround = currentTicksUnderGround;
}

int Mole::currentTicksOnGround() const
{
    return m_currentTicksOnGround;
}

void Mole::setCurrentTicksOnGround(int currentTicksOnGround)
{
    m_currentTicksOnGround = currentTicksOnGround;
}

int Mole::childTicks() const
{
    return m_childTicks;
}

void Mole::setChildTicks(int childTicks)
{
    m_childTicks = childTicks;
}

int Mole::damageRadius() const
{
    return m_damageRadius;
}

void Mole::setDamageRadius(int damageRadius)
{
    m_damageRadius = damageRadius;
}
