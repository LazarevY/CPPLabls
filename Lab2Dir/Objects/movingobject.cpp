#include "movingobject.h"

MovingObject::MovingObject()
{

}

MovingObject::MovingObject(
        int speed,
        const IntegerVector &position,
        const IntegerVector &direction) :
    BaseObject(position),
    m_speed(speed),
    m_direction(direction)
{

}


IntegerVector MovingObject::direction() const
{
    return m_direction;
}

void MovingObject::setDirection(const IntegerVector &direction)
{
    m_direction = direction;
}

int MovingObject::speed() const
{
    return m_speed;
}

void MovingObject::setSpeed(int speed)
{
    m_speed = speed;
}

