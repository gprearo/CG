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

    model = QColor::Rgb;

    colorA = 0;
    colorB = 0;
    colorC = 0;
}

GLBox::~GLBox()
{
    delete m_timer;
}

void GLBox::initializeGL() {
    // Set up the rendering context, load shaders and other resources, etc.:
    makeCurrent();
    initializeOpenGLFunctions();

    fgColor = QColor(0, 0, 0, 255) ;
    bgColor = QColor(255, 255, 255, 255);

    clearBg(bgColor);

    glMatrixMode(GL_PROJECTION);
//    glEnable(GL_BLEND) ;
    glLoadIdentity();

//     glEnable(GL_CULL_FACE);

//    GLfloat mat_ambient[]={1.0,0.3,0.3,0.5};
//    GLfloat mat_diffuse[]={1.6,1.6,0.6,1.0};
//    GLfloat mat_specular[]={1.9,0.9,0.9,1.0};
//    GLfloat mat_shininess[]={100.0};

//    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
//    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
//    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
//    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);

//    GLfloat light0_ambient[]={1.0, 1.0, 1.0, 1.0};
//    GLfloat light0_diffuse[]={1.0, 1.0, 1.0, 10.0};
//    GLfloat light0_specular[]={1.0,1.0,1.0,1.0};
//    GLfloat light0_position[]={0.0,10.0,-9.0,0.0};

//    glLightfv(GL_LIGHT0,GL_AMBIENT,light0_ambient);
//    glLightfv(GL_LIGHT0,GL_DIFFUSE,light0_diffuse);
//    glLightfv(GL_LIGHT0,GL_SPECULAR,light0_specular);
//    glLightfv(GL_LIGHT0,GL_POSITION,light0_position);
//    glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE,light0_ambient);


//    glShadeModel(GL_SMOOTH);

    // Set up lighting for the scene
       GLfloat ambient[4] = {0.0f, 0.0f, 0.0f, 1.0f};
       glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

       glEnable(GL_DEPTH_TEST);
       glEnable(GL_LIGHT0);
       glEnable(GL_LIGHTING);
       glEnable(GL_COLOR_MATERIAL);
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
//    std::cout << fgColor.red() << std::endl;
    drawSphere();
//    drawCube();
}

void GLBox::drawSphere() {

    clearBg(bgColor);
    glClear(GL_COLOR_BUFFER_BIT);

    Sphere sphere(1, 25, 25);
    int const win_width  = 620; // retrieve window dimensions from
    int const win_height = 330; // framework of choice here
    float const win_aspect = (float)win_width / (float)win_height;

    glViewport(0, 0, win_width, win_height);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, win_aspect, 1, 10);

    if(model == QColor::Rgb) {
        fgColor.setRgb(colorA, colorB, colorC);
    } else if(model == QColor::Cmyk) {
        fgColor.setCmyk(colorA, colorB, colorC, 0);
    } else if(model == QColor::Hsv) {
        fgColor.setHsv(colorA, colorB, colorC, 0);
    }

    fgColor.convertTo(QColor::Rgb);

    glColor3ub(fgColor.red(), fgColor.green(), fgColor.blue());
    sphere.draw(0, 0, -5, rot.x(), rot.y(), rot.z());

}

void GLBox::drawCube() {
    clearBg(bgColor);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

     // Render a color-cube consisting of 6 quads with different colors
     glLoadIdentity();                 // Reset the model-view matrix


    int const win_width  = 620; // retrieve window dimensions from
    int const win_height = 330; // framework of choice here
    float const win_aspect = (float)win_width / (float)win_height;

    glViewport(0, 0, win_width, win_height);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, win_aspect, 0.1, 10);

//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();

    glTranslatef(0, 0.0f, -5.0f);  // Move left and into the screen

    glRotatef(rot.x(), 1, 0, 0);
    glRotatef(rot.y(), 0, 1, 0);
    glRotatef(rot.z(), 0, 0, 1);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
          // Top face (y = 1.0f)
          // Define vertices in counter-clockwise (CCW) order with normal pointing out
          glColor3f(0.0f, 1.0f, 0.0f);     // Green
          glVertex3f( 1.0f, 1.0f, -1.0f);
          glVertex3f(-1.0f, 1.0f, -1.0f);
          glVertex3f(-1.0f, 1.0f,  1.0f);
          glVertex3f( 1.0f, 1.0f,  1.0f);

          // Bottom face (y = -1.0f)
          glColor3f(1.0f, 0.5f, 0.0f);     // Orange
          glVertex3f( 1.0f, -1.0f,  1.0f);
          glVertex3f(-1.0f, -1.0f,  1.0f);
          glVertex3f(-1.0f, -1.0f, -1.0f);
          glVertex3f( 1.0f, -1.0f, -1.0f);

          // Front face  (z = 1.0f)
          glColor3f(1.0f, 0.0f, 0.0f);     // Red
          glVertex3f( 1.0f,  1.0f, 1.0f);
          glVertex3f(-1.0f,  1.0f, 1.0f);
          glVertex3f(-1.0f, -1.0f, 1.0f);
          glVertex3f( 1.0f, -1.0f, 1.0f);

          // Back face (z = -1.0f)
          glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
          glVertex3f( 1.0f, -1.0f, -1.0f);
          glVertex3f(-1.0f, -1.0f, -1.0f);
          glVertex3f(-1.0f,  1.0f, -1.0f);
          glVertex3f( 1.0f,  1.0f, -1.0f);

          // Left face (x = -1.0f)
          glColor3f(0.0f, 0.0f, 1.0f);     // Blue
          glVertex3f(-1.0f,  1.0f,  1.0f);
          glVertex3f(-1.0f,  1.0f, -1.0f);
          glVertex3f(-1.0f, -1.0f, -1.0f);
          glVertex3f(-1.0f, -1.0f,  1.0f);

          // Right face (x = 1.0f)
          glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
          glVertex3f(1.0f,  1.0f, -1.0f);
          glVertex3f(1.0f,  1.0f,  1.0f);
          glVertex3f(1.0f, -1.0f,  1.0f);
          glVertex3f(1.0f, -1.0f, -1.0f);
       glEnd();  // End of drawing color-cube
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
    //angle += 0.4;
//    std::cout << rot.x() << ", " << rotSpeed.x() << std::endl;
    rot.setX(rot.x() + rotSpeed.x());
    rot.setY(rot.y() + rotSpeed.y());
    rot.setZ(rot.z() + rotSpeed.z());
    update();
}

void GLBox::rotate(QVector3D ori) {
    std::cout << "rotate\n";
    this->rotSpeed.setX(rotSpeed.x() + ori.x());
    this->rotSpeed.setY(rotSpeed.y() + ori.y());
    this->rotSpeed.setZ(rotSpeed.z() + ori.z());
    std::cout << "rotSpeed.x() = " << rotSpeed.x();
}


void GLBox::setColorModel(QColor::Spec model) {
    this->model = model;
}

void GLBox::setColorA(int value) {
    colorA = value;
}

void GLBox::setColorB(int value) {
    colorB = value;
}

void GLBox::setColorC(int value) {
    colorC = value;
}
