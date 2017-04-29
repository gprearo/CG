#include "glbox.h"
#include <iostream>

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
    std::cout << r << ", " << g << " , " << b << "\n" ;
}

void GLBox::setBgColor(QColor c) {
    bgColor = c ;
    clearBg(bgColor);
    changeFg(fgColor);
    this->draw() ;
}

void GLBox::setFgColor(QColor c) {
    fgColor = c ;
    clearBg(bgColor);
    changeFg(fgColor);
    draw();
    std::cout << c.name().toStdString() ;
}


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
    //Muda a altura e largura global do componente
    this->height = height ;
    this->width = width ;
    std::cout << "resize: " << width << ", " << height << std::endl;
    glViewport(0, 0, width, height);
    glOrtho(0.0, width, 0.0, height, 1.0, -1.0 );
}

void GLBox::drawPolygon() {
    glClear(GL_COLOR_BUFFER_BIT);
    clearBg(bgColor);
    std::cout << "paintGL()" << std::endl;
    glBegin(GL_LINE_LOOP);

    // Test
    changeFg(fgColor);

    // Draw QPolygon
    for(int i = 0; i < poly.size(); i++) {
        QPointF vertex = poly.point(i);
        glVertex2i(vertex.x(), vertex.y());
        std::cout << poly.size() << ", " << vertex.x() << ", " << vertex.y() << std::endl;
    }
    glEnd();
    glFlush();
}

void GLBox::paintGL() {
    drawPolygon();
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
