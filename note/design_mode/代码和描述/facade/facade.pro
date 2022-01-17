TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    Facade.cpp

HEADERS += \
    preprocessing.h \
    compilation.h \
    assemble.h \
    linking.h \
    Facade.h
