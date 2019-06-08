#include "scene.h"


Scene::Scene(const int &width, const int &height): width(width), height(height){

}

QImage Scene::render(){
    QImage image = QImage(this->width, this->height, QImage::Format_RGB32);
    image.fill(0);
    unsigned char *ptr = image.bits();
    for(DVector2 point: points){
        const int maxX = point.getX() + pointSize;
        const int minX = point.getX() - pointSize;

        const int maxY = point.getY() + pointSize;
        const int minY = point.getY() - pointSize;

        for (int y = minY; y < maxY; y++) {
            for (int x = minX; x < maxX; x++) {
                draw(ptr, point.getColor(), x, y);
            }
        }
    }

    for(DLine2 line: lines){
        drawLine(line, ptr);
    }



    return image;
}

void Scene::setPoints(std::vector<DVector2> points){
    this->points = points;
}

void Scene::setLines(std::vector<DLine2> lines){
    this->lines = lines;
}

void Scene::drawLine(DLine2 line, unsigned char *ptr){
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
         draw(ptr, line.getColor(), x, y);

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
               draw(ptr, line.getColor(), x, y);
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
                draw(ptr, line.getColor(), x, y);
             }
         }

}

void Scene::draw(unsigned char *ptr, QColor color, const int &x, const int &y){
    if(x > 0 && x < width && y > 0 && y < height){
        const int position = width * 4 * y + 4 * x;
        ptr[position] = static_cast<unsigned char>(color.blue());
        ptr[position + 1] = static_cast<unsigned char>(color.green());
        ptr[position + 2] = static_cast<unsigned char>(color.red());
    }
}
