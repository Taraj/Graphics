#ifndef DRAVABLE2_H
#define DRAVABLE2_H

#include <QColor>
#include <objects/vector2.h>

template <typename T>
class Dravable2{
public:
    Dravable2(const T &object, const QColor &color = QColor(0,255,0));
    void operator=(const Dravable2<T> &dravable);
    bool operator==(const  Dravable2<T> &dravable);
    void setColor(const QColor &color);
    void setObject(const T &object);
    QColor getColor();
    T getObject();

private:

    QColor color;
    T object;
};

#endif // DRAVABLE2_H
