#include "glbox.h"
#include <iostream>
#include <QPainter>
#include "sphere.h"
#include <GL/glut.h>
#include <QGLWidget>

int const win_width  = 800; // OpenGL frame width
int const win_height = 400; // OpenGL frame height
float const win_aspect = (float)win_width / (float)win_height; // OpenGL frame aspect ratio

GLBox::GLBox(QWidget *parent) : QOpenGLWidget(parent) {
    //setup timer
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    m_timer->start(1000/60);

    model = QColor::Rgb;

    colorA = 0;
    colorB = 0;
    colorC = 0;
}

GLBox::~GLBox() {
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
    glLoadIdentity();

    // Set up lighting for the scene
    GLfloat ambient[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

// Handle OpenGL frame resize
void GLBox::resizeGL(int width, int height) {
    // Changes the global height and width from component
    this->height = height;
    this->width = width;
    glViewport(0, 0, width, height);
    glOrtho(0.0, width, 0.0, height, 1.0, -1.0 );
}

void GLBox::paintGL() {
    clearBg(bgColor);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Draw objects */
    drawSphere();
    drawCube();
    drawPyramid();
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

// Changes the background color
void GLBox::setBgColor(QColor c) {
    bgColor = c;
    draw();
}

// Updates the frame
void GLBox::nextFrame() {
    rot.setX(rot.x() + rotSpeed.x());
    rot.setY(rot.y() + rotSpeed.y());
    rot.setZ(rot.z() + rotSpeed.z());
    update();
}

// Set rotation speeds
void GLBox::rotate(QVector3D ori) {
    this->rotSpeed.setX(rotSpeed.x() + ori.x());
    this->rotSpeed.setY(rotSpeed.y() + ori.y());
    this->rotSpeed.setZ(rotSpeed.z() + ori.z());
}

// Set color model
void GLBox::setColorModel(QColor::Spec model) {
    this->model = model;
}

// Set color component A
void GLBox::setColorA(int value) {
    colorA = value;
}

// Set color component B
void GLBox::setColorB(int value) {
    colorB = value;
}

// Set color component C
void GLBox::setColorC(int value) {
    colorC = value;
}

// Draw the sphere
void GLBox::drawSphere() {
    Sphere sphere(1, 25, 25);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, win_aspect, 1, 10);

    glTranslatef(0.0f, 0.0f, 0.0f);  // Move left and into the screen

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

// Draw the cube
void GLBox::drawCube() {
    double vertices[8][3] = {   // Cube vertices
        { 1.0f, 1.0f, 1.0f},    // 0
        { 1.0f, 1.0f,-1.0f},    // 1
        { 1.0f,-1.0f,-1.0f},    // 2
        {-1.0f,-1.0f,-1.0f},    // 3
        {-1.0f,-1.0f, 1.0f},    // 4
        {-1.0f, 1.0f, 1.0f},    // 5
        {-1.0f, 1.0f,-1.0f},    // 6
        { 1.0f,-1.0f, 1.0f}     // 7
    };

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, win_aspect, 0.1, 10);

    /* Translate the object */
    glTranslatef(-3.5f, 0.0f, -7.0f);  // Move left and into the screen

    /* Rotate the object */
    glRotatef(rot.x(), 1, 0, 0);
    glRotatef(rot.y(), 0, 1, 0);
    glRotatef(rot.z(), 0, 0, 1);

    /* Get input values and color model */
    if(model == QColor::Rgb) {
        fgColor.setRgb(colorA, colorB, colorC);
    } else if(model == QColor::Cmyk) {
        fgColor.setCmyk(colorA, colorB, colorC, 0);
    } else if(model == QColor::Hsv) {
        fgColor.setHsv(colorA, colorB, colorC, 0);
    }
    fgColor.convertTo(QColor::Rgb); // Converts the color to RGB

    glColor3ub(fgColor.red(), fgColor.green(), fgColor.blue()); // Change color

    /* Draw faces */
    glBegin(GL_QUADS);  // Begin of drawing cube
        // Top face (y = 1.0f)
        // Define vertices in counter-clockwise (CCW) order with normal pointing out
        glVertex3f( 1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f,  1.0f);
        glVertex3f( 1.0f, 1.0f,  1.0f);

        // Bottom face (y = -1.0f)
        glVertex3f( 1.0f, -1.0f,  1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);

        // Front face  (z = 1.0f)
        glVertex3f( 1.0f,  1.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f( 1.0f, -1.0f, 1.0f);

        // Back face (z = -1.0f)
        glVertex3f( 1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f( 1.0f,  1.0f, -1.0f);

        // Left face (x = -1.0f)
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);

        // Right face (x = 1.0f)
        glVertex3f(1.0f,  1.0f, -1.0f);
        glVertex3f(1.0f,  1.0f,  1.0f);
        glVertex3f(1.0f, -1.0f,  1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();  // End of drawing cube

    /* Draw edges */
    glColor3f(0.0f, 0.0f, 0.0f);    // Black
    glBegin(GL_LINES);  // Start drawing edges
        //Front Lines
        //Left
        glVertex3f(vertices[5][0],vertices[5][1],vertices[5][2]);
        glVertex3f(vertices[4][0],vertices[4][1],vertices[4][2]);
        //Top
        glVertex3f(vertices[5][0],vertices[5][1],vertices[5][2]);
        glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
        //Bottom
        glVertex3f(vertices[4][0],vertices[4][1],vertices[4][2]);
        glVertex3f(vertices[7][0],vertices[7][1],vertices[7][2]);
        //Right
        glVertex3f(vertices[7][0],vertices[7][1],vertices[7][2]);
        glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
        //Middle Lines
        //Top Left
        glVertex3f(vertices[6][0],vertices[6][1],vertices[6][2]);
        glVertex3f(vertices[5][0],vertices[5][1],vertices[5][2]);
        //Top Right
        glVertex3f(vertices[1][0],vertices[1][1],vertices[1][2]);
        glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
        //Bottom Left
        glVertex3f(vertices[3][0],vertices[3][1],vertices[3][2]);
        glVertex3f(vertices[4][0],vertices[4][1],vertices[4][2]);
        //Bottom Right
        glVertex3f(vertices[2][0],vertices[2][1],vertices[2][2]);
        glVertex3f(vertices[7][0],vertices[7][1],vertices[7][2]);
        //Back Lines
        //Left
        glVertex3f(vertices[6][0],vertices[6][1],vertices[6][2]);
        glVertex3f(vertices[3][0],vertices[3][1],vertices[3][2]);
        //Top
        glVertex3f(vertices[6][0],vertices[6][1],vertices[6][2]);
        glVertex3f(vertices[1][0],vertices[1][1],vertices[1][2]);
        //Bottom
        glVertex3f(vertices[3][0],vertices[3][1],vertices[3][2]);
        glVertex3f(vertices[2][0],vertices[2][1],vertices[2][2]);
        //Right
        glVertex3f(vertices[2][0],vertices[2][1],vertices[2][2]);
        glVertex3f(vertices[1][0],vertices[1][1],vertices[1][2]);
    glEnd();    // Done drawing edges
}

// Draw the pyramid
void GLBox::drawPyramid() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, win_aspect, 0.1, 10);

    /* Translate the object */
    glTranslatef(1.8f, 0.0f, -4.0f);

    /* Rotate the object */
    glRotatef(rot.x(), 1, 0, 0);
    glRotatef(rot.y(), 0, 1, 0);
    glRotatef(rot.z(), 0, 0, 1);

    /* Get input values and color model */
    if(model == QColor::Rgb) {
        fgColor.setRgb(colorA, colorB, colorC);
    } else if(model == QColor::Cmyk) {
        fgColor.setCmyk(colorA, colorB, colorC, 0);
    } else if(model == QColor::Hsv) {
        fgColor.setHsv(colorA, colorB, colorC, 0);
    }
    fgColor.convertTo(QColor::Rgb); // Converts the color to RGB

    glColor3ub(fgColor.red(), fgColor.green(), fgColor.blue()); // Change color

    /* Draw faces */
    glBegin(GL_POLYGON);    // Begin of drawing pyramid
        glVertex3f(0.5,-0.5,0.0);
        glVertex3f(0.5,0.5,0.0);
        glVertex3f(-0.5,0.5,0.0);
        glVertex3f(-0.5,-0.5,0.0);

        glVertex3f(0.5f, -0.5f,  0.0f);
        glVertex3f(0.5f,  0.5f,  0.0f);
        glVertex3f(0.0f, 0.0f, -0.5f);

        glVertex3f(0.5f, 0.5f,  0.0f);
        glVertex3f(-0.5f,  0.5f,  0.0f);
        glVertex3f(0.0f, 0.0f, -0.5f);

        glVertex3f(-0.5f, 0.5f,  0.0f);
        glVertex3f(-0.5f, -0.5f,  0.0f);
        glVertex3f(0.0f, 0.0f, -0.5f);

        glVertex3f(-0.5f, -0.5f,  0.0f);
        glVertex3f(0.5f, -0.5f,  0.0f);
        glVertex3f(0.0f, 0.0f, -0.5f);
    glEnd();    // End of drawing pyramid

    /* Draw edges */
    glColor3f(0.0f, 0.0f, 0.0f);    // Black

    glBegin(GL_LINE_LOOP);  // Draw base
        glVertex3f(0.5,-0.5,0.0);
        glVertex3f(0.5,0.5,0.0);
        glVertex3f(-0.5,0.5,0.0);
        glVertex3f(-0.5,-0.5,0.0);
    glEnd();

    glBegin(GL_LINES);  // Draw diagonals
        glVertex3f(0.5,-0.5,0.0);
        glVertex3f(0.0,0.0,-0.5);

        glVertex3f(0.5,0.5,0.0);
        glVertex3f(0.0,0.0,-0.5);

        glVertex3f(-0.5,0.5,0.0);
        glVertex3f(0.0,0.0,-0.5);

        glVertex3f(-0.5,-0.5,0.0);
        glVertex3f(0.0,0.0,-0.5);
    glEnd();
}
