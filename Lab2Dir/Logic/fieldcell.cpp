#include "fieldcell.h"

FieldCell::FieldCell(const IntegerVector &coords) :
    m_coords(coords)
{

}

FieldCell::FieldCell()
{

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

IntegerVector FieldCell::getCoords() const
{
    return m_coords;
}

void FieldCell::setCoords(const IntegerVector &Coords)
{
    m_coords = Coords;
}

int FieldCell::cellDigitCode() const
{
    int code = 0;

    for (auto a: m_objectsMap)
        code |= a->digitCode();
    return code;
}

