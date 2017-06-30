#include "principal.h"
#include "ui_principal.h"
#include "glbox.h"
#include <iostream>

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);

    gl = ui->openGLWidget;// new GLBox(ui->openGLWidget) ;
    //gl->resize(ui->openGLWidget->width(), ui->openGLWidget->height());

    this->setWindowTitle("Trabalho 2 - Modelos de iluminação");

    // Bloqueia o redimensionamento da janela
    this->setFixedSize(this->width(), this->height());
    this->statusBar()->setSizeGripEnabled(false);
}


Principal::~Principal() {
    delete ui;
}

void Principal::on_actionCor_da_linha_triggered() {
    QColor color = QColorDialog::getColor(Qt::yellow, this);
    if(color.isValid())
        gl->setFgColor(color);
}

void Principal::on_actionCor_de_fundo_triggered() {
    QColor color = QColorDialog::getColor(Qt::yellow, this);
    if(color.isValid())
        gl->setBgColor(color);
}

void Principal::on_checkBox_Phong_toggled(bool checked)
{

}


void Principal::keyPressEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) {
    } else if (event->type() == QEvent::KeyPress) {
        std::cout << "keypress\n";
        if(event->key() == Qt::Key_W) {
            gl->rotate(QVector3D(0, 0, 1));
        }
        if(event->key() == Qt::Key_A) {
            gl->rotate(QVector3D(0, -1, 0));
        }
        if(event->key() == Qt::Key_S) {
            gl->rotate(QVector3D(0, 0, -1));
        }
        if(event->key() == Qt::Key_D) {
            gl->rotate(QVector3D(0, 1, 0));
        }
    }
}

void Principal::keyReleaseEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) {
    } else if (event->type() == QEvent::KeyRelease) {
        std::cout << "keyrelease\n";
        if(event->key() == Qt::Key_W) {
            gl->rotate(QVector3D(0, 0, -1));
        }
        if(event->key() == Qt::Key_A) {
            gl->rotate(QVector3D(0, 1, 0));
        }
        if(event->key() == Qt::Key_S) {
            gl->rotate(QVector3D(0, 0, 1));
        }
        if(event->key() == Qt::Key_D) {
            gl->rotate(QVector3D(0, -1, 0));
        }
    }
}

void Principal::mouseMoveEvent(QMouseEvent *event) {
    std::cout << event->x() << ", " << event->y() << std::endl;
}
