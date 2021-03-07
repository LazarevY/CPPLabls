#include "baseobject.h"

BaseObject::BaseObject()
{

}

BaseObject::BaseObject(const IntegerVector &position) :
    m_position(position)
{

}

BaseObject::~BaseObject()
{

}

int BaseObject::id() const
{
    return m_id;
}

void BaseObject::setId(int id)
{
    m_id = id;
}

IntegerVector BaseObject::position() const
{
    return m_position;
}

void BaseObject::setPosition(const IntegerVector &position)
{
    m_position = position;
}
