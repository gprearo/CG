#ifndef GLBOX_H
#define GLBOX_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QPolygon>
#include <QMouseEvent>
#include <QColor>
#include <QTimer>
#include <QVector3D>

#define DRAW_VERTEX 0
#define DRAW_POLYGON 1
#define FILL_POLYGON 2

class GLBox : public QOpenGLWidget, public QOpenGLFunctions {
Q_OBJECT
public:
    GLBox(QWidget *parent = 0);
    virtual ~GLBox();

    void draw();

    void setBgColor(QColor c);

    void rotate(QVector3D ori);

    void setColorModel(QColor::Spec model);
    void setColorA(int value);
    void setColorB(int value);
    void setColorC(int value);

protected:
    QTimer* m_timer; //Timer object for triggering updates

    QColor bgColor;
    QColor fgColor;

    int colorA;
    int colorB;
    int colorC;

    QColor::Spec model;

    void initializeGL();

    void resizeGL(int width, int height);

    void paintGL();

    void clearBg(QColor c) ;

    void drawVertex();
    void drawSphere();
    void drawCube();
    void drawPyramid();

private:
    int height = 400;
    int width = 800;

    QVector3D rotSpeed;
    QVector3D rot;

private slots:
    void nextFrame();
};

#endif // GLBOX_H
