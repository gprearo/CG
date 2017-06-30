#include <QApplication>
#include <iostream>
#include "principal.h"
#include "world.h"
#include <QVector3D>

#include<GL/glut.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // TODO: Posição da fonte de luz e do observador na UI
    QVector3D *l = new QVector3D(10, 10, 10); // Light position
    QVector3D *t = new QVector3D(0, 0, 10);   // Target position
    World w(l, t, 5);

    // Código exemplo da esfera: https://stackoverflow.com/questions/5988686/creating-a-3d-sphere-in-opengl-using-visual-c
    Principal mw;
    mw.show();

    return a.exec();
}
