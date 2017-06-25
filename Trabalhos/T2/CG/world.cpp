#include "world.h"

World::World(QVector3D *l, QVector3D *t, qreal sphere_radius) {
    // Init sphere
    sphere = new Sphere(sphere_radius, 32, 32);

    light = l;
    target  = t;
}
