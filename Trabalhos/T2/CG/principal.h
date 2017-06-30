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


    void on_actionCor_da_linha_triggered();

    void on_actionCor_de_fundo_triggered();

    void on_checkBox_Phong_toggled(bool checked);

private:
    Ui::Principal *ui;

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);


    void mouseMoveEvent(QMouseEvent *event);

};

#endif // PRINCIPAL_H
