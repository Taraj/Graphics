#include "square3.h"

Square3::Square3(const Vector3 &center, const int &size): center(center),
    a(Line3(Vector3(-size, size, 0) + center, Vector3(-size, -size, 0) + center)),
    b(Line3(Vector3(-size, -size ,0) + center, Vector3(size, -size,0) + center)),
    c(Line3(Vector3(size, -size,0) + center, Vector3(size, size, 0) + center)),
    d(Line3(Vector3(size, size, 0) + center, Vector3(-size, size, 0) + center))
{

}

void Square3::rotateAroundX(const Vector3 &vector, const double &angleInDegree){
     center.rotateAroundX(vector, angleInDegree);
     a.rotateAroundX(vector, angleInDegree);
     b.rotateAroundX(vector, angleInDegree);
     c.rotateAroundX(vector, angleInDegree);
     d.rotateAroundX(vector, angleInDegree);
 }

void Square3::rotateAroundY(const Vector3 &vector, const double &angleInDegree){
    center.rotateAroundY(vector, angleInDegree);
    a.rotateAroundY(vector, angleInDegree);
    b.rotateAroundY(vector, angleInDegree);
    c.rotateAroundY(vector, angleInDegree);
    d.rotateAroundY(vector, angleInDegree);
}

void Square3::rotateAroundZ(const Vector3 &vector, const double & angleInDegree){
    center.rotateAroundZ(vector, angleInDegree);
    a.rotateAroundZ(vector, angleInDegree);
    b.rotateAroundZ(vector, angleInDegree);
    c.rotateAroundZ(vector, angleInDegree);
    d.rotateAroundZ(vector, angleInDegree);
}

Vector3 Square3::getNormalVector() const {
   return this->a.toVector().crossProduct(this->b.toVector());
}

void Square3::translate(const Vector3 &vector){
    center.transalte(vector);
    a.translate(vector);
    b.translate(vector);
    c.translate(vector);
    d.translate(vector);
}
