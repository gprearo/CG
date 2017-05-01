#include "glbox.h"
#include <iostream>
#include <QPainter>

#include "activeedgetable.h"

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
    if(mode == DRAW_VERTEX)
        drawVertex();
    else if(mode == DRAW_POLYGON)
        drawPolygon();
    else if(mode == FILL_POLYGON)
        preencher();
    else
        std::cout << "paintGL(): Invalid type!" << std::endl;
}

void GLBox::preencher() {
    if(this->poly.size() < 2)
        return;

    clearBg(bgColor);
    glClear(GL_COLOR_BUFFER_BIT);
    changeFg(fgColor);


    ActiveEdgeTable aet = ActiveEdgeTable(this->poly) ;

    aet.print() ; // DEBUG

    int y = aet.start() ;

    glBegin(GL_POINTS);
    do {
//        std::cout << "linha: " << y << std::endl;
        QVector<int> inter ;

        //Pega as intersecções da linha com as arestas
        inter = aet.intersections() ;
        int x = 1 ;
        int i = 0 ;
        char parity = 0 ;

        //Se só houver uma intersecção, não há o que fazer
        if (inter.size() == 1) {
            continue ;
        }

        //Enquanto nao passar por todas intersecções
        while (i < inter.size()) {
            //Se o x é ponto de intersecção, muda a paridade
            if (x == inter.at(i)) {
                //Se a paridade for 0, pinta o pixel de x
                if (!parity) {
                    glVertex2i(x, y);
                }

                //Incrementa o i e muda a paridade
                i++ ;
                parity = !parity ;
            } else {
                //Se a paridade é 1, pinta o pixel
                if (parity) {
                    glVertex2i(x, y);
                }
                //Anda na linha
                x++ ;
            }
        }

        //Incrementa a linha
    } while ((y = aet.incY())) ;

    glEnd() ;
    glFlush();
    std::cout << "Terminou" << "\n" ;
    return ;
}



void GLBox::drawVertex() {
    clearBg(bgColor);
    glClear(GL_COLOR_BUFFER_BIT);
    changeFg(fgColor);

    int p = 1; // Número do ponto

    // Desenha os vértices
    for(int i = 0; i < poly.size(); i++) {
        QPoint vertex = poly.at(i) ;

        // Pinta o ponto do vértice
        glBegin(GL_POINTS);
        glVertex2i(vertex.x(), vertex.y());
        glEnd();

        // Pinta a letra do vértice
        QPainter painter(this);
        painter.setPen(fgColor);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(vertex.x() + 1, this->height-vertex.y() - 1, "P"+QString::number(p));
        p++; // Próximo número
    }
    glFlush();
}

void GLBox::drawPolygon() {
    clearBg(bgColor);
    glClear(GL_COLOR_BUFFER_BIT);
    changeFg(fgColor);

    glBegin(GL_LINE_LOOP);

    // Desenha o polígono
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

void GLBox::reset() {
    this->poly.clear();
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

void GLBox::setMode(short mode) {
    if(mode < DRAW_VERTEX || mode > FILL_POLYGON)
        std::cout << "GLBox::setMode(): Invalid mode!\n";
    else
        this->mode = mode;
}

void GLBox::setBgColor(QColor c) {
    bgColor = c;
    draw();
}

void GLBox::setFgColor(QColor c) {
    fgColor = c;
    draw();
}

void GLBox::mousePressEvent(QMouseEvent *event) {
    //Identifica as cordenadas relativas ao container clicado
    QPoint p = QPoint(event->x(), event->y());

    // Corrige o valor relativo do eixo y
    p.setY(this->height - p.y());

    // Insere no poligono
    poly.putPoints(poly.size(), 1, p.x(), p.y());

    // Desenha o vértice selecionado
    this->draw();
}
