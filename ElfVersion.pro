#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T07:40:44
#
#-------------------------------------------------

QT       += core gui
QT       +=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ElfVersion
TEMPLATE = app


SOURCES += main.cpp \
    GameView.cpp \
    StartMenuScene/MainMenu.cpp \
    SongChooseScene/SongChoose.cpp \
    StartMenuScene/TaikoIcon.cpp \
    StartMenuScene/SoloButton.cpp \
    GamePlayScene/PlayScene.cpp \
    GamePlayScene/PlayEngine.cpp \
    GamePlayScene/Note.cpp \
    GamePlayScene/SheetMusic.cpp \
    GamePlayScene/SheetMusicPlayer.cpp \
    GamePlayScene/Dong.cpp \
    GamePlayScene/Ka.cpp \
    GamePlayScene/HitPoint.cpp


HEADERS  += \
    GameView.h \
    StartMenuScene/MainMenu.h \
    StartMenuScene/TaikoIcon.h \
    StartMenuScene/SoloButton.h \
    SongChooseScene/SongChoose.h \
    GamePlayScene/PlayScene.h \
    GamePlayScene/PlayEngine.h \
    GamePlayScene/Note.h \
    GamePlayScene/SheetMusic.h \
    GamePlayScene/SheetMusicPlayer.h \
    GamePlayScene/Dong.h \
    GamePlayScene/Ka.h \
    GamePlayScene/HitPoint.h

