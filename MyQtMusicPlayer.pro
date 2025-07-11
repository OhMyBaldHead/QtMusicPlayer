QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimediawidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LyricWidget.cpp \
    Music.cpp \
    MusicList.cpp \
    MusicListWidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    LyricWidget.h \
    Music.h \
    MusicList.h \
    MusicListWidget.h \
    mainwindow.h

FORMS += \
    LyricWidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagefile.qrc
