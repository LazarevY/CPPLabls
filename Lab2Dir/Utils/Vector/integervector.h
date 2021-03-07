#ifndef INTEGERVECTOR_H
#define INTEGERVECTOR_H


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

    IntegerVector operator+(const IntegerVector &other);
    IntegerVector operator-(const IntegerVector &other);
    IntegerVector operator-() const;
    IntegerVector operator+=(const IntegerVector &other);

    IntegerVector operator*(int value);
    bool operator==(const IntegerVector &other);

private:
    int m_x, m_y;
};

#endif // INTEGERVECTOR_H
