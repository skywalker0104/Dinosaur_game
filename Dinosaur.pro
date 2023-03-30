#-------------------------------------------------
#
# Project created by QtCreator 2022-11-03T00:02:27
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dinosaur
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    scene.cpp \
    dinosaur.cpp \
    cactus.cpp \
    score.cpp \
    meat.cpp

HEADERS  += widget.h \
    scene.h \
    dinosaur.h \
    cactus.h \
    score.h \
    meat.h

FORMS    += widget.ui

RESOURCES += \
    resource.qrc
