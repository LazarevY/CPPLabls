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

    FieldCell& operator()(size_t row, size_t column);

private:
    bool checkDimension(size_t width, size_t height);
    bool checkBounds(size_t row, size_t column);

private:
    FieldCell *m_fieldStore;
    FieldCell *m_endPtr;
    size_t m_width;
    size_t m_height;
};

#endif // FIELD_H
