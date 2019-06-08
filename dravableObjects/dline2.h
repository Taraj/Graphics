#ifndef DLINE2_H
#define DLINE2_H

#include <objects/line2.h>
#include <QColor>

class DLine2 : public Line2 {
public:
    DLine2(const Vector2 &a, const Vector2 &b, const QColor &color);
    DLine2(const Line2 &vector, const QColor &color = QColor(0, 255, 0));
    DLine2(const DLine2 &line);
    DLine2(const DLine2 &&line);
    void operator=(const DLine2 &line);
    QColor getColor();
    void setColor(const QColor &color);
private:
    QColor color;
};

#endif // DLINE2_H
