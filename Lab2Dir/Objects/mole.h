#ifndef MOLE_H
#define MOLE_H

#include <QStack>

#include "movingobject.h"
using Path = QStack<IntegerVector>;

class Mole : public MovingObject
{
public:
    enum class Gender
    {
        Male, Female
    };
    Mole();
    Mole(int speed,
         const IntegerVector &position,
         const IntegerVector &direction,
         Gender gender,
         bool isChild,
         int damageRadius);

    int digitCode() override;

    Gender gender() const;
    void setGender(const Gender &gender);


    bool isChild() const;
    void setIsChild(bool isChild);

    Path currentPath() const;
    void setCurrentPath(const Path &currentPath);

    int currentTicksUnderGround() const;
    void setCurrentTicksUnderGround(int currentTicksUnderGround);

    int currentTicksOnGround() const;
    void setCurrentTicksOnGround(int currentTicksOnGround);

    int childTicks() const;
    void setChildTicks(int childTicks);

    int damageRadius() const;
    void setDamageRadius(int damageRadius);

private:
    Gender m_gender;
    bool m_isChild = false;
    Path m_currentPath;
    int m_currentTicksUnderGround = 0;
    int m_currentTicksOnGround = 0;
    int m_childTicks = 0;
    int m_damageRadius;
};

#endif // MOLE_H
