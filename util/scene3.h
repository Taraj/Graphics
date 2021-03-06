#ifndef SCENE3_H
#define SCENE3_H

#include <objects/vector2.h>
#include <objects/vector3.h>
#include <objects/square3.h>
#include <QImage>
#include <QList>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>
#include <QThreadPool>


//#define ALLOW_FLY

class Scene3 {
public:
    Scene3(const unsigned int &width, const unsigned int &height);
    QImage render(const Vector3 &position, const Vector3 &rotation);


    std::vector<Square3> floor;
    std::vector<Square3> walls;
    std::vector<Square3> ceiling;
    std::vector<Square3> specialFloor;


    void addUniqueWall(const Square3 &wall);
    void addSpecialFloor(const Square3 &wall);
private:
    constexpr static const double d = 1000;
    constexpr static const int drawRange = 500;

    const unsigned int width;
    const unsigned int height;
    const Vector2 screenCenter;
    const Vector3 baseVector = Vector3(0, 0, -1000);
    const unsigned int magicNumber = 2500;


    const QImage floorSprite = QImage(":/orig.jpg").scaledToWidth(500);
    const QImage wallSprite = QImage(":/stone.jpg").scaledToWidth(500);
    const QImage ceilingSprite = QImage(":/coble.jpg").scaledToWidth(500);
    const QImage specialFloorSprite = QImage(":/brick1.jpg").scaledToWidth(500);


    const unsigned char *floorTexture = floorSprite.bits();
    const unsigned char *wallTexture = wallSprite.bits();
    const unsigned char *ceilingTexture = ceilingSprite.bits();
    const unsigned char *specialFloorTexture = specialFloorSprite.bits();



    inline bool inArea(const Vector2 &vector);
    void drawSquare(const Square3 &square, unsigned char *ptr, const unsigned char *texture);
    Vector2 convert(const Vector3 &vector);
    void drawTriangle(const Vector3 &a, const Vector3 &b, const Vector3 &c, unsigned char *target, const bool &top, const unsigned char *texture);
    void drawTriangleOnEdge(const Vector2 &a, const Vector2 &b, const Vector2 &c, unsigned char *target, const bool &top, const unsigned char *texture);
    void drawTriangleInCenter(const Vector2 &a, const Vector2 &b, const Vector2 &c, unsigned char *target, const bool &top, const unsigned char *texture);
    inline void copyColor(unsigned char *target, const unsigned int &tx, const unsigned int &ty, const unsigned char *source, const unsigned int &sx, const unsigned int &sy);
    inline static Vector2 barycentric(const Vector2 &p, const Vector2 &a, const Vector2 &b, const Vector2 &c);

};

#endif // SCENE3_H
