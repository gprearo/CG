#ifndef WORLD_H
#define WORLD_H

#include <QVector3D>
#include <QVector4D>
#include "sphere.h"


class World
{
public:
    World(QVector3D *l, QVector3D *t, qreal sphere_radius);

private:
    QVector3D *light;
    QVector3D *target;
    Sphere *sphere;  // TODO: array of spheres?

};



#endif // WORLD_H
