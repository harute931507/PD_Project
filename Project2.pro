#-------------------------------------------------
#
# Project created by QtCreator 2017-05-18T11:24:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    minion.cpp \
    show_hp.cpp \
    player.cpp \
    show_mana.cpp \
    game.cpp \
    tower.cpp \
    minion_image.cpp \
    attack_area.cpp \
    enemy.cpp \
    ai.cpp \
    tower_ai.cpp \
    deck.cpp

HEADERS  += mainwindow.h \
    minion.h \
    show_hp.h \
    game.h \
    player.h \
    show_mana.h \
    tower.h \
    minion_image.h \
    attack_area.h \
    enemy.h \
    ai.h \
    tower_ai.h \
    deck.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
