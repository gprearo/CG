#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QColorDialog>
#include <QColor>
#include <glbox.h>

namespace Ui {
class Principal;
}

class Principal : public QMainWindow {
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);

    GLBox *gl ;

    ~Principal();

private slots:

    void on_actionCor_de_fundo_triggered();

    void on_horizontalSlider_a_valueChanged(int value);

    void on_horizontalSlider_b_valueChanged(int value);

    void on_horizontalSlider_c_valueChanged(int value);

    void on_radioButton_CMY_toggled(bool checked);

    void on_radioButton_RGB_toggled(bool checked);

    void on_radioButton_HSV_toggled(bool checked);

private:
    Ui::Principal *ui;

    QString lblA;
    QString lblB;
    QString lblC;

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
};

#endif // PRINCIPAL_H
