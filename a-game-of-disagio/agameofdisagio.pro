QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    src/main.cpp \
    src/schemahandler.cpp \
    src/ui/button.cpp \
    src/ui/centrallayout.cpp \
    src/ui/mainwindow.cpp

HEADERS += \
    src/exceptions.h \
    src/schemahandler.h \
    src/ui/button.h \
    src/ui/centrallayout.h \
    src/ui/mainwindow.h

FORMS += \
    src/ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
