#include "scene3.h"

Scene3::Scene3(const unsigned int &width, const unsigned int &height): width(width), height(height), screenCenter(width / 2, height / 2){

}

QImage Scene3::render(const Vector3 &position, const Vector3 &rotation){
    QImage image = QImage(static_cast<int>(this->width), static_cast<int>(this->height), QImage::Format_RGB32);
    image.fill(0);

    unsigned char *ptr = image.bits();  


    for (unsigned int i = 0; i < floor.size(); i++) {
        floor[i].translate(position);
        floor[i].rotateAroundY(baseVector, rotation.y);
    }

    for (unsigned int i = 0; i < ceiling.size(); i++) {
        ceiling[i].translate(position);
        ceiling[i].rotateAroundY(baseVector, rotation.y);
    }

    for (unsigned int i = 0; i < walls.size(); i++) {
        walls[i].translate(position);
        walls[i].rotateAroundY(baseVector, rotation.y);
    }

    for(Square3 square : floor) {
        drawSquare(square, ptr, floorTexture);
    }

    for(Square3 square : ceiling) {
        drawSquare(square, ptr, ceilingTexture);
    }

    std::sort(walls.begin(), walls.end(), [](const Square3 &a, const Square3 &b) -> bool {
         return a.center.z > b.center.z;
    });

    for(Square3 square : walls) {
        drawSquare(square, ptr, wallTexture);
    }

    return image;
}

bool Scene3::inArea(const Vector2 &a){
    return a.x >= 0 && a.x < static_cast<int>(width)  && a.y >= 0 && a.y < static_cast<int>(height);
}

void Scene3::drawSquare(const Square3 &square, unsigned char *ptr, const unsigned char *texture){

    if(square.center.z < -d){
        return;
    }

    drawTriangle(
                square.a,
                square.b,
                square.d,
                ptr,
                true,
                texture
                );

    drawTriangle(
                square.c,
                square.d,
                square.b,
                ptr,
                false,
                texture
                );
}

Vector2 Scene3::convert(const Vector3 &vector){
    const double tmp = (1.0 + (vector.z / d));
    if(tmp == 0){
      return Vector2(std::round((vector.x)/0.01), std::round((vector.y)/0.01)) + screenCenter;
    }
    return Vector2(std::round((vector.x)/tmp), std::round((vector.y)/tmp)) + screenCenter;
}

void Scene3::drawTriangle(const Vector3 &a, const Vector3 &b, const Vector3 &c, unsigned char *target, const bool &top, const unsigned char *texture){

    const Vector2 a2 = convert(a);
    const Vector2 b2 = convert(b);
    const Vector2 c2 = convert(c);

    if((a2.x < 0 && b2.x < 0 && c2.x < 0) || (a2.x > static_cast<int>(width) &&  b2.x > static_cast<int>(width) && c2.x > static_cast<int>(width))){
        return;
    }else if ((a2.y < 0 && b2.y < 0 && c2.y < 0) || (a2.y > static_cast<int>(height) &&  b2.y > static_cast<int>(height) && c2.y > static_cast<int>(height))) {
        return;
    }

    const bool aNotInArea = !inArea(a2);
    const bool bNotInArea = !inArea(b2);
    const bool cNotInArea = !inArea(c2);

    if (aNotInArea && bNotInArea && cNotInArea) {
        if(a2.distance(c2) < magicNumber && a2.distance(b2) < magicNumber && b2.distance(c2) < magicNumber){
            drawTriangleOnEdge(a2, b2, c2, target, top, texture);
        }
    } else if(aNotInArea || bNotInArea || cNotInArea){
        drawTriangleOnEdge(a2, b2, c2, target, top, texture);
    } else {
        drawTriangleInCenter(a2, b2, c2, target, top, texture);
    }
}

