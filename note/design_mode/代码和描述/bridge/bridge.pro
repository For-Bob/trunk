TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    whitecolorpaint.cpp \
    redcolorpaint.cpp \
    baseshape.cpp \
    basecolor.cpp \
    rectangleshape.cpp \
    circleshape.cpp

HEADERS += \
    whitecolorpaint.h \
    redcolorpaint.h \
    baseshape.h \
    basecolor.h \
    rectangleshape.h \
    circleshape.h
