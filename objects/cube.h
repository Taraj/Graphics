#ifndef CUBE_H
#define CUBE_H

#include <objects/vector3.h>
#include <objects/square3.h>
class Cube{
public:
    Cube(const Vector3 &center, const int &size);

    void translate(const Vector3 &vector);
    void rotateAroundX(const Vector3 &vector, double angleInDegree);
    void rotateAroundY(const Vector3 &vector, double angleInDegree);
    void rotateAroundZ(const Vector3 &vector, double angleInDegree);

    Vector3 center;
    int size;
    Square3 a, b, c, d, e, f;

};

#endif // CUBE_H
