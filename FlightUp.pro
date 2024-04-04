QT       += core gui printsupport serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    referencescreen.cpp \
    resultscreen.cpp \
    settingsscreen.cpp \
    warningscreen.cpp \
    welcomescreen.cpp

HEADERS += \
    mainwindow.h \
    qcustomplot.h \
    referencescreen.h \
    resultscreen.h \
    settingsscreen.h \
    warningscreen.h \
    welcomescreen.h

FORMS += \
    mainwindow.ui \
    referencescreen.ui \
    resultscreen.ui \
    settingsscreen.ui \
    warningscreen.ui \
    welcomescreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    flightUp_logo.jpg

RESOURCES += \
    resource.qrc
