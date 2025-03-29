QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ClassicTagGameWindow.cpp \
    Menu.cpp \
    RateYourMindPalWindow.cpp \
    ScreenSaver.cpp \
    TagGame.cpp \
    CreateTagGame.cpp \
    ILogger.cpp \
    CreateLogger.cpp \
    main.cpp

HEADERS += \
    ClassicTagGameWindow.h \
    Menu.h \
    RateYourMindPalWindow.h \
    ScreenSaver.h \
    TagGame.h \
    CreateTagGame.h \
    ILogger.h \
    CreateLogger.h

FORMS += \
    ClassicTagGameWindow.ui \
    Menu.ui \
    RateYourMindPalWindow.ui \
    ScreenSaver.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
