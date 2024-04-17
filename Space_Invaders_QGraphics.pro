QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Barrier.cpp \
    Enemy.cpp \
    Game.cpp \
    Health.cpp \
    Laser.cpp \
    LaserEnemy.cpp \
    Player.cpp \
    Score.cpp \
    endscreen.cpp \
    highscores.cpp \
    main.cpp \
    instruct.cpp \
    menu.cpp \
    settings.cpp

HEADERS += \
    Barrier.h \
    Enemy.h \
    Game.h \
    Health.h \
    Laser.h \
    LaserEnemy.h \
    Player.h \
    Score.h \
    endscreen.h \
    highscores.h \
    instruct.h \
    menu.h \
    settings.h

FORMS += \
    Game.ui \
    endscreen.ui \
    highscores.ui \
    instruct.ui \
    menu.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
