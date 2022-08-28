QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

INCLUDEPATH += D:/c++/chenjianglong/qt/WpdPack/Include
LIBS +="-LD:/c++/chenjianglong/qt/WpdPack/Lib/x64" -lws2_32 -lwpcap

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    capThread.cpp \
    filterdialog.cpp \
    main.cpp \
    xiutan.cpp

HEADERS += \
    about.h \
    capThread.h \
    datastruct.h \
    filterdialog.h \
    xiutan.h

FORMS += \
    about.ui \
    filterdialog.ui \
    xiutan.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



LIBS += -liphlpapi

RESOURCES +=
