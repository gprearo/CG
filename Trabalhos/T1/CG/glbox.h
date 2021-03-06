#ifndef GLBOX_H
#define GLBOX_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QPolygon>
#include <QMouseEvent>
#include <QColor>

#define DRAW_VERTEX 0
#define DRAW_POLYGON 1
#define FILL_POLYGON 2

class GLBox : public QOpenGLWidget, public QOpenGLFunctions{
public:
    GLBox(QWidget *parent) : QOpenGLWidget(parent) {mode = DRAW_VERTEX;}

    void draw();
    void reset();

    void setMode(short mode);

    void setBgColor(QColor c);
    void setFgColor(QColor c);
    void preencher() ;



protected:
    QColor bgColor;
    QColor fgColor;

    short mode;

    void initializeGL();

    void resizeGL(int width, int height);

    void paintGL();

    void clearBg(QColor c) ;
    void changeFg(QColor c) ;

    void drawVertex();
    void drawPolygon() ;
    void drawPixel(int x, int y) ;

private:
    int height = 300;
    int width = 600;

    QPolygon poly;

    void mousePressEvent(QMouseEvent *event);
};

#endif // GLBOX_H
