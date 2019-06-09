#include "dravable2.h"


template <typename T>
Dravable2<T>::Dravable2(const T &object, const int &zIndex, const QColor &color): object(object), zIndex(zIndex), color(color){

}

template <typename T>
bool Dravable2<T>::operator==(const  Dravable2<T> &dravable){
    return this->zIndex == dravable.zIndex && this->object == dravable.object;
}

template <typename T>
bool Dravable2<T>::operator>(Dravable2<T> &dravable){
     return this->zIndex > dravable.zIndex;
}

template <typename T>
bool Dravable2<T>::operator<=(Dravable2<T> &dravable){
    return this->zIndex <= dravable.zIndex;
}

template <typename T>
bool Dravable2<T>::operator<(Dravable2<T> &dravable){
     return this->zIndex > dravable.zIndex;
}

template <typename T>
bool Dravable2<T>::operator>=(Dravable2<T> &dravable){
     return this->zIndex >= dravable.zIndex;
}

template <typename T>
void Dravable2<T>::setColor(const QColor &color){
    this->color = color;
}

template <typename T>
void Dravable2<T>::setZIndex(const int &zIndex){
    this->zIndex = zIndex;
}

template <typename T>
void Dravable2<T>::setObject(const T &object){
   this->object = object;
}

template <typename T>
QColor Dravable2<T>::getColor(){
    return this->color;
}

template <typename T>
int Dravable2<T>::getZIndex(){
    return this->zIndex;
}

template <typename T>
T Dravable2<T>::getObject(){
    return this->object;
}

