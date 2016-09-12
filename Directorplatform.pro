#-------------------------------------------------
#
# Project created by QtCreator 2016-09-09T14:30:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Directorplatform
TEMPLATE = app

TRANSLATIONS +=director_zh.ts \
               director_en.ts

SOURCES += main.cpp\
    QVideoWidget.cpp \
    MainWindow.cpp \
    QCtrlWindow.cpp \
    QLiveWidget.cpp \
    QDirWidget.cpp \
    QButton.cpp

HEADERS  += \
    PlatformConfig.h \
    QVideoWidget.h \
    MainWindow.h \
    QCtrlWindow.h \
    QLiveWidget.h \
    QDirWidget.h \
    QButton.h

RESOURCES += \
    src.qrc

OTHER_FILES +=
