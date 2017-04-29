#include "principal.h"
#include "ui_principal.h"
#include "glbox.h"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);

    gl = new GLBox(ui->openGLWidget) ;
    gl->resize(ui->openGLWidget->width(), ui->openGLWidget->height());
}


Principal::~Principal()
{
    delete ui;
}

void Principal::on_actionTabela_de_lados_triggered()
{
    ui->actionTabela_de_lados->setChecked(true);
    ui->actionTabela_de_lados_ativos->setChecked(false);
}

void Principal::on_actionTabela_de_lados_ativos_triggered()
{
    ui->actionTabela_de_lados->setChecked(false);
    ui->actionTabela_de_lados_ativos->setChecked(true);
}

void Principal::on_actionCor_da_linha_triggered()
{
    QColor color = QColorDialog::getColor(Qt::yellow, this );
    gl->setFgColor(color);
}

void Principal::on_actionCor_de_fundo_triggered()
{
    QColor color = QColorDialog::getColor(Qt::yellow, this );
    gl->setBgColor(color);
}
