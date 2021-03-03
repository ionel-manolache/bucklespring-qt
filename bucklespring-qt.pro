QT += core
QT += gui
QT += multimedia
QT += widgets

TARGET = bucklespring-qt
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    src/main.cpp \
    src/application.cpp \
    src/settings.cpp \

HEADERS += \
    src/application.h \
    src/settings.h \

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/res.qrc
