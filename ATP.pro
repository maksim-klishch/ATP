#-------------------------------------------------
#
# Project created by QtCreator 2020-11-18T21:11:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ATP
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
    Expression/term.cpp \
    Expression/Operators/and.cpp \
    Expression/variable.cpp \
    CNF/cnf.cpp \
    CNF/resolution.cpp \
    Expression/Operators/or.cpp \
    Expression/variablesregister.cpp \
    Expression/expression.cpp \
    Expression/atom.cpp \
    Expression/binaryoperator.cpp \
    Expression/unaryoperator.cpp \
    Expression/Operators/not.cpp

HEADERS += \
        mainwindow.h \
    Expression/term.h \
    Expression/Operators/and.h \
    Expression/variable.h \
    CNF/cnf.h \
    CNF/resolution.h \
    Expression/Operators/or.h \
    Expression/variablesregister.h \
    Expression/expression.h \
    Expression/atom.h \
    Expression/binaryoperator.h \
    Expression/unaryoperator.h \
    Expression/Operators/not.h

FORMS += \
        mainwindow.ui
