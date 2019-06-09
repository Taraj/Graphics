#include "line3.h"

Line3::Line3(const Vector3 &a, const Vector3 &b): a(a), b(b){

}

Line3::Line3(const Line3 &line): a(line.a), b(line.b){

}

Line3::Line3(const Line3 &&line): a(line.a), b(line.b){

}

bool Line3::operator==(const Line3 &vector){
    return this->a == vector.a && this->b == vector.b;
}

std::ostream& operator<<(std::ostream &out, const Line3 &line){
    out << "Line2(a: " << line.a << ", b: " << line.b << ")";
    return out;
}

void Line3::rotateAroundX(const Vector3 &vector, double angleInDegree){
   this->a.rotateAroundX(vector, angleInDegree);
   this->b.rotateAroundX(vector, angleInDegree);
}

void Line3::rotateAroundY(const Vector3 &vector, double angleInDegree){
   this->a.rotateAroundY(vector, angleInDegree);
   this->b.rotateAroundY(vector, angleInDegree);
}


void Line3::rotateAroundZ(const Vector3 &vector, double angleInDegree){
   this->a.rotateAroundZ(vector, angleInDegree);
   this->b.rotateAroundZ(vector, angleInDegree);
}

void Line3::translate(const Vector3 &vector){
    this->a.transalte(vector);
    this->b.transalte(vector);
}

Vector3 Line3::getA(){
    return a;
}

Vector3 Line3::getB(){
    return b;
}

void Line3::setA(Vector3 a){
      this->a = a;
}

void Line3::setB(Vector3 b){
    this->b = b;
}

void Line3::operator=(const Line3 &line){
    this->a = line.a;
    this->b = line.b;
}

Vector3 Line3::toVector(){
    return this->a - this->b;
}
