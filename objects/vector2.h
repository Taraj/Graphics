#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <cmath>

class Vector2 {
public:
    Vector2(const int &x = 0, const int &y = 0);
    Vector2(const Vector2 &vector);
    Vector2(const Vector2 &&vector);
    double distance(const Vector2 &vector);
    void rotateAround(const Vector2 &vector, double angleInDegree);
    Vector2 operator+(const Vector2 &vector);
    Vector2 operator-(const Vector2 &vector);
    void operator=(const Vector2 &vector);
    bool operator==(const Vector2 &vector);
    friend std::ostream& operator<<(std::ostream &out, const Vector2 &vector);
    int getX();
    int getY();
    void setX(const int &x);
    void setY(const int &y);

private:
    Vector2(const double &x, const double &y);
    double x;
    double y;
};
#endif // POINT2D_H
