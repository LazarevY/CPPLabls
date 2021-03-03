#include "field.h"


Field::Field(size_t width, size_t height) :
    m_width(width), m_height(height)
{
//    if (!checkDimension(width, height))
//        //exception
    m_fieldStore = new int[m_width * m_height + 1]();
    m_endPtr = m_fieldStore + (m_width * m_height);
}

Field::~Field()
{
    delete [] m_fieldStore;
}

void Field::resize(size_t width, size_t height)
{
    if (checkDimension(width, height)){
        delete [] m_fieldStore;
        m_width = width;
        m_height = height;
        m_fieldStore = new int[m_width * m_height + 1];
        m_endPtr = m_fieldStore + (m_width * m_height);
    }
}

int &Field::operator()(size_t row, size_t column)
{
//    if (!checkBounds(row, column))
//        //exception
    return m_fieldStore[row * m_width + column];
}

bool Field::checkDimension(size_t width, size_t height)
{
    return width && height;
}

bool Field::checkBounds(size_t row, size_t column)
{
    return row < m_width && column < m_height;
}
