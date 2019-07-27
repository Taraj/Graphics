#include "vector3.h"



Vector3::Vector3(const int &x, const int &y, const int &z): x(x), y(y), z(z){

}
Vector3::Vector3(const double &x, const double &y, const double &z): x(x), y(y), z(z){

}
Vector3::Vector3(const Vector3 &vector): x(vector.x), y(vector.y), z(vector.z){

}
Vector3::Vector3(const Vector3 &&vector): x(vector.x), y(vector.y), z(vector.z){

}
double Vector3::distance(const Vector3 &vector){
    return std::sqrt(
                (this->x - vector.x) * (this->x - vector.x)
                                     +
                (this->y - vector.y) * (this->y - vector.y)
                                     +
                (this->z - vector.z) * (this->z - vector.z)
                );
}
void Vector3::rotateAroundX(const Vector3 &vector, double angleInDegree){
    const double angleInRadians = angleInDegree * (M_PI/180);
    const double cosValue = cos(angleInRadians);
    const double sinValue = sin(angleInRadians);

    const double ytmp = cosValue * (this->y - vector.y) - sinValue * (this->z - vector.z) + vector.y;
    const double ztmp = sinValue * (this->y - vector.y) + cosValue * (this->z - vector.z) + vector.z;

    this->y = ytmp;
    this->z = ztmp;

}
void Vector3::rotateAroundY(const Vector3 &vector, double angleInDegree){
    const double angleInRadians = angleInDegree * (M_PI/180);
    const double cosValue = cos(angleInRadians);
    const double sinValue = sin(angleInRadians);
    const double ztmp = cosValue * (this->z - vector.z) - sinValue * (this->x - vector.x) + vector.z;

    const double xtmp = sinValue * (this->z - vector.z) + cosValue * (this->x - vector.x) + vector.x;
    this->x = xtmp;
    this->z = ztmp;
}
void Vector3::rotateAroundZ(const Vector3 &vector, double angleInDegree){
    const double angleInRadians = angleInDegree * (M_PI/180);
    const double cosValue = cos(angleInRadians);
    const double sinValue = sin(angleInRadians);
    const double xtmp = cosValue * (this->x - vector.x) - sinValue * (this->y - vector.y) + vector.x;
    const double ytmp = sinValue * (this->x - vector.x) + cosValue * (this->y - vector.y) + vector.y;
    this->x = xtmp;
    this->y = ytmp;
}
Vector3 Vector3::operator+(const Vector3 &vector){
       return Vector3(this->x + vector.x, this->y + vector.y, this->z + vector.z);
}
Vector3 Vector3::operator-(const Vector3 &vector){
     return Vector3(this->x - vector.x, this->y - vector.y, this->z - vector.z);
}
bool Vector3::operator==(const Vector3 &vector){
    return this->x == vector.x && this->y == vector.y && this->z == vector.z;
}

void Vector3::transalte(const Vector3 &vector){
    this->x+=vector.x;
    this->y+=vector.y;
    this->z+=vector.z;
}

std::ostream& operator<<(std::ostream &out, const Vector3 &vector){
    out << "Vector3(x: " << vector.x << ", y: " << vector.y <<", z: " << vector.z <<")";
    return out;
}

int Vector3::getX(){
    return static_cast<int>(this->x);
}

int Vector3::getY(){
    return static_cast<int>(this->y);
}

int Vector3::getZ(){
    return static_cast<int>(this->z);
}

void Vector3::setX(const int &x){
    this->x = x;
}

void Vector3::setY(const int &y){
    this->y = y;
}

void Vector3::setZ(const int &z){
    this->z = z;
}

void Vector3::operator=(const Vector3 &vector){
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
}

Vector3 Vector3::crossProduct(const Vector3 &vector){
  return Vector3(
              this->y*vector.z - this->z*vector.y,
              this->z*vector.x - this->x*vector.z,
              this->x*vector.y - this->y*vector.x
              );
}

double Vector3::dotProduct(const Vector3 &vector){
    return this->x * vector.x + this->y * vector.y + this->z * vector.z;
}

double Vector3::angle(const Vector3 &vector){
return this->dotProduct(vector)/(this->length()*vector.length());
}

double Vector3::length() const
{
    return  std::sqrt(x*x+y*y+z*z);
}
