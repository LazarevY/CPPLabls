#include "integervector.h"
#include <QtMath>
IntegerVector::IntegerVector() : IntegerVector(0,0)
{

}

IntegerVector::IntegerVector(int x, int y) :
    m_x(x), m_y(y)
{

}

int IntegerVector::x() const
{
    return m_x;
}

void IntegerVector::setX(int x)
{
    m_x = x;
}

int IntegerVector::y() const
{
    return m_y;
}

void IntegerVector::setY(int y)
{
    m_y = y;
}

void IntegerVector::normalize()
{
    m_x = m_x? m_x / qAbs(m_x) : 0;
    m_y = m_y? m_y / qAbs(m_y) : 0;
}

IntegerVector IntegerVector::normalized()
{
    auto newVector = IntegerVector(m_x, m_y);
    newVector.normalize();
    return newVector;
}

IntegerVector IntegerVector::operator+(const IntegerVector &other)
{
    return IntegerVector(m_x + other.m_x, m_y + other.m_y);
}

IntegerVector IntegerVector::operator-(const IntegerVector &other)
{
    return *this + (-other);
}

IntegerVector IntegerVector::operator-() const
{
    return IntegerVector(-m_x, -m_y);
}

IntegerVector IntegerVector::operator +=(const IntegerVector &other)
{
    return *this + other;
}

IntegerVector IntegerVector::operator*(int value)
{
    return IntegerVector(m_x * value, m_y * value);
}

bool IntegerVector::operator==(const IntegerVector &other)
{
    return m_x == other.m_x && m_y == other.m_y;
}
