#ifndef SCENE_H
#define SCENE_H

#include <QImage>
#include <vector>
#include <dravableObjects/dvector2.h>
#include <dravableObjects/dline2.h>

class Scene{
public:
    Scene(const int &width, const int &height);
    QImage render();

    void setPoints(std::vector<DVector2> points);
    void setLines(std::vector<DLine2> lines);

private:
    std::vector<DVector2> points;
    const int width;
    const int height;
    std::vector<DLine2> lines;

    static const int pointSize = 5;

    void drawLine(DLine2 line, unsigned char *ptr);


    inline void draw(unsigned char *ptr, QColor color, const int &x, const int &y);
};

#endif // SCENE_H
