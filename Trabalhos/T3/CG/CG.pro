QT += core gui widgets
QT += opengl
QT += widgets

CONFIG += c++11

TARGET = CG
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -lglut -lGLU -lGL

SOURCES += main.cpp \
    glbox.cpp \
    principal.cpp \
    sphere.cpp

HEADERS += \
    glbox.h \
    principal.h \
    sphere.h

FORMS += \
    principal.ui
