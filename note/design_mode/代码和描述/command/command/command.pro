TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    command.cpp \
    concretecommand.cpp \
    receiver.cpp \
    invoker.cpp

HEADERS += \
    command.h \
    concretecommand.h \
    receiver.h \
    invoker.h
