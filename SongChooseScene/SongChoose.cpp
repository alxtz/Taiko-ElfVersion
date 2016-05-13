#include <fstream>
#include <iostream>
#include <QBrush>
#include <QImage>
#include <QDebug>
#include <QPixmap>
#include <QFileInfo>
#include <QGraphicsScene>

#include "SongChoose.h"

using namespace std;

SongChoose::SongChoose()
{
    setSceneRect(0 , 0 , 800 , 600);

    backButton = new BackButton();
    addItem(backButton);

    selectPic = new QGraphicsPixmapItem();
    selectPic->setPixmap(QPixmap("./GameData/DefaultResources/images/selectSong.png"));
    addItem(selectPic);

    songFocusedIndex = -1;

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

    loadSongList();
}

SongChoose::~SongChoose()
{
    backgroundMusicPlayer->stop();
    clear();
}

void SongChoose::setBackground(string oveName)
{

    if(oveName!="default")
    {
        string backgroundPath;
        backgroundPath = "./GameData/Oves/" + oveName + "/background.png";

        qBackgroundPath = QString::fromStdString(backgroundPath);
    }

    setBackgroundBrush(QBrush(QImage(qBackgroundPath)));
}

void SongChoose::setMusic(string oveName)
{

    if(oveName!="default")
    {
        backgroundMusicPlayer->stop();
        string songPath;
        songPath = "./GameData/Oves/" + oveName + "/song.mp3";
        qMusicPath = QString::fromStdString(songPath);
        currentPlaying = oveName;
    }
    else
    {
        currentPlaying = lastSongName;
    }

    backgroundMusicPlaylist = new QMediaPlaylist();
    backgroundMusicPlaylist->addMedia(QUrl::fromLocalFile(QFileInfo(qMusicPath).absoluteFilePath()));
    backgroundMusicPlaylist->setCurrentIndex(1);
    backgroundMusicPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    backgroundMusicPlayer = new QMediaPlayer();
    backgroundMusicPlayer->setPlaylist(backgroundMusicPlaylist);
    backgroundMusicPlayer->play();
}

void SongChoose::buttonClicked(int index)
{
    if(songFocusedIndex == index)
    {
        //removeItem(songButtonList.at(songFocusedIndex)->childSongButton);
        //cout<<"移除"<<songFocusedIndex<<"號的child按鈕"<<endl;

        cout<<"點下了正在focus的按鈕，號碼為"<<index<<endl;
        songButtonList.at(index)->setUp();

        emit songButtonList.at(index)->destroyChild();

        songButtonList.at(songFocusedIndex)->isDown=false;

        songFocusedIndex = -1;


        for(int i= index+1; i< songButtonList.size(); i++)
        {
            songButtonList.at(i)->moveUp(1);
        }
    }
    else
    {
        if(songFocusedIndex!=-1)
        {
            songButtonList.at(songFocusedIndex)->setUp();

            //removeItem(songButtonList.at(songFocusedIndex)->childSongButton);
            //cout<<"移除"<<songFocusedIndex<<"號的child按鈕"<<endl;



            for(int i= songFocusedIndex+1; i< songButtonList.size(); i++)
            {
                songButtonList.at(i)->moveUp(1);
            }
        }

        songFocusedIndex = index;
        songButtonList.at(songFocusedIndex)->setDown();
        songButtonList.at(songFocusedIndex)->isDown=true;

        if(currentPlaying!=songButtonList.at(index)->oveName)
        {
            setMusic(songButtonList.at(index)->oveName);
            setBackground(songButtonList.at(index)->oveName);
        }

        for(int i= index+1; i< songButtonList.size(); i++)
        {
            songButtonList.at(i)->moveDown(1);
        }
    }
}

void SongChoose::loadSongList()
{
    ifstream inputSongList("./GameData/GameSettings/songList.txt" , ios::in);

    if(!inputSongList)
    {
        qDebug()<<"打開lastSong.txt失敗";
    }

    for(int i=0; i<=100; i++)
    {
        string foo;

        if(inputSongList>>foo)
        {
            cout<<"讀入了"<<foo<<endl;
            songList.push_back(foo);
        }
        else
        {
            cout<<"讀檔結尾"<<endl;
            break;
        }
    }
}

void SongChoose::loadSongButtons()
{

    for(int i=0; i<songList.size(); i++)
    {
        string songNamePath = "./GameData/Oves/" + songList.at(i) + "/name.txt";

        cout<<"path為"<<songNamePath<<endl;

        ifstream inputSongName(songNamePath , ios::in);

        string songName;
        string songOrigin;

        if(!inputSongName)
        {
            qDebug()<<"打開name.txt失敗";
        }
        inputSongName>>songName;

        getline(inputSongName , songOrigin);


        cout<<"取得一首歌名"<<songName<<endl;

        cout<<"取得一首歌的來源"<<songOrigin<<endl;

        QString qSongName= QString::fromStdString(songName);
        QString qSongOrigin = QString::fromStdString(songOrigin);


        SongButton * songButton = new SongButton(qSongName , qSongOrigin , songList.at(i));
        songButton->setPos(490 , 110 + 70*i);
        addItem(songButton);
        songButtonList.push_back(songButton);
        songButtonList.at(i)->index=i;
        cout<<"按鈕"<<songName<<"的index為"<<songButtonList.at(i)->index<<endl;

        connect( songButton , SIGNAL( clicked(int) ) , this , SLOT (buttonClicked(int)) );
    }

}
