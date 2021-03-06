#include "field.h"
#include <QtMath>

#include "GlobalContext/globalcontext.h"

Field::Field(size_t width, size_t height) :
    m_width(width), m_height(height)
{
    if (!checkDimension(width, height)){
        GlobalContext::globalInstance()
                ->reportFatal(QString(
                                  "Cannot create field with dimension [%1x%2]")
                              .arg(width)
                              .arg(height));
        }

    else {
        initField();
    }
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
        initField();
    }
    else {
        GlobalContext::globalInstance()->reportError(
                    QString(
                        "Cannot resize field with dimension [%1x%2]")
                    .arg(width)
                    .arg(height));
    }
}

FieldCell &Field::operator()(size_t x, size_t y)
{
        if (!checkBounds(x, y))
            GlobalContext::globalInstance()->reportError(
                        QString(
                            "Cannot out of bound coordinate [%1, %2]")
                        .arg(x)
                        .arg(y));

    return m_fieldStore[y * m_width + x];
}

FieldCell &Field::operator()(const IntegerVector &coords)
{
    return (*this)(coords.x(), coords.y());
}

const FieldCell &Field::operator()(size_t x, size_t y) const
{
    return m_fieldStore[y * m_width + x];
}

void Field::add(const IntegerVector &coords, BaseObject *o)
{
    m_currentCoordMap[o->id()] = coords;
    (*this)(coords).add(o);
}

void Field::remove(BaseObject *o)
{
    (*this)(m_currentCoordMap[o->id()]).remove(o);
    m_currentCoordMap.remove(o->id());
}

void Field::move(const IntegerVector &toCoords, BaseObject *o)
{
    remove(o);
    add(toCoords, o);
}

IntegerVector Field::fixCoorsByFieldBounds(const IntegerVector &v)
{
    return IntegerVector(
                qMin(static_cast<int>(qMax(0, v.x())), static_cast<int>(m_width - 1)),
                qMin(static_cast<int>(qMax(0, v.y())), static_cast<int>(m_height - 1)));
}

IntegerVector Field::size() const
{
    return IntegerVector(m_width, m_height);
}

bool Field::inBounds(const IntegerVector &v) const
{
    return v.x() >= 0 && v.y() >= 0 &&
            v.x() < static_cast<int>(m_width) && v.y() < static_cast<int>(m_height);
}

bool Field::checkDimension(size_t width, size_t height)
{
    return width && height;
}

bool Field::checkBounds(size_t x, size_t y)
{
    return x < m_width && y < m_height;
}

void Field::initField()
{
    m_fieldStore = new FieldCell[m_width * m_height + 1];
    m_endPtr = m_fieldStore + (m_width * m_height);
    int cellCounter = 0;
    for (auto *cell = m_fieldStore; cell != m_endPtr; ++cell, cellCounter++){
        cell->setCoords(IntegerVector(
                            cellCounter % m_width,
                            cellCounter / m_width));
    }
}

size_t Field::height() const
{
    return m_height;
}

size_t Field::width() const
{
    return m_width;
}
