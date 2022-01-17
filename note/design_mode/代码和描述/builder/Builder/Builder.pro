TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    director.cpp \
    builder.cpp \
    concertebuilder.cpp \
    product.cpp

HEADERS += \
    director.h \
    builder.h \
    concertebuilder.h \
    product.h
