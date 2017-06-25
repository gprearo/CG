#include "glbox.h"
#include <iostream>
#include <QPainter>
#include "sphere.h"

void GLBox::initializeGL() {
    // Set up the rendering context, load shaders and other resources, etc.:
    makeCurrent();
    initializeOpenGLFunctions();

    fgColor = QColor(255, 0, 0, 255) ;
    bgColor = QColor(255, 255, 255, 255);

    clearBg(bgColor);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_BLEND) ;
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
}

void GLBox::resizeGL(int width, int height) {
    // Muda a altura e largura global do componente
    this->height = height;
    this->width = width;
    glViewport(0, 0, width, height);
    glOrtho(0.0, width, 0.0, height, 1.0, -1.0 );
}

void GLBox::paintGL() {
    drawSphere();
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

