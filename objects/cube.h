#ifndef CUBE_H
#define CUBE_H

#include <objects/vector3.h>

class Cube{
public:
    Cube(const Vector3 &center, unsigned int &size);


private:
    Vector3 center;


};

#endif // CUBE_H
