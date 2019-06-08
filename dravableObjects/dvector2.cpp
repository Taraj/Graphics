#include "dvector2.h"

DVector2::DVector2(const int &x, const int &y, const QColor &color): Vector2(x,y), color(color){

}
DVector2::DVector2(const Vector2 &vector, const QColor &color): Vector2 (vector), color(color){

}
DVector2::DVector2(const DVector2 &vector):Vector2 (vector.x, vector.y), color(vector.color){

}
DVector2::DVector2(const DVector2 &&vector):Vector2 (vector.x, vector.y), color(vector.color){

}

void DVector2::operator=(const DVector2 &vector){
    this->x = vector.x;
    this->y = vector.y;
    this->color = vector.color;
}

QColor DVector2::getColor(){
    return color;
}
void DVector2::setColor(const QColor &color){
    this->color = color;
}


DVector2 DVector2::operator+(const DVector2 &vector){
    return DVector2(this->x + vector.x, this->y + vector.y, this->color);
}

DVector2 DVector2::operator-(const DVector2 &vector){
    return DVector2(this->x - vector.x, this->y - vector.y, this->color);
}

DVector2::DVector2(const double &x, const double &y, const QColor &color): Vector2(x,y), color(color){

}
