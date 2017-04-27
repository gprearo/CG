#ifndef GLBOX_H
#define GLBOX_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QPolygon>
#include <QMouseEvent>
#include <QColor>

class GLBox : public QOpenGLWidget, public QOpenGLFunctions{
public:
    GLBox(QWidget *parent) : QOpenGLWidget(parent) { }

    void draw();
    QPolygon poly;
    int height = 300;
    int width = 600;

    void setBgColor(QColor c) ;
    void setFgColor(QColor c) ;

protected:
    QColor bgColor;
    QColor fgColor ;


    void initializeGL();

    void resizeGL(int width, int height);

    void paintGL();

    void clearBg(QColor c) ;
    void changeFg(QColor c) ;

    void drawPolygon() ;
private:
    void mousePressEvent(QMouseEvent *event);
};

#endif // GLBOX_H
