#include "square3.h"

Square3::Square3(const Vector3 &center, const int &size): center(center),
    a(Vector3(-size, -size, 0) + center),
    b(Vector3(size, -size, 0) + center),
    c(Vector3(size, size, 0) + center),
    d(Vector3(-size, size, 0) + center)
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
   return (this->a - this->b).crossProduct((this->b - this->c));
}

void Square3::translate(const Vector3 &vector){
    center.transalte(vector);
    a.transalte(vector);
    b.transalte(vector);
    c.transalte(vector);
    d.transalte(vector);
}
