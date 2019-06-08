#include "line2.h"

Line2::Line2(const Vector2 &a, const Vector2 &b): a(a), b(b){

}

Line2::Line2(const Line2 &line): a(line.a), b(line.b){

}

Line2::Line2(const Line2 &&line): a(line.a), b(line.b){

}

bool Line2::operator==(const Line2 &vector){
    return this->a == vector.a && this->b == vector.b;
}

std::ostream& operator<<(std::ostream &out, const Line2 &line){
    out << "Line2(a: " << line.a << ", b: " << line.b << ")";
    return out;
}
void Line2::rotateAround(const Vector2 &vector, double angleInDegree){
   this->a.rotateAround(vector, angleInDegree);
   this->b.rotateAround(vector, angleInDegree);
}
Vector2 Line2::getA(){
    return a;
}
Vector2 Line2::getB(){
    return b;
}
void Line2::setA(Vector2 a){
      this->a = a;
}
void Line2::setB(Vector2 b){
    this->b = b;
}
void Line2::operator=(const Line2 &line){
    this->a = line.a;
    this->b = line.b;
}
