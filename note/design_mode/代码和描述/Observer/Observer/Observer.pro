TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    subject.cpp \
    observer.cpp \
    concreteobservera.cpp \
    concreteobserverb.cpp

HEADERS += \
    subject.h \
    observer.h \
    concreteobservera.h \
    concreteobserverb.h
