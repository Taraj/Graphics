#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <cmath>

class Vector2 {
public:
    Vector2(const int &x, const int &y);
    Vector2(const unsigned int &x, const unsigned int &y);
    Vector2(const double &x, const double &y);

    double distance(const Vector2 &vector) const;
    Vector2 operator+(const Vector2 &vector) const;
    Vector2 operator-(const Vector2 &vector) const;

    double x;
    double y;
};
#endif // POINT2D_H
