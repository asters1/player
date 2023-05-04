CONFIG -= app_bundle
QT       += core gui network svg
CODECFORSRC = UTF-8
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11 link_pkgconfig
PKGCONFIG += mpv

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mpv/mpvwidget.cpp \
    widgets/console.cpp \
    widgets/custowidget.cpp \
    widgets/seekbar.cpp

HEADERS += \
    mainwindow.h \
    mpv/mpvwidget.h \
    mpv/qthelper.hpp \
    widgets/console.h \
    widgets/custowidget.h \
    widgets/seekbar.h

FORMS += \
    mainwindow.ui \
    widgets/console.ui \
    widgets/seekbar.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
