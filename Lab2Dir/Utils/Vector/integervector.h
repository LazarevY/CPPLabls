#ifndef INTEGERVECTOR_H
#define INTEGERVECTOR_H

#include <QtGlobal>

class IntegerVector
{
public:
    IntegerVector();
    IntegerVector(int x, int y);

    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);

    void normalize();

    IntegerVector normalized();

    IntegerVector operator+(const IntegerVector &other) const;
    IntegerVector operator-(const IntegerVector &other) const;
    IntegerVector operator-() const;
    IntegerVector operator+=(const IntegerVector &other);

    IntegerVector operator*(int value);
    bool operator==(const IntegerVector &other);

    double lenghtSqr() const;

private:
    int m_x, m_y;
};

template <>
inline const IntegerVector &qMin<IntegerVector>(const IntegerVector &a, const IntegerVector &b){
    return a.lenghtSqr() < b.lenghtSqr()? a : b;
}

#endif // INTEGERVECTOR_H
