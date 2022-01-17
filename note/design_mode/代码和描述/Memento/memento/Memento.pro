TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    originator.cpp \
    caretaker.cpp \
    memento.cpp

HEADERS += \
    originator.h \
    caretaker.h \
    memento.h
