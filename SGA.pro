#-------------------------------------------------
#
# Project created by QtCreator 2014-06-18T09:07:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SGA
TEMPLATE = app


SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/Components/TestWidget.cpp \
    src/MainView.cpp \
    src/ObjectBuilder.cpp \
    src/View.cpp

HEADERS  += include/mainwindow.hpp \
    include/Components/TestWidget.hpp \
    include/MainView.hpp \
    include/ObjectBuilder.hpp \
    include/View.hpp

FORMS    += resources/mainwindow.ui \
    resources/TestWidget.ui

INCLUDEPATH += "include"

QMAKE_CXXFLAGS += -std=c++11
