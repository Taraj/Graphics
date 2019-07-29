#ifndef LINE3_H
#define LINE3_H

#include <objects/vector3.h>

class Line3{
public:
    Line3(const Vector3 &a, const Vector3 &b);
    void rotateAroundX(const Vector3 &vector, const double &angleInDegree);
    void rotateAroundY(const Vector3 &vector,  const double &angleInDegree);
    void rotateAroundZ(const Vector3 &vector,  const double &angleInDegree);
    void translate(const Vector3 &vector);

    Vector3 toVector() const;

    Vector3 a;
    Vector3 b;

};

#endif // LINE3_H
