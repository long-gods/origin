QT       += core gui network axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

LIBS +=-lws2_32

CONFIG += c++11

INCLUDEPATH += D:/c++/chenjianglong/qt/WpdPack/Include
LIBS +="-LD:/c++/chenjianglong/qt/WpdPack/Lib/x64" -lws2_32 -lwpcap -lPacket


DEFINES += HAVE_REMOTE
DEFINES += WPCAP

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    HttpOp.cpp \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    test1.cpp \
    webtest.cpp

HEADERS += \
    HttpOp.h \
    form.h \
    mainwindow.h \
    test1.h \
    webtest.h

FORMS += \
    form.ui \
    mainwindow.ui \
    webtest.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    HttpOp.py \
    Testweb.qml \
    TestwebForm.ui.qml
