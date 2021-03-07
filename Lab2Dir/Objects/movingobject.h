#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "baseobject.h"

#include "Utils/Vector/integervector.h"


class MovingObject: public BaseObject
{
public:
    MovingObject();
    MovingObject(int speed, const IntegerVector &position, const IntegerVector &direction);

    IntegerVector direction() const;
    void setDirection(const IntegerVector &direction);

    int speed() const;
    void setSpeed(int speed);

protected:
    int m_speed;
    IntegerVector m_direction;
};

#endif // MOVINGOBJECT_H
