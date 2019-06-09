#ifndef SCENE3_H
#define SCENE3_H

#include <vector>
#include <objects/line3.h>
#include <objects/line2.h>
#include <objects/square3.h>
#include <objects/cube.h>
#include <QImage>

class Scene3 {
public:
    Scene3(const int &width, const int &height);
    QImage render();
    void add(const Vector3 &point);
    void add(const Line3 &line);
    void add(const Square3 &square);
    void add(const Cube &cube);
private:
    int width;
    int height;
    std::vector<Vector3> points;
    std::vector<Line3> lines;
    std::vector<Square3> squares;
    std::vector<Cube> cubes;

    static const int pointSize = 5;

    void drawLine(Line2 line, unsigned char *ptr, QColor color);
    void drawLine(Line3 line, unsigned char *ptr, QColor color);


    inline void draw(unsigned char *ptr, QColor color, const int &x, const int &y);
};

#endif // SCENE3_H
