#include "dline2.h"

DLine2::DLine2(const Vector2 &a, const Vector2 &b, const QColor &color): Line2(a, b), color(color){

}
DLine2::DLine2(const Line2 &line, const QColor &color): Line2(line), color(color){

}
DLine2::DLine2(const DLine2 &line): Line2(line.a, line.b), color(line.color){

}
DLine2::DLine2(const DLine2 &&line): Line2(line.a, line.b), color(line.color){

}
void DLine2::operator=(const DLine2 &line){
    this->a = line.a;
    this->b = line.b;

}
QColor DLine2::getColor(){
    return color;
}
void DLine2::setColor(const QColor &color){
    this->color = color;
}
