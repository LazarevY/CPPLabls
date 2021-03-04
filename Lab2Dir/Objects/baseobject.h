#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include "Utils/integervector.h"


class BaseObject
{
public:
    BaseObject();
    BaseObject(const IntegerVector &position);

    /**
     * @brief The number is power of tho, unique for even type of object
     */
    virtual int digitCode() = 0;

    int id() const;


    IntegerVector position() const;
    void setPosition(const IntegerVector &position);
    void setId(int id);

protected:
    int m_id;
    IntegerVector m_position;
};

#endif // BASEOBJECT_H
