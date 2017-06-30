#include "glbox.h"
#include <iostream>
#include <QPainter>
#include "sphere.h"
#include <GL/glut.h>
#include <QGLWidget>
//#include <Qt3DExtras/QTorusMesh>
//#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DCore/QTransform>


GLBox::GLBox(QWidget *parent) : QOpenGLWidget(parent) {
    mode = DRAW_VERTEX;
    //setup timer
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    m_timer->start(1000/60);

}

GLBox::~GLBox()
{
    delete m_timer;
}

void GLBox::initializeGL() {
    // Set up the rendering context, load shaders and other resources, etc.:
    makeCurrent();
    initializeOpenGLFunctions();

    fgColor = QColor(0, 255, 0, 255) ;
    bgColor = QColor(255, 255, 255, 255);

    clearBg(bgColor);

    glMatrixMode(GL_PROJECTION);
    glEnable(GL_BLEND) ;
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    GLfloat mat_ambient[]={0.3,0.3,0.3,1.0};
    GLfloat mat_diffuse[]={1.6,1.6,0.6,1.0};
    GLfloat mat_specular[]={1.9,0.9,0.9,1.0};
    GLfloat mat_shininess[]={100.0};

    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);

    GLfloat light0_ambient[]={0.5,0.5,0.5,1.0};
    GLfloat light0_diffuse[]={1.0,1.0,1.0,1.0};
    GLfloat light0_specular[]={1.0,1.0,1.0,1.0};
    GLfloat light0_position[]={10.0,10.0,-7.0,0.0};

    glLightfv(GL_LIGHT0,GL_AMBIENT,light0_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light0_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light0_specular);
    glLightfv(GL_LIGHT0,GL_POSITION,light0_position);
    glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE,light0_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
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
    drawSphere();
}

void GLBox::drawSphere() {

    clearBg(bgColor);
    glClear(GL_COLOR_BUFFER_BIT);

    Sphere sphere(1, 32, 32);
    int const win_width  = 620; // retrieve window dimensions from
    int const win_height = 330; // framework of choice here
    float const win_aspect = (float)win_width / (float)win_height;

    glViewport(0, 0, win_width, win_height);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, win_aspect, 1, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Desenha as linhas da esfera (comentar para desenhar esfera sólida)
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    sphere.draw(0, 0, -5, 0, angle, angle);

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

void GLBox::nextFrame() {
    angle += 0.4;
    update();
}
