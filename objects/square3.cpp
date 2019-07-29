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
    this->a = square.a;
     this->b = square.b;
     this->c = square.c;
     this->d = square.d;
     this->center = square.center;
}

void Square3::rotateAroundX(const Vector3 &vector, double angleInDegree){
     center.rotateAroundX(vector, angleInDegree);
     a.rotateAroundX(vector, angleInDegree);
     b.rotateAroundX(vector, angleInDegree);
     c.rotateAroundX(vector, angleInDegree);
     d.rotateAroundX(vector, angleInDegree);
 }

void Square3::rotateAroundY(const Vector3 &vector, double angleInDegree){
    center.rotateAroundY(vector, angleInDegree);
    a.rotateAroundY(vector, angleInDegree);
    b.rotateAroundY(vector, angleInDegree);
    c.rotateAroundY(vector, angleInDegree);
    d.rotateAroundY(vector, angleInDegree);
}

void Square3::rotateAroundZ(const Vector3 &vector, double angleInDegree){
    center.rotateAroundZ(vector, angleInDegree);
    a.rotateAroundZ(vector, angleInDegree);
    b.rotateAroundZ(vector, angleInDegree);
    c.rotateAroundZ(vector, angleInDegree);
    d.rotateAroundZ(vector, angleInDegree);
}

Vector3 Square3::getNormalVector(){
   return this->a.toVector().crossProduct(this->b.toVector());
}

void Square3::translate(const Vector3 &vector){
    center.transalte(vector);
    a.translate(vector);
    b.translate(vector);
    c.translate(vector);
    d.translate(vector);
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
