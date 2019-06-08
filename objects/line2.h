#ifndef LINE2_H
#define LINE2_H

#include <objects/vector2.h>


class Line2{
public:
    Line2(const Vector2 &a, const Vector2 &b);
    Line2(const Line2 &line);
    Line2(const Line2 &&line);
    bool operator==(const Line2 &vector);
    void operator=(const Line2 &line);
    friend std::ostream& operator<<(std::ostream &out, const Line2 &vector);
    void rotateAround(const Vector2 &vector, double angleInDegree);
    Vector2 getA();
    Vector2 getB();
    void setA(Vector2 a);
    void setB(Vector2 b);

protected:
    Vector2 a;
    Vector2 b;
};

#endif // LINE2_H
