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
    void reset();

    void setMode(short mode);

    void setBgColor(QColor c);
    void setFgColor(QColor c);
    void preencher() ;

    void display();

    void rotate(QVector3D ori);



protected:

    QTimer* m_timer; //Timer object for triggering updates

    QColor bgColor;
    QColor fgColor;

    short mode;

    void initializeGL();

    void resizeGL(int width, int height);

    void paintGL();

    void clearBg(QColor c) ;
    void changeFg(QColor c) ;

    void drawVertex();
    void drawSphere() ;
    void drawCube();
    void drawPixel(int x, int y) ;

private:
    int height = 300;
    int width = 600;

    QVector3D rotSpeed;
    QVector3D rot;

    QPolygon poly;

private slots:
    void nextFrame();
};

#endif // GLBOX_H
