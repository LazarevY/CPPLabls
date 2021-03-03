#include "baseobject.h"

BaseObject::BaseObject()
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
