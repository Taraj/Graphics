#ifndef SQUARE3_H
#define SQUARE3_H

#include <objects/vector3.h>
#include <objects/line3.h>

class Square3{
public:
    Square3(const Vector3 &center, const int size);
    bool operator==(const Square3 &square);
    void operator=(const Square3 &square);
    void rotateAroundX(const Vector3 &vector, double angleInDegree);
    void rotateAroundY(const Vector3 &vector, double angleInDegree);
    void rotateAroundZ(const Vector3 &vector, double angleInDegree);
    Vector3 getNormalVector();

    void translate(const Vector3 &vector);

    Line3 getA();
    Line3 getB();
    Line3 getC();
    Line3 getD();
    Vector3 center;
private:

    int size;
    Line3 a, b, c, d;
};

#endif // SQUARE3_H
