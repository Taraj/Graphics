#include "scene3.h"

Scene3::Scene3(const int &width, const int &height): width(width), height(height), screenCenter(Vector2(width/2, height/2)){

}

QImage Scene3::render(const Vector3 &position,  Vector3 rotation){
    QImage image = QImage(this->width, this->height, QImage::Format_RGB32);
    image.fill(0);
    Vector3 baseVector = Vector3(0, 0, static_cast<int>(-2*d));

    unsigned char *ptr = image.bits();  
    for (unsigned int i = 0; i < points.size(); i++) {
        points[i].transalte(position);
        points[i].rotateAroundY(baseVector, rotation.getY());
        points[i].rotateAroundX(baseVector, rotation.getX());
        points[i].rotateAroundZ(baseVector, rotation.getZ());
    }

    for (unsigned int i = 0; i < lines.size(); i++) {
        lines[i].translate(position);
        lines[i].rotateAroundY(baseVector, rotation.getY());
        lines[i].rotateAroundX(baseVector, rotation.getX());
        lines[i].rotateAroundZ(baseVector, rotation.getZ());
    }

    for (unsigned int i = 0; i < squares.size(); i++) {
        squares[i].translate(position);
        squares[i].rotateAroundX(baseVector, rotation.getX());
        squares[i].rotateAroundY(baseVector, rotation.getY());
        squares[i].rotateAroundZ(baseVector, rotation.getZ());
    }

    for (unsigned int i = 0; i < cubes.size(); i++) {
        cubes[i].translate(position);
        cubes[i].rotateAroundX(cubes[i].center, rotation.getX());
        cubes[i].rotateAroundY(cubes[i].center, rotation.getY());
        cubes[i].rotateAroundZ(cubes[i].center, rotation.getZ());


      //  cubes[i].rotateAroundX(baseVector, rotation.getX());
      //  cubes[i].rotateAroundY(baseVector, rotation.getY());
      //  cubes[i].rotateAroundZ(baseVector, rotation.getZ());
    }




    const int maxX = screenCenter.getX() + pointSize;
    const int minX = screenCenter.getX() - pointSize;

    const int maxY = screenCenter.getY() + pointSize;
    const int minY = screenCenter.getY() - pointSize;

    for (int y = minY; y < maxY; y++) {
        for (int x = minX; x < maxX; x++) {
            draw(ptr, QColor(255,0, 255), x, y);
        }
    }





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
        drawLine(line, ptr, QColor(0,255,0),position);
    }

    for(Square3 square : squares) {
        drawSquare(square, ptr,QColor(0,255,0),position);
    }

    Vector3 center = Vector3(0, 0, 1000);
    for(Cube cube : cubes){
        if(cube.a.getNormalVector().dotProduct(center + cube.a.getA().getA()) < 0)
            drawSquare(cube.a, ptr,QColor(255,255,0),position);
        if(cube.b.getNormalVector().dotProduct(center + cube.b.getA().getA()) < 0)
            drawSquare(cube.b, ptr,QColor(255,255,0),position);
        if(cube.c.getNormalVector().dotProduct(center + cube.c.getA().getA()) < 0)
            drawSquare(cube.c, ptr,QColor(255,255,0),position);
        if(cube.d.getNormalVector().dotProduct(center + cube.d.getA().getA()) < 0)
            drawSquare(cube.d, ptr,QColor(255,255,0),position);
        if(cube.e.getNormalVector().dotProduct(center + cube.e.getA().getA()) < 0)
            drawSquare(cube.e, ptr,QColor(255,255,0),position);
        if(cube.f.getNormalVector().dotProduct(center + cube.f.getA().getA()) < 0)
            drawSquare(cube.f, ptr,QColor(255,255,0),position);
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

void  Scene3::drawLine(Line3 line, unsigned char *ptr, QColor color, Vector3 center){

    if(line.getA().getZ()<=-d && line.getB().getZ()<=-d){
        return;
    }

    if(line.getA().getZ()<=-d){


        Vector3 tmp = line.getA();
        tmp.setZ((-d)+1);

        drawLine(Line2(convert(tmp,center), convert(line.getB(), center)), ptr, color);

          return;
    }

    if(line.getB().getZ()<=-d){

        Vector3 tmp = line.getB();
        tmp.setZ((-d)+1);

        drawLine(Line2(convert(line.getA(),center), convert(tmp, center)), ptr, color);

          return;
    }

    drawLine(Line2(convert(line.getA(),center), convert(line.getB(), center)), ptr, color);

}

void Scene3::drawSquare(Square3 square, unsigned char *ptr, QColor color ,Vector3 center){

    drawTriangle(
                square.getA().getB(),
                square.getB().getB(),
                square.getA().getA(),
                ptr,
                center,
                true
                );

    drawTriangle(
                square.getC().getB(),
                square.getD().getB(),
                square.getC().getA(),
                ptr,
                center,
                false
                );
}

Vector2 Scene3::convert(Vector3 vector, Vector3 center){
    double tmp = (1.0+(vector.getZ()/d));
         if(tmp == 0){
            tmp=0.001;
         }
         return Vector2(static_cast<int>(std::round((vector.getX())/tmp)), static_cast<int>(std::round((vector.getY())/tmp))) + screenCenter;
}

void Scene3::drawTriangle(Vector3 a, Vector3 b, Vector3 c, unsigned char *ptr,Vector3 center,bool t){
    drawTriangle(convert(a,center), convert(b,center), convert(c, center), ptr, t);
}

void Scene3::drawTriangle(Vector2 a, Vector2 b, Vector2 c, unsigned char *ptr, bool t){

int yMin = std::min(a.getY(), std::min(b.getY(), c.getY()));
int yMax = std::max(a.getY(), std::max(b.getY(), c.getY()));

int xMin = std::min(a.getX(), std::min(b.getX(), c.getX()));
int xMax = std::max(a.getX(), std::max(b.getX(), c.getX()));

QImage text = QImage(":/orig.jpg").scaledToWidth(500);

for (int y = yMin; y < yMax; y++) {
    for (int x = xMin; x < xMax; x++) {

        std::pair<double, double> ba = bar(Vector2(x,y), a, b, c);
        double v = ba.first;
        double w = ba.second;
        double u = 1-w-v;
        if(
                v>=0 && v<=1
                &&
                w>=0 && w<=1
                &&
                u>=0 && u<=1

                ){
            int xt;
            int yt;
            if(t){
                 xt = (u * 0) + (v * 500) + (w * 0);
                 yt = (u * 0) + (v * 0) + (w * 500);
            }else{
                xt = (u * 500) + (v * 0) + (w * 500);
                yt = (u * 500) + (v * 500) + (w * 0);
            }

          //  unsigned char *ptr = target.bits();
          //  unsigned char *sr = source.bits();
           // ptr[500*4*y + 4*x] =  sr[500*4*yt + 4*xt];
          //  ptr[500*4*y + 4*x + 1] =  sr[500*4*yt + 4*xt+1];
          //  ptr[500*4*y + 4*x + 2] =  sr[500*4*yt + 4*xt+2];

            draw(ptr, text.pixel(xt,yt),x,y);
        }


    }
}
















  //  drawLine(Line2(a, b), ptr, QColor(255,0,0));
  //  drawLine(Line2(a, c), ptr, QColor(255,0,0));
  //  drawLine(Line2(b, c), ptr, QColor(255,255,0));
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







std::pair<double, double> Scene3::bar(Vector2 p,Vector2 a,Vector2 b, Vector2 c){
    double vg= (p.getX()-a.getX())*(c.getY()-a.getY())-(c.getX()-a.getX())*(p.getY()-a.getY());
    double wg = (b.getX()-a.getX())*(p.getY()-a.getY())-(p.getX()-a.getX())*(b.getY()-a.getY());

    double vd = (b.getX()-a.getX())*(c.getY()-a.getY())-(c.getX()-a.getX())*(b.getY()-a.getY());
    double wd = (b.getX()-a.getX())*(c.getY()-a.getY())-(c.getX()-a.getX())*(b.getY()-a.getY());

    double v =vg/vd;
    double w =wg/wd;

    return std::make_pair(v,w);
}









void Scene3::draw(unsigned char *ptr, QColor color, const int &x, const int &y){
    if(x > 0 && x < width && y > 0 && y < height){
        const int position = width * 4 * y + 4 * x;
        ptr[position] = static_cast<unsigned char>(color.blue());
        ptr[position + 1] = static_cast<unsigned char>(color.green());
        ptr[position + 2] = static_cast<unsigned char>(color.red());
    }
}
