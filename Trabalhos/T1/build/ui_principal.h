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
#include <QtWidgets/QPushButton>
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
    QPushButton *pushButton_Point;
    QPushButton *pushButton_Polyg;
    QPushButton *pushButton_Polyg_2;
    QPushButton *pushButton_Polyg_3;
    QMenuBar *menubar;
    QMenu *menuPreenchimento_de_pol_gonos;
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
        pushButton_Point = new QPushButton(centralwidget);
        pushButton_Point->setObjectName(QStringLiteral("pushButton_Point"));
        pushButton_Point->setGeometry(QRect(130, 10, 90, 31));
        pushButton_Polyg = new QPushButton(centralwidget);
        pushButton_Polyg->setObjectName(QStringLiteral("pushButton_Polyg"));
        pushButton_Polyg->setGeometry(QRect(240, 10, 90, 31));
        pushButton_Polyg_2 = new QPushButton(centralwidget);
        pushButton_Polyg_2->setObjectName(QStringLiteral("pushButton_Polyg_2"));
        pushButton_Polyg_2->setGeometry(QRect(350, 10, 90, 31));
        pushButton_Polyg_3 = new QPushButton(centralwidget);
        pushButton_Polyg_3->setObjectName(QStringLiteral("pushButton_Polyg_3"));
        pushButton_Polyg_3->setGeometry(QRect(460, 10, 90, 31));
        Principal->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Principal);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 22));
        menuPreenchimento_de_pol_gonos = new QMenu(menubar);
        menuPreenchimento_de_pol_gonos->setObjectName(QStringLiteral("menuPreenchimento_de_pol_gonos"));
        Principal->setMenuBar(menubar);
        statusbar = new QStatusBar(Principal);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Principal->setStatusBar(statusbar);

        menubar->addAction(menuPreenchimento_de_pol_gonos->menuAction());
        menuPreenchimento_de_pol_gonos->addAction(actionCor_da_linha);
        menuPreenchimento_de_pol_gonos->addAction(actionCor_de_fundo);

        retranslateUi(Principal);

        QMetaObject::connectSlotsByName(Principal);
    } // setupUi

    void retranslateUi(QMainWindow *Principal)
    {
        Principal->setWindowTitle(QApplication::translate("Principal", "MainWindow", Q_NULLPTR));
        actionCor_da_linha->setText(QApplication::translate("Principal", "&Cor da linha", Q_NULLPTR));
        actionCor_de_fundo->setText(QApplication::translate("Principal", "Cor &de fundo", Q_NULLPTR));
        actionTabela_de_lados->setText(QApplication::translate("Principal", "&Tabela de lados", Q_NULLPTR));
        actionTabela_de_lados_ativos->setText(QApplication::translate("Principal", "Tabela &de lados ativos", Q_NULLPTR));
        pushButton_Point->setText(QApplication::translate("Principal", "Pontos", Q_NULLPTR));
        pushButton_Polyg->setText(QApplication::translate("Principal", "Pol\303\255gono", Q_NULLPTR));
        pushButton_Polyg_2->setText(QApplication::translate("Principal", "Limpar", Q_NULLPTR));
        pushButton_Polyg_3->setText(QApplication::translate("Principal", "Preencher", Q_NULLPTR));
        menuPreenchimento_de_pol_gonos->setTitle(QApplication::translate("Principal", "&Cores", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Principal: public Ui_Principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
