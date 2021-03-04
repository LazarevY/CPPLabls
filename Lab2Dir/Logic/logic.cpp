#include "logic.h"

Logic::Logic(Field *field) :
    m_field(field)
{

}

void Logic::addObject(BaseObject *o, const IntegerVector &position)
{
    o->setId(m_idCounter++);
    m_objectsMap[o->id()] = o;
    m_field->add(position, o);
}

void Logic::addObject(BaseObject *o)
{
    addObject(o, o->position());
}

void Logic::moveObject(BaseObject *o, const IntegerVector &toCell)
{
    if (!m_objectsMap.contains(o->id())){
        return;
    }

    m_field->move(toCell, o);

}

void Logic::removeObject(BaseObject *o)
{
    if (!m_objectsMap.contains(o->id())){
        return;
    }

    m_objectsMap.take(o->id());
    m_field->remove(o);
}
