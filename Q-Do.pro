QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    src/Task.cpp \
    src/main.cpp \
    src/MainWindow.cpp

HEADERS += \
    src/include/Task.h \
    src/include/MainWindow.h

FORMS += \
    src/forms/Task.ui \
    src/forms/MainWindow.ui
