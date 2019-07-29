#ifndef SQUARE3_H
#define SQUARE3_H

#include <objects/vector3.h>

class Square3{
public:
    Square3(const Vector3 &center, const int &size);
    void rotateAroundX(const Vector3 &vector, const double &angleInDegree);
    void rotateAroundY(const Vector3 &vector, const double &angleInDegree);
    void rotateAroundZ(const Vector3 &vector, const double &angleInDegree);
    void translate(const Vector3 &vector);
    Vector3 getNormalVector() const;

    Vector3 center;
    Vector3 a, b, c, d;

};

#endif // SQUARE3_H
