#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include <cmath>

class Vector2 {
public:
    Vector2(const int &x, const int &y);
    Vector2(const Vector2 &point);
    Vector2(const Vector2 &&point);
    double distance(const Vector2 &point);
    void rotateAround(const Vector2 &point, double angleInDegree);
    Vector2 operator+(const Vector2 &point);
    Vector2 operator-(const Vector2 &point);
    bool operator==(const Vector2 &point);
    friend std::ostream& operator<<(std::ostream &out, const Vector2 &point);
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
