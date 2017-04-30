QT += core gui widgets
QT += opengl
QT += widgets

CONFIG += c++11 -lglut

LIBS += -lglut

TARGET = CG
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    glbox.cpp \
    principal.cpp \
    edge.cpp \
    edgetable.cpp \
    activeedgetable.cpp

HEADERS += \
    glbox.h \
    principal.h \
    edge.h \
    edgetable.h \
    activeedgetable.h

FORMS += \
    principal.ui
