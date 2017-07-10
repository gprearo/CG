/********************************************************************************
** Form generated from reading UI file 'principal.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPAL_H
#define UI_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <glbox.h>

QT_BEGIN_NAMESPACE

class Ui_Principal
{
public:
    QAction *actionCor_da_linha;
    QAction *actionCor_de_fundo;
    QAction *actionTabela_de_lados;
    QAction *actionTabela_de_lados_ativos;
    QWidget *centralwidget;
    GLBox *openGLWidget;
    QRadioButton *radioButton_RGB;
    QRadioButton *radioButton_CMY;
    QRadioButton *radioButton_HSV;
    QSlider *horizontalSlider_a;
    QSlider *horizontalSlider_b;
    QSlider *horizontalSlider_c;
    QLabel *label_a;
    QLabel *label_b;
    QLabel *label_c;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuPreenchimento_de_pol_gonos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Principal)
    {
        if (Principal->objectName().isEmpty())
            Principal->setObjectName(QStringLiteral("Principal"));
        Principal->resize(847, 436);
        actionCor_da_linha = new QAction(Principal);
        actionCor_da_linha->setObjectName(QStringLiteral("actionCor_da_linha"));
        actionCor_de_fundo = new QAction(Principal);
        actionCor_de_fundo->setObjectName(QStringLiteral("actionCor_de_fundo"));
        actionTabela_de_lados = new QAction(Principal);
        actionTabela_de_lados->setObjectName(QStringLiteral("actionTabela_de_lados"));
        actionTabela_de_lados->setCheckable(true);
        actionTabela_de_lados_ativos = new QAction(Principal);
        actionTabela_de_lados_ativos->setObjectName(QStringLiteral("actionTabela_de_lados_ativos"));
        actionTabela_de_lados_ativos->setCheckable(true);
        centralwidget = new QWidget(Principal);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        openGLWidget = new GLBox(centralwidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(0, 0, 621, 331));
        radioButton_RGB = new QRadioButton(centralwidget);
        radioButton_RGB->setObjectName(QStringLiteral("radioButton_RGB"));
        radioButton_RGB->setGeometry(QRect(640, 20, 61, 20));
        radioButton_RGB->setChecked(true);
        radioButton_CMY = new QRadioButton(centralwidget);
        radioButton_CMY->setObjectName(QStringLiteral("radioButton_CMY"));
        radioButton_CMY->setGeometry(QRect(640, 50, 61, 20));
        radioButton_HSV = new QRadioButton(centralwidget);
        radioButton_HSV->setObjectName(QStringLiteral("radioButton_HSV"));
        radioButton_HSV->setGeometry(QRect(640, 80, 61, 20));
        horizontalSlider_a = new QSlider(centralwidget);
        horizontalSlider_a->setObjectName(QStringLiteral("horizontalSlider_a"));
        horizontalSlider_a->setGeometry(QRect(640, 150, 160, 20));
        horizontalSlider_a->setMaximum(255);
        horizontalSlider_a->setOrientation(Qt::Horizontal);
        horizontalSlider_b = new QSlider(centralwidget);
        horizontalSlider_b->setObjectName(QStringLiteral("horizontalSlider_b"));
        horizontalSlider_b->setGeometry(QRect(640, 200, 160, 20));
        horizontalSlider_b->setMaximum(255);
        horizontalSlider_b->setOrientation(Qt::Horizontal);
        horizontalSlider_c = new QSlider(centralwidget);
        horizontalSlider_c->setObjectName(QStringLiteral("horizontalSlider_c"));
        horizontalSlider_c->setGeometry(QRect(640, 250, 160, 20));
        horizontalSlider_c->setMaximum(255);
        horizontalSlider_c->setOrientation(Qt::Horizontal);
        label_a = new QLabel(centralwidget);
        label_a->setObjectName(QStringLiteral("label_a"));
        label_a->setGeometry(QRect(650, 130, 141, 16));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_a->sizePolicy().hasHeightForWidth());
        label_a->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        label_a->setFont(font);
        label_b = new QLabel(centralwidget);
        label_b->setObjectName(QStringLiteral("label_b"));
        label_b->setGeometry(QRect(650, 180, 141, 16));
        label_b->setFont(font);
        label_c = new QLabel(centralwidget);
        label_c->setObjectName(QStringLiteral("label_c"));
        label_c->setGeometry(QRect(650, 230, 141, 16));
        label_c->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(640, 0, 121, 16));
        Principal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Principal);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 847, 27));
        menuPreenchimento_de_pol_gonos = new QMenu(menubar);
        menuPreenchimento_de_pol_gonos->setObjectName(QStringLiteral("menuPreenchimento_de_pol_gonos"));
        Principal->setMenuBar(menubar);
        statusbar = new QStatusBar(Principal);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Principal->setStatusBar(statusbar);

        menubar->addAction(menuPreenchimento_de_pol_gonos->menuAction());
        menuPreenchimento_de_pol_gonos->addAction(actionCor_de_fundo);

        retranslateUi(Principal);

        QMetaObject::connectSlotsByName(Principal);
    } // setupUi

    void retranslateUi(QMainWindow *Principal)
    {
        Principal->setWindowTitle(QApplication::translate("Principal", "MainWindow", 0));
        actionCor_da_linha->setText(QApplication::translate("Principal", "&Cor da linha", 0));
        actionCor_de_fundo->setText(QApplication::translate("Principal", "Cor &de fundo", 0));
        actionTabela_de_lados->setText(QApplication::translate("Principal", "&Tabela de lados", 0));
        actionTabela_de_lados_ativos->setText(QApplication::translate("Principal", "Tabela &de lados ativos", 0));
        radioButton_RGB->setText(QApplication::translate("Principal", "R&GB", 0));
        radioButton_CMY->setText(QApplication::translate("Principal", "CMY", 0));
        radioButton_HSV->setText(QApplication::translate("Principal", "HS&V", 0));
        label_a->setText(QApplication::translate("Principal", "RED: 0", 0));
        label_b->setText(QApplication::translate("Principal", "GREEN: 0", 0));
        label_c->setText(QApplication::translate("Principal", "BLUE: 0", 0));
        label->setText(QApplication::translate("Principal", "Escolha o modelo:", 0));
        menuPreenchimento_de_pol_gonos->setTitle(QApplication::translate("Principal", "&Cores", 0));
    } // retranslateUi

};

namespace Ui {
    class Principal: public Ui_Principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
