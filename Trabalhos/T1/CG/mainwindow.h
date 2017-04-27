#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glbox.h"

class MainWindow : public QMainWindow { Q_OBJECT
public:
    MainWindow();
    void draw();
    int height  ;
    int width ;
private:
    GLBox *gl;

};


#endif // MAINWINDOW_H
