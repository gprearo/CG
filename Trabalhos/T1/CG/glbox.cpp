#include "glbox.h"
#include <iostream>
#include <QPainter>

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

void GLBox::drawVertex() {
    glClear(GL_COLOR_BUFFER_BIT);
    clearBg(bgColor);
    std::cout << "drawVertex()" << std::endl;

    // Test
    changeFg(fgColor);

    char c = 'A';

    // Desenha os vértices
    for(int i = 0; i < vPoints.size(); i++) {
        QPoint vertex = vPoints.at(i);

        // Pinta o ponto do vértice
        glBegin(GL_POINTS);
        glVertex2i(vertex.x(), vertex.y());
        glEnd();

        // Pinta a letra do vértice
        QPainter painter( this );
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(vertex.x() + 1, this->height-vertex.y() - 1, QString(c));
        c++; // Próxima letra

        std::cout << vPoints.size() << ", " << vertex.x() << ", " << vertex.y() << std::endl; // DEBUG
    }
    glFlush();
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
    if(type == DRAW_VERTEX)
        drawVertex();
    else if(type == DRAW_POLYGON)
        drawPolygon();
    else
        std::cout << "paintGL(): Invalid type!" << std::endl;
}

void GLBox::draw() {
    this->update();

}

void GLBox::mousePressEvent(QMouseEvent *event) {
    //Identifica as cordenadas relativas ao container clicado
    QPoint p = QPoint(event->x(), event->y());

    // Corrige o valor relativo do eixo y
    p.setY(this->height - p.y());

    // Insere na lista de vértices
    vPoints.append(p);

    // Insere no poligono
    poly.putPoints(poly.size(), 1, p.x(), p.y());

    // Desenha o vértice selecionado
    this->draw();
}
