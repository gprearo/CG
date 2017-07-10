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

    this->setWindowTitle("Trabalho 3 - Modelos de cor");

    // Bloqueia o redimensionamento da janela
    this->setFixedSize(this->width(), this->height());
    this->statusBar()->setSizeGripEnabled(false);

    lblA = "RED: ";
    lblB = "GREEN: ";
    lblC = "BLUE: ";
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

void Principal::on_horizontalSlider_a_valueChanged(int value) {
    ui->label_a->setText(lblA + QString::number(value));
    gl->setColorA(value);
}
void Principal::on_horizontalSlider_b_valueChanged(int value) {
    ui->label_b->setText(lblB + QString::number(value));
    gl->setColorB(value);
}

void Principal::on_horizontalSlider_c_valueChanged(int value) {
    ui->label_c->setText(lblC + QString::number(value));
    gl->setColorC(value);
}



void Principal::on_radioButton_CMY_toggled(bool checked) {
    if(!checked)
        return;
    lblA = "CYAN: ";
    lblB = "MAGENTA: ";
    lblC = "YELLOW: ";

    ui->horizontalSlider_a->setMaximum(255);
    gl->setColorA(ui->horizontalSlider_a->value());
    ui->label_a->setText(lblA + QString::number(ui->horizontalSlider_a->value()));
    ui->label_b->setText(lblB + QString::number(ui->horizontalSlider_b->value()));
    ui->label_c->setText(lblC + QString::number(ui->horizontalSlider_c->value()));
    gl->setColorModel(QColor::Cmyk);
}

void Principal::on_radioButton_RGB_toggled(bool checked) {
    if(!checked)
        return;
    lblA = "RED: ";
    lblB = "GREEN: ";
    lblC = "BLUE: ";

    ui->horizontalSlider_a->setMaximum(255);
    gl->setColorA(ui->horizontalSlider_a->value());
    ui->label_a->setText(lblA + QString::number(ui->horizontalSlider_a->value()));
    ui->label_b->setText(lblB + QString::number(ui->horizontalSlider_b->value()));
    ui->label_c->setText(lblC + QString::number(ui->horizontalSlider_c->value()));
    gl->setColorModel(QColor::Rgb);
}

void Principal::on_radioButton_HSV_toggled(bool checked) {
    if(!checked)
        return;
    lblA = "HUE: ";
    lblB = "SATURATION: ";
    lblC = "VALUE: ";

    ui->horizontalSlider_a->setMaximum(359);
    ui->label_a->setText(lblA + QString::number(ui->horizontalSlider_a->value()));
    ui->label_b->setText(lblB + QString::number(ui->horizontalSlider_b->value()));
    ui->label_c->setText(lblC + QString::number(ui->horizontalSlider_c->value()));
    gl->setColorModel(QColor::Hsv);

}
