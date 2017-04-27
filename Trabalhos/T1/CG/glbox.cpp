#include "glbox.h"
#include <iostream>

void GLBox::initializeGL() {
    // Set up the rendering context, load shaders and other resources, etc.:
    makeCurrent();
    initializeOpenGLFunctions();
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_BLEND) ;
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

}

void GLBox::resizeGL(int width, int height) {
    //Muda a altura e largura global do componente
    this->height = height ;
    this->width = width ;
    std::cout << "resize: " << width << ", " << height << std::endl;
    glViewport(0, 0, width, height);
    glOrtho(0.0, width, 0.0, height, 1.0, -1.0 );
}

void GLBox::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    std::cout << "paintGL()" << std::endl;
    glBegin(GL_LINE_LOOP);

    // Test
    glColor3i(255, 0, 0) ;

    // Draw QPolygon
    for(int i = 0; i < poly.size(); i++) {
        QPointF vertex = poly.point(i);
        glVertex2i(vertex.x(), vertex.y());
        std::cout << poly.size() << ", " << vertex.x() << ", " << vertex.y() << std::endl;
    }
    glEnd();
    glFlush();

}

void GLBox::draw() {

this->update();

}

void GLBox::mousePressEvent(QMouseEvent *event) {
    //Identifica as cordenadas relativas ao container clicado
    QPoint p = QPoint(event->x(), event->y()) ;

    //Corrige o y da cordenada e insere no poligono
    poly.putPoints(poly.size(), 1, p.x(), this->height - p.y());
    this->draw();
}
