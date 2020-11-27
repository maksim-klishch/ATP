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
    CNF/cnf.cpp \
    CNF/resolution.cpp \
    Expression/Operators/and.cpp \
    Expression/Operators/not.cpp \
    Expression/Operators/or.cpp \
    Expression/atom.cpp \
    Expression/binaryoperator.cpp \
    Expression/expression.cpp \
    Expression/term.cpp \
    Expression/unaryoperator.cpp \
    Expression/variable.cpp \
    Interpreter/register.cpp \
    Interpreter/interpreter.cpp \
    Expression/Operators/implication.cpp \
    Expression/operator.cpp

HEADERS += \
        mainwindow.h \
    CNF/cnf.h \
    CNF/resolution.h \
    Expression/Operators/and.h \
    Expression/Operators/not.h \
    Expression/Operators/or.h \
    Expression/atom.h \
    Expression/binaryoperator.h \
    Expression/expression.h \
    Expression/term.h \
    Expression/unaryoperator.h \
    Expression/variable.h \
    Interpreter/register.h \
    Interpreter/interpreter.h \
    Expression/Operators/implication.h \
    Expression/operator.h

FORMS += \
        mainwindow.ui

# Share all project output files by directories
MOC_DIR = moc
RCC_DIR = rcc
UI_DIR = ui
unix:OBJECTS_DIR = unix
win32:OBJECTS_DIR = win32
macx:OBJECTS_DIR = mac

CONFIG(release, debug|release) {
    win32:QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt $$OUT_PWD/release
}
