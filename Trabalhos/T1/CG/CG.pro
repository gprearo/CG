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
    principal.cpp

HEADERS += \
    glbox.h \
    principal.h

FORMS += \
    principal.ui
