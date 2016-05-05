#include <QBrush>
#include <QImage>
#include <QFileInfo>
#include <iostream>
#include <fstream>
#include "MainMenu.h"
#include "../GameView.h"

extern GameView * gameView;

using namespace std;

MainMenu::MainMenu()
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

    taikoIcon = new TaikoIcon();
    addItem(taikoIcon);

    soloButton = new SoloButton();
    addItem(soloButton);

    //gameView->setSongMenu();
}

MainMenu::~MainMenu()
{
    clear();
    backgroundMusicPlayer->stop();
}

void MainMenu::setBackground()
{
    setBackgroundBrush(QBrush(QImage(qBackgroundPath)));
}

void MainMenu::setMusic()
{
    backgroundMusicPlaylist = new QMediaPlaylist();
    backgroundMusicPlaylist->addMedia(QUrl::fromLocalFile(QFileInfo(qMusicPath).absoluteFilePath()));
    backgroundMusicPlaylist->setCurrentIndex(1);
    backgroundMusicPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    backgroundMusicPlayer = new QMediaPlayer();
    backgroundMusicPlayer->setPlaylist(backgroundMusicPlaylist);
    backgroundMusicPlayer->play();
}
