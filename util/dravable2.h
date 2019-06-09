#ifndef DRAVABLE2_H
#define DRAVABLE2_H

#include <QColor>


template <typename T>
class Dravable2{
public:
    Dravable2(const T &object, const int &zIndex, const QColor &color);

    void operator=(const Dravable2<T> &dravable);



    bool operator==(const  Dravable2<T> &dravable);

    bool operator> (Dravable2<T> &dravable);
    bool operator<= (Dravable2<T> &dravable);

    bool operator< (Dravable2<T> &dravable);
    bool operator>= (Dravable2<T> &dravable);

    void setColor(const QColor &color);
    void setZIndex(const int &zIndex);
    void setObject(const T &object);

    QColor getColor();
    int getZIndex();
    T getObject();


private:
    int zIndex;
    QColor color;
    T object;
};

#endif // DRAVABLE2_H
