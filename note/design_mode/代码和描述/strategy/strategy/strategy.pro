TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    strategyinterface.cpp \
    abstructstrategy.cpp \
    concretestrategy.cpp \
    halfstrtegy.cpp \
    buytowgetonefreestrategy.cpp

HEADERS += \
    strategyinterface.h \
    abstructstrategy.h \
    concretestrategy.h \
    halfstrtegy.h \
    buytowgetonefreestrategy.h
