#include "scene3.h"

Scene3::Scene3(const int &width, const int &height): width(width), height(height){

}

QImage Scene3::render(){
    QImage image = QImage(this->width, this->height, QImage::Format_RGB32);
    image.fill(0);
    unsigned char *ptr = image.bits();
    for(Vector3 point: points){
        const int maxX = point.getX() + pointSize;
        const int minX = point.getX() - pointSize;

        const int maxY = point.getY() + pointSize;
        const int minY = point.getY() - pointSize;

        for (int y = minY; y < maxY; y++) {
            for (int x = minX; x < maxX; x++) {
                draw(ptr, QColor(255,0, 0), x, y);
            }
        }
    }

    for(Line3 line: lines){
        drawLine(line, ptr, QColor(0,255,0));
    }


    for (Square3 square : squares) {
        drawLine(square.getA(), ptr, QColor(0,255,0));
        drawLine(square.getB(), ptr, QColor(0,255,0));
        drawLine(square.getC(), ptr, QColor(0,255,0));
        drawLine(square.getD(), ptr, QColor(0,255,0));
    }
    return image;
}

void Scene3::add(const Vector3 &point){
    points.push_back(point);
}

void Scene3::add(const Line3 &line){
    lines.push_back(line);
}

void Scene3::add(const Square3 &square){
    squares.push_back(square);
}

void Scene3::add(const Cube &cube){
    cubes.push_back(cube);
}

void  Scene3::drawLine(Line3 line, unsigned char *ptr, QColor color){
    drawLine(Line2(
                 Vector2(line.getA().getX(),line.getA().getY()),
                 Vector2(line.getB().getX(),line.getB().getY())
                 ), ptr, color);
}

void Scene3::drawLine(Line2 line, unsigned char *ptr, QColor color){
    const int x1 = line.getA().getX();
    const int y1 = line.getA().getY();
    const int x2 = line.getB().getX();
    const int y2 = line.getB().getY();
    // zmienne pomocnicze
         int d, dx, dy, ai, bi, xi, yi;
         int x = x1, y = y1;
         // ustalenie kierunku rysowania
         if (x1 < x2)
         {
             xi = 1;
             dx = x2 - x1;
         }
         else
         {
             xi = -1;
             dx = x1 - x2;
         }
         // ustalenie kierunku rysowania
         if (y1 < y2)
         {
             yi = 1;
             dy = y2 - y1;
         }
         else
         {
             yi = -1;
             dy = y1 - y2;
         }
         // pierwszy piksel
         draw(ptr, color, x, y);

         // oś wiodąca OX
         if (dx > dy)
         {
             ai = (dy - dx) * 2;
             bi = dy * 2;
             d = bi - dx;
             // pętla po kolejnych x
             while (x != x2)
             {
                 // test współczynnika
                 if (d >= 0)
                 {
                     x += xi;
                     y += yi;
                     d += ai;
                 }
                 else
                 {
                     d += bi;
                     x += xi;
                 }
               draw(ptr,color, x, y);
             }
         }
         // oś wiodąca OY
         else
         {
             ai = ( dx - dy ) * 2;
             bi = dx * 2;
             d = bi - dy;
             // pętla po kolejnych y
             while (y != y2)
             {
                 // test współczynnika
                 if (d >= 0)
                 {
                     x += xi;
                     y += yi;
                     d += ai;
                 }
                 else
                 {
                     d += bi;
                     y += yi;
                 }
                draw(ptr, color, x, y);
             }
         }

}

void Scene3::draw(unsigned char *ptr, QColor color, const int &x, const int &y){
    if(x > 0 && x < width && y > 0 && y < height){
        const int position = width * 4 * y + 4 * x;
        ptr[position] = static_cast<unsigned char>(color.blue());
        ptr[position + 1] = static_cast<unsigned char>(color.green());
        ptr[position + 2] = static_cast<unsigned char>(color.red());
    }
}
