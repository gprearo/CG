/********************************************************************************
** Form generated from reading UI file 'principal.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Principal
{
public:
    QAction *actionCor_da_linha;
    QAction *actionCor_de_fundo;
    QAction *actionTabela_de_lados;
    QAction *actionTabela_de_lados_ativos;
    QWidget *centralwidget;
    QOpenGLWidget *openGLWidget;
    QMenuBar *menubar;
    QMenu *menuPreenchimento_de_pol_gonos;
    QMenu *menuM_todos_de_preenchimento;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Principal)
    {
        if (Principal->objectName().isEmpty())
            Principal->setObjectName(QStringLiteral("Principal"));
        Principal->resize(640, 480);
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
        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 50, 621, 331));
        Principal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Principal);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 22));
        menuPreenchimento_de_pol_gonos = new QMenu(menubar);
        menuPreenchimento_de_pol_gonos->setObjectName(QStringLiteral("menuPreenchimento_de_pol_gonos"));
        menuM_todos_de_preenchimento = new QMenu(menubar);
        menuM_todos_de_preenchimento->setObjectName(QStringLiteral("menuM_todos_de_preenchimento"));
        Principal->setMenuBar(menubar);
        statusbar = new QStatusBar(Principal);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Principal->setStatusBar(statusbar);

        menubar->addAction(menuPreenchimento_de_pol_gonos->menuAction());
        menubar->addAction(menuM_todos_de_preenchimento->menuAction());
        menuPreenchimento_de_pol_gonos->addAction(actionCor_da_linha);
        menuPreenchimento_de_pol_gonos->addAction(actionCor_de_fundo);
        menuM_todos_de_preenchimento->addAction(actionTabela_de_lados);
        menuM_todos_de_preenchimento->addAction(actionTabela_de_lados_ativos);

        retranslateUi(Principal);

        QMetaObject::connectSlotsByName(Principal);
    } // setupUi

    void retranslateUi(QMainWindow *Principal)
    {
        Principal->setWindowTitle(QApplication::translate("Principal", "MainWindow", Q_NULLPTR));
        actionCor_da_linha->setText(QApplication::translate("Principal", "Cor da linha", Q_NULLPTR));
        actionCor_de_fundo->setText(QApplication::translate("Principal", "Cor de fundo", Q_NULLPTR));
        actionTabela_de_lados->setText(QApplication::translate("Principal", "Tabela de lados", Q_NULLPTR));
        actionTabela_de_lados_ativos->setText(QApplication::translate("Principal", "Tabela de lados ativos", Q_NULLPTR));
        menuPreenchimento_de_pol_gonos->setTitle(QApplication::translate("Principal", "Cores", Q_NULLPTR));
        menuM_todos_de_preenchimento->setTitle(QApplication::translate("Principal", "Preencher", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Principal: public Ui_Principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
