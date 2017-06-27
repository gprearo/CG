#include "glbox.h"
#include <iostream>
#include <QPainter>
#include "sphere.h"
#include <GL/glut.h>
#include <QGLWidget>
#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DCore/QTransform>

void GLBox::initializeGL() {
    // Set up the rendering context, load shaders and other resources, etc.:
    makeCurrent();
    initializeOpenGLFunctions();

    fgColor = QColor(255, 0, 0, 255) ;
    bgColor = QColor(255, 255, 255, 255);

    clearBg(bgColor);
    int i=0;

    glMatrixMode(GL_PROJECTION);
    glEnable(GL_BLEND) ;
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    Qt3DExtras::QTorusMesh *m_torus = new Qt3DExtras::QTorusMesh();
    m_torus->setRadius(1.0f);
    m_torus->setMinorRadius(0.4f);
    m_torus->setRings(100);
    m_torus->setSlices(20);

    Qt3DCore::QTransform *torusTransform = new Qt3DCore::QTransform();
    torusTransform->setScale(2.0f);
    torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 25.0f));
    torusTransform->setTranslation(QVector3D(5.0f, 4.0f, 0.0f));

    Qt3DExtras::QPhongMaterial *torusMaterial = new Qt3DExtras::QPhongMaterial();
    torusMaterial->setDiffuse(QColor(QRgb(0xbeb32b)));

    m_torus->setEnabled(true);
}

void GLBox::display() {

}

void GLBox::resizeGL(int width, int height) {
    // Muda a altura e largura global do componente
    this->height = height;
    this->width = width;
    glViewport(0, 0, width, height);
    glOrtho(0.0, width, 0.0, height, 1.0, -1.0 );
}

void GLBox::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
    /*
        glPushMatrix();
               srand((unsigned int)time(NULL));

           glRotatef (xRotated, 0.0, 0.0, 0.0);    // rotation about Y axis
           glRotatef (yRotated, 0.0, 0.0, 0.0);    // rotation about Z axis
           glRotatef (zRotated, 0.0 , 0.0, 0.0);

           glPushMatrix();
           glTranslatef (0, 0.0, 0.0);
           glutSolidSphere(1.0, 50, 50);
            glPopMatrix();

        glFlush();*/
    glutSolidSphere (1.0, 50, 50);
}

void GLBox::drawSphere() {
    clearBg(bgColor);
    glClear(GL_COLOR_BUFFER_BIT);
    changeFg(fgColor);


    Sphere sphere(1, 32, 32);
    int const win_width  = 600; // retrieve window dimensions from
    int const win_height = 600; // framework of choice here
    float const win_aspect = (float)win_width / (float)win_height;

    glViewport(0, 0, win_width, win_height);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, win_aspect, 1, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Desenha as linhas da esfera (comentar para desenhar esfera sólida)
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    sphere.draw(0, -1, -6);
}

void GLBox::draw() {
    this->update();
}


void GLBox::clearBg(QColor c) {
    qreal r,  g, b ;
    c.getRgbF(&r, &g, &b, NULL);
    glClearColor(r, g, b, 1.0f);
    glFlush();
}

void GLBox::changeFg(QColor c) {
    qreal r,  g, b ;
    c.getRgbF(&r, &g, &b, NULL);
    glColor3f(r, g, b);
}


void GLBox::setBgColor(QColor c) {
    bgColor = c;
    draw();
}

void GLBox::setFgColor(QColor c) {
    fgColor = c;
    draw();
}

