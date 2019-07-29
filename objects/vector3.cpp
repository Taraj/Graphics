#include "vector3.h"



Vector3::Vector3(const int &x, const int &y, const int &z): x(x), y(y), z(z){
}
Vector3::Vector3(const double &x, const double &y, const double &z): x(x), y(y), z(z){
}

void Vector3::rotateAroundX(const Vector3 &vector,  const double &angleInDegree){
    const double angleInRadians = angleInDegree * (M_PI/180);
    const double cosValue = cos(angleInRadians);
    const double sinValue = sin(angleInRadians);

    const double ytmp = cosValue * (this->y - vector.y) - sinValue * (this->z - vector.z) + vector.y;
    const double ztmp = sinValue * (this->y - vector.y) + cosValue * (this->z - vector.z) + vector.z;

    this->y = ytmp;
    this->z = ztmp;

}
void Vector3::rotateAroundY(const Vector3 &vector,  const double &angleInDegree){
    const double angleInRadians = angleInDegree * (M_PI/180);
    const double cosValue = cos(angleInRadians);
    const double sinValue = sin(angleInRadians);
    const double ztmp = cosValue * (this->z - vector.z) - sinValue * (this->x - vector.x) + vector.z;

    const double xtmp = sinValue * (this->z - vector.z) + cosValue * (this->x - vector.x) + vector.x;
    this->x = xtmp;
    this->z = ztmp;
}
void Vector3::rotateAroundZ(const Vector3 &vector, const double &angleInDegree){
    const double angleInRadians = angleInDegree * (M_PI/180);
    const double cosValue = cos(angleInRadians);
    const double sinValue = sin(angleInRadians);
    const double xtmp = cosValue * (this->x - vector.x) - sinValue * (this->y - vector.y) + vector.x;
    const double ytmp = sinValue * (this->x - vector.x) + cosValue * (this->y - vector.y) + vector.y;
    this->x = xtmp;
    this->y = ytmp;
}

Vector3 Vector3::operator+(const Vector3 &vector) const{
    return Vector3(this->x + vector.x, this->y + vector.y, this->z + vector.z);
}

Vector3 Vector3::operator-(const Vector3 &vector) const {
     return Vector3(this->x - vector.x, this->y - vector.y, this->z - vector.z);
}

void Vector3::transalte(const Vector3 &vector){
    this->x += vector.x;
    this->y += vector.y;
    this->z += vector.z;
}
