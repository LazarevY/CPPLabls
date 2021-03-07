#include "logic.h"

Logic::Logic(Field *field) :
    m_field(field)
{

}

Logic::~Logic()
{
    for (auto kv = m_resourceCapturedObjects.begin(); kv != m_resourceCapturedObjects.end(); ++kv)
        delete kv.value();
}

void Logic::addObject(BaseObject *o, const IntegerVector &position, bool resouceCapture)
{
    o->setId(m_idCounter++);
    m_objectsMap[o->id()] = o;
    m_field->add(position, o);
    if (resouceCapture)
        m_resourceCapturedObjects[o->id()] = o;
}

void Logic::addObject(BaseObject *o, bool resouceCapture)
{
    addObject(o, o->position(), resouceCapture);
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

Path Logic::getPath(const IntegerVector &from, const IntegerVector &to)
{
    return Path();
}

IntegerVector Logic::fixCoords(const IntegerVector &coords)
{
    return m_field->fixSize(coords);
}

void Logic::processObject(BaseObject *o)
{
    for (auto handler: m_handlersMap.values(typeid(o).hash_code()))
        handler->process(o);
}
