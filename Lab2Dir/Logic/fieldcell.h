#ifndef FIELDCELL_H
#define FIELDCELL_H

#include "Objects/baseobject.h"
#include "Utils/integervector.h"

#include <QVector>
#include <QMap>

class FieldCell
{
public:
    FieldCell(const IntegerVector & coords);
    FieldCell();


    void remove(BaseObject *o);
    void add(BaseObject *o);

    QVector<BaseObject *> getAllObjects();


    IntegerVector getCoords() const;
    void setCoords(const IntegerVector &Coords);

private:
    IntegerVector m_coords;
    QMap<int, BaseObject *> m_objectsMap;
};

#endif // FIELDCELL_H
