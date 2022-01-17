TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    prototype.cpp \
    prototypemale.cpp \
    prototypefemale.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    prototype.h \
    prototypemale.h \
    prototypefemale.h
