TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    compositemenu.cpp \
    leafmenu.cpp \
    menuitem.cpp \
    waiter.cpp

HEADERS += \
    compositemenu.h \
    leafmenu.h \
    menuitem.h \
    waiter.h
