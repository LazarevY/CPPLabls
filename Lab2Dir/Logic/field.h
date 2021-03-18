#ifndef FIELD_H
#define FIELD_H

#include <stdlib.h>

#include "fieldcell.h"

class Field
{
public:
    Field(size_t width, size_t height);
    ~Field();

    Field(const Field& ) = delete;
    Field(Field&& ) = delete;
    Field& operator=(const Field& ) = delete;
    Field& operator=(Field&& ) = delete;

    void resize(size_t width, size_t height);
    size_t width() const;
    size_t height() const;

    IntegerVector fixCoorsByFieldBounds(const IntegerVector &v); // fit coords to field bounds
    IntegerVector size() const;


    void add(const IntegerVector &coords, BaseObject *o);
    void remove(BaseObject * o);
    void move(const IntegerVector &toCoords, BaseObject *o);


    bool inBounds(const IntegerVector &v) const;

    FieldCell& operator()(size_t row, size_t column);
    FieldCell& operator()(const IntegerVector &coords);
    const FieldCell &operator()(size_t x, size_t y) const;

private:
    bool checkDimension(size_t width, size_t height);
    bool checkBounds(size_t row, size_t column);
    void initField();

private:
    FieldCell *m_fieldStore;
    FieldCell *m_endPtr;
    QMap<int, IntegerVector> m_currentCoordMap;
    size_t m_width;
    size_t m_height;
};

#endif // FIELD_H
