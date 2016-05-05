#include <QDebug>
#include <QFileInfo>
#include <iostream>
#include <fstream>
#include <QGraphicsScene>
#include "PlayEngine.h"
#include "Dong.h"
#include "Ka.h"

using namespace std;

PlayEngine::PlayEngine(string oveName)
{
    moveTimer = new QTimer();
    moveTimer->start(7);

    inputOve =  oveName;

    cout<<"目前的譜面資料夾名稱是"<<inputOve<<endl;

    playMusic();
    readSheetMusic();
    sheetMusicPlayer = new SheetMusicPlayer( & sheetMusic);
    connect(sheetMusicPlayer , SIGNAL(shootDongKa(int)) , this , SLOT(spawnDongKa(int)));
    playSheetMusic();

}

void PlayEngine::readSheetMusic()
{
    string ovePath = "./GameData/Oves/" + inputOve + "/ove.txt";

    cout<<"目前讀的譜面路徑為"<<ovePath<<endl;

    ifstream inputOve(ovePath , ios::in );

    if(!inputOve)
    {
        qDebug()<<"打開失敗~";
    }

    int BPM;

    inputOve>>BPM;

    float speedFactor = (float) 60 / (BPM*2);//每個八分音符的時間長度

    qDebug()<<"這首歌的BPM為"<<BPM;

    for(int i=0; i<=999; i++)
    {
        float foo;
        if(inputOve>>foo)
        {
            qDebug()<<"第"<<i<<"個拍子數是"<<foo;
            //sheetMusic.notes[i].spawnSec = foo * speedFactor * 1000 + 10370;
            sheetMusic.notes[i].spawnSec = foo * speedFactor * 1000 + 10375;
            //10550後面會有一點問題，之後在改譜面
        }
        else
        {
            qDebug()<<"ove結束";
            break;
        }
        qDebug()<<"第"<<i<<"個note的出生時間是"<< sheetMusic.notes[i].spawnSec;
        inputOve>>foo;
        sheetMusic.notes[i].type = foo;
        qDebug()<<"第"<<i<<"個note的類型是"<< sheetMusic.notes[i].type;
    }

}

void PlayEngine::playSheetMusic()
{
    sheetMusicPlayer->start();
}

void PlayEngine::playMusic()
{
    BGMusic = new QMediaPlayer();
    string musicPath = "./GameData/Oves/" + inputOve + "/song.mp3";
    QString qMusicPath = QString::fromStdString(musicPath);

    BGMusic->setMedia(QUrl::fromLocalFile(QFileInfo(qMusicPath).absoluteFilePath()));
    BGMusic->play();
}

void PlayEngine::spawnDongKa(int type)
{
    if (type==0)
    {
        Dong * dong = new Dong();
        scene()->addItem(dong);
        connect( moveTimer , SIGNAL(timeout()) , dong , SLOT(move()) );

    }
    else if (type==1)
    {
        Ka * ka = new Ka();
        scene()->addItem(ka);
        connect( moveTimer , SIGNAL(timeout()) , ka , SLOT(move()) );
    }
}