void Scene3::drawTriangleOnEdge(const Vector2 &a, const Vector2 &b, const Vector2 &c, unsigned char *target, const bool &top, const unsigned char *texture){
    int yMin = static_cast<int>(std::min(a.y, std::min(b.y, c.y)));
    int yMax = static_cast<int>(std::max(a.y, std::max(b.y, c.y)));

    int xMin = static_cast<int>(std::min(a.x, std::min(b.x, c.x)));
    int xMax = static_cast<int>(std::max(a.x, std::max(b.x, c.x)));

    if(yMin < 0) yMin = 0;
    if(xMin < 0) xMin = 0;

    if(yMax >= static_cast<int>(height)) yMax = static_cast<int>(height) - 1;
    if(xMax >= static_cast<int>(width)) xMax = static_cast<int>(width) - 1;

    for (int y = yMin; y < yMax; y++) {
      for (int x = xMin; x < xMax; x++) {

          const Vector2 bar = barycentric(Vector2(x, y), a, b, c);
          const double v = bar.x;
          const double w = bar.y;
          const double u = 1 - w - v;
          if(
                  v >= 0 && v <= 1
                  &&
                  w >= 0 && w <= 1
                  &&
                  u >= 0 && u <= 1
          ){
              if(top){
                 const unsigned int xt = static_cast<unsigned int>((u * 0) + (v * 499) + (w * 0));
                 const unsigned int yt = static_cast<unsigned int>((u * 0) + (v * 0) + (w * 499));
                 copyColor(target, static_cast<unsigned int>(x), static_cast<unsigned int>(y), texture, xt, yt);

              } else {
                 const unsigned int xt = static_cast<unsigned int>((u * 499) + (v * 0) + (w * 499));
                 const unsigned int  yt = static_cast<unsigned int>((u * 499) + (v * 499) + (w * 0));
                 copyColor(target, static_cast<unsigned int>(x), static_cast<unsigned int>(y), texture, xt, yt);
              }
          }
      }
    }
}

void Scene3::drawTriangleInCenter(const Vector2 &a, const Vector2 &b, const Vector2 &c, unsigned char *target, const bool &top, const unsigned char *texture){

  const unsigned int yMin = static_cast<unsigned int>(std::min(a.y, std::min(b.y, c.y)));
  const unsigned int yMax = static_cast<unsigned int>(std::max(a.y, std::max(b.y, c.y)));

  const unsigned int xMin = static_cast<unsigned int>(std::min(a.x, std::min(b.x, c.x)));
  const unsigned int xMax = static_cast<unsigned int>(std::max(a.x, std::max(b.x, c.x)));

    for (unsigned int y = yMin; y < yMax; y++) {
        for (unsigned int x = xMin; x < xMax; x++) {
            const Vector2 bar = barycentric(Vector2(x, y), a, b, c);
            const double v = bar.x;
            const double w = bar.y;
            const double u = 1 - w - v;
            if(
                    v >= 0 && v <= 1
                    &&
                    w >= 0 && w <= 1
                    &&
                    u >= 0 && u <= 1
            ){
                if(top){
                   const unsigned int xt = static_cast<unsigned int>((u * 0) + (v * 499) + (w * 0));
                   const unsigned int yt = static_cast<unsigned int>((u * 0) + (v * 0) + (w * 499));
                   copyColor(target, x, y, texture, xt, yt);

                } else {
                   const unsigned int xt = static_cast<unsigned int>((u * 499) + (v * 0) + (w * 499));
                   const unsigned int  yt = static_cast<unsigned int>((u * 499) + (v * 499) + (w * 0));
                   copyColor(target, x, y, texture, xt, yt);
                }
            }
        }
    }
}

Vector2 Scene3::barycentric(const Vector2 &p, const Vector2 &a, const Vector2 &b, const Vector2 &c){
    const double vg = (p.x - a.x) * (c.y - a.y) - (c.x - a.x) * (p.y - a.y);
    const double wg = (b.x - a.x) * (p.y - a.y) - (p.x - a.x) * (b.y - a.y);

    const double d = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);

    return Vector2(vg / d, wg / d);
}

void Scene3::copyColor(unsigned char *target, const unsigned int &tx, const unsigned int &ty, const unsigned char *source, const unsigned int &sx, const unsigned int &sy){
    const unsigned int targetPosition = width * 4 * ty + 4 * tx;
    const unsigned int sourcePosition = 500 * 4 * sy + 4 * sx; // Wielkość tekstury

    target[targetPosition] = source[sourcePosition];
    target[targetPosition + 1] = source[sourcePosition + 1];
    target[targetPosition + 2] = source[sourcePosition + 2];

}
