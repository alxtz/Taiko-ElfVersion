#include <QBrush>
#include <QImage>
#include <QFileInfo>
#include <fstream>
#include <iostream>
#include "SongChoose.h"

using namespace std;

SongChoose::SongChoose()
{
    setSceneRect(0 , 0 , 800 , 600);

    ifstream lastSong("./GameData/GameSettings/lastSong.txt" , ios::in);

    if(!lastSong)
    {
        cout<<"打開失敗"<<endl;
    }

    lastSong >> lastSongName;

    string backgroundPath;
    backgroundPath = "./GameData/Oves/" + lastSongName + "/background.png";

    string songPath;
    songPath = "./GameData/Oves/" + lastSongName + "/song.mp3";

    qBackgroundPath = QString::fromStdString(backgroundPath);
    qMusicPath = QString::fromStdString(songPath);

    setBackground();
    setMusic();
}

void SongChoose::setBackground()
{
    setBackgroundBrush(QBrush(QImage(qBackgroundPath)));
}

void SongChoose::setMusic()
{
    backgroundMusicPlaylist = new QMediaPlaylist();
    backgroundMusicPlaylist->addMedia(QUrl::fromLocalFile(QFileInfo(qMusicPath).absoluteFilePath()));
    backgroundMusicPlaylist->setCurrentIndex(1);
    backgroundMusicPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    backgroundMusicPlayer = new QMediaPlayer();
    backgroundMusicPlayer->setPlaylist(backgroundMusicPlaylist);
    backgroundMusicPlayer->play();
}
