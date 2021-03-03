#ifndef FIELDCELL_H
#define FIELDCELL_H

#include "Objects/baseobject.h"

#include <QVector>
#include <QMap>

class FieldCell
{
public:
    FieldCell(int x, int y);
    FieldCell();

    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);

    void remove(BaseObject *o);
    void add(BaseObject *o);

    QVector<BaseObject *> getAllObjects();


private:
    int m_x, m_y;
    QMap<int, BaseObject *> m_objectsMap;
};

#endif // FIELDCELL_H
