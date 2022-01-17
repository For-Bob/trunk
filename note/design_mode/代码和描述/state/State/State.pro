TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    state.cpp \
    context.cpp \
    concretestatea.cpp \
    concretestateb.cpp

HEADERS += \
    state.h \
    context.h \
    concretestatea.h \
    concretestateb.h
