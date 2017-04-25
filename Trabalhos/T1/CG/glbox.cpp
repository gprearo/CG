#include "glbox.h"
#include <iostream>

void GLBox::initializeGL() {
    // Set up the rendering context, load shaders and other resources, etc.:
    makeCurrent();
    initializeOpenGLFunctions();
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_BLEND) ;
//    glViewport( 0,0, 400, 600);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
//    glOrtho( 0.0, 400, 0.0, 600, 1.0, -1.0 );

}

void GLBox::resizeGL(int width, int height) {
    std::cout << "resize: " << width << ", " << height << std::endl;
    glViewport(0, 0, width, height);
    glOrtho(0.0, width, 0.0, height, 1.0, -1.0 );
}

void GLBox::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT);
    std::cout << "paintGL()" << std::endl;
    glBegin(GL_LINE_STRIP);

    // Test
    glColor3i(255, 0, 0) ;
    glVertex2i(100, 10);
    glVertex2i(119, 10);
    glVertex2i(100, 120);

    // Draw QPolygon
//    for(int i = 0; i < poly.size(); i++) {
//        QPointF vertex = poly.point(i);
//        glVertex2i(vertex.x(), vertex.y());
//        std::cout << poly.size() << ", " << vertex.x() << ", " << vertex.y() << std::endl;
//    }
    glEnd();
    glFlush();

}

void GLBox::draw() {

this->update();

}

void GLBox::mousePressEvent(QMouseEvent *event) {

    this->draw();
}
