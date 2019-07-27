#include "cube.h"

Cube::Cube(const Vector3 &center, const int &size): center(center), size(size),
  a(Square3(Vector3(0,0,size) + center, size)),
  b(Square3(Vector3(0,0,size) + center, size)),
  c(Square3(Vector3(0,0,size) + center, size)),
  d(Square3(Vector3(0,0,size) + center, size)),
  e(Square3(Vector3(0,0,size) + center, size)),
  f(Square3(Vector3(0,0,size) + center, size))
{
a.rotateAroundX(center, 90);
b.rotateAroundX(center, -90);


c.rotateAroundY(center, 90);
d.rotateAroundY(center, -90);

e.rotateAroundY(center, 180);
}

void Cube::translate(const Vector3 &vector){
    center.transalte(vector);
    a.translate(vector);
    b.translate(vector);
    c.translate(vector);
    d.translate(vector);
    e.translate(vector);
    f.translate(vector);
}

void Cube::rotateAroundX(const Vector3 &vector, double angleInDegree){
      center.rotateAroundX(vector,angleInDegree);
    a.rotateAroundX(vector, angleInDegree);
    b.rotateAroundX(vector, angleInDegree);
    c.rotateAroundX(vector, angleInDegree);
    d.rotateAroundX(vector, angleInDegree);
    e.rotateAroundX(vector, angleInDegree);
    f.rotateAroundX(vector, angleInDegree);
}

void Cube::rotateAroundY(const Vector3 &vector, double angleInDegree){
    center.rotateAroundY(vector,angleInDegree);
    a.rotateAroundY(vector, angleInDegree);
    b.rotateAroundY(vector, angleInDegree);
    c.rotateAroundY(vector, angleInDegree);
    d.rotateAroundY(vector, angleInDegree);
    e.rotateAroundY(vector, angleInDegree);
    f.rotateAroundY(vector, angleInDegree);
}

void Cube::rotateAroundZ(const Vector3 &vector, double angleInDegree){
    center.rotateAroundZ(vector,angleInDegree);
    a.rotateAroundZ(vector, angleInDegree);
    b.rotateAroundZ(vector, angleInDegree);
    c.rotateAroundZ(vector, angleInDegree);
    d.rotateAroundZ(vector, angleInDegree);
    e.rotateAroundZ(vector, angleInDegree);
    f.rotateAroundZ(vector, angleInDegree);
}
