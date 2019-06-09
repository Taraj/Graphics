#include "square3.h"

Square3::Square3(const Vector3 &center, const int size): center(center), size(size),
    a(Line3(Vector3(-size, size, 0) + center, Vector3(-size, -size, 0) + center)),
    b(Line3(Vector3(-size, -size ,0) + center, Vector3(size, -size,0) + center)),
    c(Line3(Vector3(size, -size,0) + center, Vector3(size, size, 0) + center)),
    d(Line3(Vector3(size, size, 0) + center, Vector3(-size, size, 0) + center))
{

}
bool Square3::operator==(const Square3 &square){
    return this->center == square.center && this->size == square.size;
}

void Square3::operator=(const Square3 &square){

}

void Square3::rotateAroundX(const Vector3 &vector, double angleInDegree){
     a.rotateAroundX(vector, angleInDegree);
     b.rotateAroundX(vector, angleInDegree);
     c.rotateAroundX(vector, angleInDegree);
     d.rotateAroundX(vector, angleInDegree);
 }

void Square3::rotateAroundY(const Vector3 &vector, double angleInDegree){
    a.rotateAroundY(vector, angleInDegree);
    b.rotateAroundY(vector, angleInDegree);
    c.rotateAroundY(vector, angleInDegree);
    d.rotateAroundY(vector, angleInDegree);
}

void Square3::rotateAroundZ(const Vector3 &vector, double angleInDegree){
    a.rotateAroundZ(vector, angleInDegree);
    b.rotateAroundZ(vector, angleInDegree);
    c.rotateAroundZ(vector, angleInDegree);
    d.rotateAroundZ(vector, angleInDegree);
}

Vector3 Square3::getNormalVector(){
    this->a.toVector().crossProduct(this->b.toVector());
}

Line3 Square3::getA(){
    return this->a;
}
Line3 Square3::getB(){
    return this->b;
}
Line3 Square3::getC(){
    return this->c;
}
Line3 Square3::getD(){
    return this->d;
}
