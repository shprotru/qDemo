QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qDemo
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS += mainwindow.ui

#OTHER_FILES += \
#    resources/something.png

RESOURCES += \
    resources.qrc
