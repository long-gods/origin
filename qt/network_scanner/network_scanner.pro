QT       +=network core gui

greaterThan(QT_MAJOR_VERSION, 4): QT +=network widgets

CONFIG += c++11 axcontainer

INCLUDEPATH += D:/c++/chenjianglong/qt/WpdPack/Include
LIBS +="-LD:/c++/chenjianglong/qt/WpdPack/Lib/x64" -lws2_32 -lwpcap


DEFINES += HAVE_REMOTE
DEFINES += WPCAP


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    baogao.cpp \
    capThread.cpp \
    ddos.cpp \
    dialog.cpp \
    dos.cpp \
    dos_attck.cpp \
    filterdialog.cpp \
    hostscan.cpp \
    hostscanner.cpp \
    httpbaoli.cpp \
    main.cpp \
    mainwindow.cpp \
    mimascan.cpp \
    mimascanner.cpp \
    portscan.cpp \
    portscanner.cpp \
    xiutan.cpp \
    xiutanscanner.cpp

HEADERS += \
    about.h \
    baogao.h \
    capThread.h \
    datastruct.h \
    ddos.h \
    dialog.h \
    dos.h \
    dos_attck.h \
    filterdialog.h \
    hostscan.h \
    hostscanner.h \
    httpbaoli.h \
    mainwindow.h \
    mimascan.h \
    mimascanner.h \
    portscan.h \
    portscanner.h \
    xiutan.h \
    xiutanscanner.h

FORMS += \
    about.ui \
    baogao.ui \
    dialog.ui \
    dos_attck.ui \
    filterdialog.ui \
    hostscan.ui \
    mainwindow.ui \
    mimascanner.ui \
    portscan.ui \
    xiutan.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    neosniffer.exe \
    network_scanner.pro.user



