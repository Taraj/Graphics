#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

class Vector3{
public:
    Vector3(const int &x = 0, const int &y = 0, const int &z = 0);
    Vector3(const Vector3 &vector);
    Vector3(const Vector3 &&vector);
    double distance(const Vector3 &vector);
    void rotateAroundX(const Vector3 &vector, double angleInDegree);
    void rotateAroundY(const Vector3 &vector, double angleInDegree);
    void rotateAroundZ(const Vector3 &vector, double angleInDegree);
    Vector3 crossProduct(const Vector3 &vector);
    Vector3 operator+(const Vector3 &vector);
    Vector3 operator-(const Vector3 &vector);
    void operator=(const Vector3 &vector);
    bool operator==(const Vector3 &vector);
    friend std::ostream& operator<<(std::ostream &out, const Vector3 &vector);
    int getX();
    int getY();
    int getZ();
    void setX(const int &x);
    void setY(const int &y);
    void setZ(const int &y);

private:
    Vector3(const double &x, const double &y, const double &z);
    double x;
    double y;
    double z;
};

#endif // VECTOR3_H
