#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QColorDialog>
#include <QColor>
#include <glbox.h>

namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);

    GLBox *gl ;

    ~Principal();

private slots:
    void on_actionTabela_de_lados_triggered();

    void on_actionTabela_de_lados_ativos_triggered();

    void on_actionCor_da_linha_triggered();

    void on_actionCor_de_fundo_triggered();

    void on_pushButton_Point_clicked();

    void on_pushButton_Polyg_clicked();

    void on_pushButton_Clean_clicked();

    void on_pushButton_Fill_clicked();

private:
    Ui::Principal *ui;

};

#endif // PRINCIPAL_H
