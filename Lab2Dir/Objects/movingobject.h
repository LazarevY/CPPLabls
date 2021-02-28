#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "baseobject.h"

#include "Utils/integervector.h"


class MovingObject: public BaseObject
{
public:
    MovingObject();
    MovingObject(int speed, const IntegerVector &position, const IntegerVector &direction);
    IntegerVector position() const;
    void setPosition(const IntegerVector &position);

    IntegerVector direction() const;
    void setDirection(const IntegerVector &direction);

protected:
    int m_speed;
    IntegerVector m_position;
    IntegerVector m_direction;
};

#endif // MOVINGOBJECT_H
