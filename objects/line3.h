#ifndef LINE3_H
#define LINE3_H

#include <objects/vector3.h>

class Line3{
public:
    Line3(const Vector3 &a, const Vector3 &b);
    Line3(const Line3 &line);
    Line3(const Line3 &&line);
    bool operator==(const Line3 &vector);
    void operator=(const Line3 &line);
    friend std::ostream& operator<<(std::ostream &out, const Line3 &vector);
    void rotateAroundX(const Vector3 &vector, double angleInDegree);
    void rotateAroundY(const Vector3 &vector, double angleInDegree);
    void rotateAroundZ(const Vector3 &vector, double angleInDegree);
    Vector3 toVector();
    Vector3 getA();
    Vector3 getB();
    void setA(Vector3 a);
    void setB(Vector3 b);

private:
    Vector3 a;
    Vector3 b;

};

#endif // LINE3_H
