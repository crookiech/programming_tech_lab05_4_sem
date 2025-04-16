QT += core gui
QT += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ClassicTagGameWindow.cpp \
    Menu.cpp \
    MenuOK.cpp \
    RateYourMindPalWindow.cpp \
    ScreenSaver.cpp \
    ScreenSaverOK.cpp \
    TagGame.cpp \
    CreateTagGame.cpp \
    ILogger.cpp \
    CreateLogger.cpp \
    main.cpp \
    ScreenSaverTests.cpp \
    MenuTests.cpp

HEADERS += \
    ClassicTagGameWindow.h \
    Menu.h \
    MenuOK.h \
    RateYourMindPalWindow.h \
    ScreenSaver.h \
    ScreenSaverOK.h \
    TagGame.h \
    CreateTagGame.h \
    ILogger.h \
    CreateLogger.h

FORMS += \
    ClassicTagGameWindow.ui \
    Menu.ui \
    MenuOK.ui \
    RateYourMindPalWindow.ui \
    ScreenSaver.ui \
    ScreenSaverOK.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
