#include "vector2.h"


Vector2::Vector2(const int &x, const int &y): x(x), y(y){
}

Vector2::Vector2(const double &x, const double &y): x(x), y(y){
}

Vector2::Vector2(const unsigned int &x, const unsigned int &y): x(x), y(y)
{

}

Vector2::Vector2(const Vector2 &vector): x(vector.x), y(vector.y){
}

Vector2::Vector2(const Vector2 &&vector): x(vector.x), y(vector.y){
}

bool Vector2::operator==(const Vector2 &vector){
    return this->x == vector.x && this->y == vector.y;
}

std::ostream& operator<<(std::ostream &out, const Vector2 &vector){
    out << "Vector2(x: " << vector.x << ", y: " << vector.y <<")";
    return out;
}

double Vector2::distance(const Vector2 &vector) const{
    return std::sqrt(
                (this->x - vector.x) * (this->x - vector.x)
                                     +
                (this->y - vector.y) * (this->y - vector.y)
                );
}

void Vector2::rotateAround(const Vector2 &vector, const double angleInDegree){
    const double angleInRadians = angleInDegree * (M_PI/180);
    const double cosValue = cos(angleInRadians);
    const double sinValue = sin(angleInRadians);
    const double xtmp = cosValue * (this->x - vector.x) - sinValue * (this->y - vector.y) + vector.x;
    const double ytmp = sinValue * (this->x - vector.x) + cosValue * (this->y - vector.y) + vector.y;
    this->x = xtmp;
    this->y = ytmp;
}

Vector2 Vector2::operator+(const Vector2 &vector){
    return Vector2(this->x + vector.x, this->y + vector.y);
}

Vector2 Vector2::operator-(const Vector2 &vector){
    return Vector2(this->x - vector.x, this->y - vector.y);
}

void Vector2::operator=(const Vector2 &vector){
    this->x = vector.x;
    this->y = vector.y;
}

int Vector2::getX(){
    return static_cast<int>(this->x);
}

int Vector2::getY(){
    return static_cast<int>(this->y);
}

void Vector2::setX(const int &x){
    this->x = x;
}

void Vector2::setY(const int &y){
    this->y = y;
}
