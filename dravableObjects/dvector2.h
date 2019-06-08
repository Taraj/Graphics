#ifndef DVECTOR2_H
#define DVECTOR2_H

#include <objects/vector2.h>
#include <QColor>


class DVector2 : public Vector2 {
public:
    DVector2(const int &x = 0, const int &y = 0, const QColor &color = QColor(0, 255, 0));
    DVector2(const Vector2 &vector, const QColor &color = QColor(0, 255, 0));
    DVector2(const DVector2 &vector);
    DVector2(const DVector2 &&vector);
    void operator=(const DVector2 &vector);
    DVector2 operator+(const DVector2 &vector);
    DVector2 operator-(const DVector2 &vector);
    QColor getColor();
    void setColor(const QColor &color);

private:
    DVector2(const double &x, const double &y, const QColor &color);
    QColor color;
};

#endif // DVECTOR2_H
