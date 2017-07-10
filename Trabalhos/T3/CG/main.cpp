#include <QApplication>
#include <iostream>
#include "principal.h"
#include "world.h"
#include <QVector3D>

#include<GL/glut.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);



    // Código exemplo da esfera: https://stackoverflow.com/questions/5988686/creating-a-3d-sphere-in-opengl-using-visual-c
    Principal mw;
    mw.show();

    return a.exec();
}
