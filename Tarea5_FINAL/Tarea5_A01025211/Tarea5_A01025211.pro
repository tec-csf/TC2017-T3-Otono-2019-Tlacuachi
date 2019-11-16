#-------------------------------------------------
#
# Project created by QtCreator 2019-11-15T16:36:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tarea5_A01025211
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    transformaciones.cpp \
    poligono.cpp \
    arco.cpp \
    cubo.cpp \
    cono.cpp \
    prisma_triangular.cpp \
    prisma_rectangular.cpp \
    referencias.cpp

HEADERS += \
        mainwindow.h \
    transformaciones.h \
    poligono.h \
    arco.h \
    cubo.h \
    cono.h \
    prisma_triangular.h \
    prisma_rectangular.h \
    referencias.h

FORMS += \
        mainwindow.ui \
    poligono.ui \
    arco.ui \
    cubo.ui \
    cono.ui \
    prisma_triangular.ui \
    prisma_rectangular.ui \
    referencias.ui
