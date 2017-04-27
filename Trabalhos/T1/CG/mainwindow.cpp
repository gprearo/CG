#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow() {
    height = 500 ;
    width = 400 ;
    resize(width, height);
    gl = new GLBox(this);
    this->setCentralWidget(gl);

//    QThread::msleep(1000);




}

void MainWindow::draw() {
//        gl->poly << QPointF(0.5, 1.0);
//        gl->poly << QPointF(0.0, 0.0);
        gl->update();
}
