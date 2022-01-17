TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    chess.cpp \
    whitechess.cpp \
    blackchess.cpp \
    chessfactory.cpp

HEADERS += \
    chess.h \
    whitechess.h \
    blackchess.h \
    chessfactory.h
