#-------------------------------------------------
#
# Project created by QtCreator 2016-11-29T13:15:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bomberman
TEMPLATE = app


SOURCES += main.cpp\
        Game.cpp \
    Map.cpp \
    Player.cpp \
    Block.cpp \
    Bomb.cpp \
    Enemy.cpp \
    Wave.cpp

HEADERS  += Game.h \
    Map.h \
    Player.h \
    Block.h \
    Bomb.h \
    Enemy.h \
    Wave.h

FORMS    +=

RESOURCES += \
    res.qrc
