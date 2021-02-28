#include "movingobject.h"

MovingObject::MovingObject()
{

}

MovingObject::MovingObject(
        int speed,
        const IntegerVector &position,
        const IntegerVector &direction) :
    m_speed(speed),
    m_position(position),
    m_direction(direction)
{

}

IntegerVector MovingObject::position() const
{
    return m_position;
}

void MovingObject::setPosition(const IntegerVector &position)
{
    m_position = position;
}

IntegerVector MovingObject::direction() const
{
    return m_direction;
}

void MovingObject::setDirection(const IntegerVector &direction)
{
    m_direction = direction;
}

