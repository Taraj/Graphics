#ifndef SCENE_H
#define SCENE_H

#include <QImage>
#include <vector>
#include <util/dravable2.h>
#include <util/dravable2.cpp>
#include <objects/vector2.h>
#include <objects/line2.h>


class Scene{
public:
    Scene(const int &width, const int &height);
    QImage render();

    void add(Dravable2<Vector2> point);
    void add(Dravable2<Line2> line);


private:
    std::vector<Dravable2<Vector2> > points;
    const int width;
    const int height;
    std::vector<Dravable2<Line2> > lines;

    static const int pointSize = 5;

    void drawLine(Dravable2<Line2> line, unsigned char *ptr);


    inline void draw(unsigned char *ptr, QColor color, const int &x, const int &y);
};

#endif // SCENE_H
