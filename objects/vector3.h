#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

class Vector3 {
public:
    Vector3(const int &x, const int &y, const int &z);
    Vector3(const double &x, const double &y, const double &z);

    void rotateAroundX(const Vector3 &vector, const double &angleInDegree);
    void rotateAroundY(const Vector3 &vector, const double &angleInDegree);
    void rotateAroundZ(const Vector3 &vector, const double &angleInDegree);
    void transalte(const Vector3 &vector);

    Vector3 operator+(const Vector3 &vector) const;
    Vector3 operator-(const Vector3 &vector) const;


    bool operator==(const Vector3& rhs){
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    double x;
    double y;
    double z;
};

#endif // VECTOR3_H
