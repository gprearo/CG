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
    world.cpp \
    sphere.cpp \
    cube.cpp

HEADERS += \
    glbox.h \
    principal.h \
    world.h \
    sphere.h \
    cube.h

FORMS += \
    principal.ui
