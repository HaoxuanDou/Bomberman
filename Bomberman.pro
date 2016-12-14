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
    Wave.cpp \
    Health.cpp \
    Level.cpp \
    Score.cpp \
    Starttext.cpp \
    Endtext.cpp

HEADERS  += Game.h \
    Map.h \
    Player.h \
    Block.h \
    Bomb.h \
    Enemy.h \
    Wave.h \
    Health.h \
    Level.h \
    Score.h \
    Starttext.h \
    Endtext.h

FORMS    +=

RESOURCES += \
    res.qrc
