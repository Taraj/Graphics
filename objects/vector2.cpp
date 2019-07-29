#include "vector2.h"


Vector2::Vector2(const int &x, const int &y): x(x), y(y){
}

Vector2::Vector2(const unsigned int &x, const unsigned int &y): x(x), y(y){
}

Vector2::Vector2(const double &x, const double &y): x(x), y(y){

}

double Vector2::distance(const Vector2 &vector) const {
    return std::sqrt(
                (this->x - vector.x) * (this->x - vector.x)
                                     +
                (this->y - vector.y) * (this->y - vector.y)
                );
}

Vector2 Vector2::operator+(const Vector2 &vector) const {
    return Vector2(this->x + vector.x, this->y + vector.y);
}

Vector2 Vector2::operator-(const Vector2 &vector) const {
    return Vector2(this->x - vector.x, this->y - vector.y);
}

