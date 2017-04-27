QT += core gui widgets
QT += opengl
QT += widgets

CONFIG += c++11

TARGET = CG
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    glbox.cpp \
    principal.cpp

HEADERS += \
    mainwindow.h \
    glbox.h \
    principal.h

FORMS += \
    principal.ui
