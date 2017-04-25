#ifndef GLBOX_H
#define GLBOX_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class GLBox : public QOpenGLWidget, public QOpenGLFunctions{
public:
    GLBox(QWidget *parent) : QOpenGLWidget(parent) { }

    void draw();
    QPolygon poly;

protected:
    void initializeGL();

    void resizeGL(int width, int height);

    void paintGL();

private:
    void mousePressEvent(QMouseEvent *event);
};

#endif // GLBOX_H
