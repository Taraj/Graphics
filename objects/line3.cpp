#include "line3.h"

Line3::Line3(const Vector3 &a, const Vector3 &b): a(a), b(b){

}

void Line3::rotateAroundX(const Vector3 &vector, const double &angleInDegree){
   this->a.rotateAroundX(vector, angleInDegree);
   this->b.rotateAroundX(vector, angleInDegree);
}

void Line3::rotateAroundY(const Vector3 &vector, const double &angleInDegree){
   this->a.rotateAroundY(vector, angleInDegree);
   this->b.rotateAroundY(vector, angleInDegree);
}

void Line3::rotateAroundZ(const Vector3 &vector, const double &angleInDegree){
   this->a.rotateAroundZ(vector, angleInDegree);
   this->b.rotateAroundZ(vector, angleInDegree);
}

void Line3::translate(const Vector3 &vector){
    this->a.transalte(vector);
    this->b.transalte(vector);
}

Vector3 Line3::toVector() const {
    return this->a - this->b;
}
