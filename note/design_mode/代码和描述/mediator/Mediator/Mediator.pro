TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    mediator.cpp \
    colleague.cpp \
    concretemediator.cpp \
    concretecolleaguea.cpp \
    concretecolleagueb.cpp

HEADERS += \
    mediator.h \
    colleague.h \
    concretemediator.h \
    concretecolleaguea.h \
    concretecolleagueb.h
