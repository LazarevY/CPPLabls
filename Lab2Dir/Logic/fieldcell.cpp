#include "fieldcell.h"

FieldCell::FieldCell(int x, int y) :
    m_x(x), m_y(y)
{

}

FieldCell::FieldCell() : FieldCell(0, 0)
{

}

int FieldCell::x() const
{
    return m_x;
}

int FieldCell::y() const
{
    return m_y;
}

void FieldCell::setY(int y)
{
    m_y = y;
}

void FieldCell::remove(BaseObject *o)
{
    m_objectsMap.remove(o->id());
}

void FieldCell::add(BaseObject *o)
{
    m_objectsMap[o->id()] = o;
}

QVector<BaseObject *> FieldCell::getAllObjects()
{
    return m_objectsMap.values().toVector();
}

void FieldCell::setX(int x)
{
    m_x = x;
}
