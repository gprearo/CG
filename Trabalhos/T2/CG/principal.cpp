#include "principal.h"
#include "ui_principal.h"
#include "glbox.h"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);

    gl = new GLBox(ui->openGLWidget) ;
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
