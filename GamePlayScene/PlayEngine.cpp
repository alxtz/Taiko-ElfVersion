#include <QDebug>
#include <QSound>
#include <QFileInfo>
#include <iostream>
#include <fstream>
#include <QGraphicsScene>
#include "PlayEngine.h"
#include "Dong.h"
#include "Ka.h"
#include "IconBad.h"
#include "IconGood.h"
#include "IconGreat.h"
#include "../TestTimer.h"

extern TestTimer timer;

using namespace std;

PlayEngine::PlayEngine(string oveName)
{
    moveTimer = new QTimer();
    moveTimer->start(7);

    inputOve =  oveName;

    cout<<"目前的譜面資料夾名稱是"<<inputOve<<endl;


    readSheetMusic();
    sheetMusicPlayer = new SheetMusicPlayer( & sheetMusic);
    connect(sheetMusicPlayer , SIGNAL(shootDongKa(int)) , this , SLOT(spawnDongKa(int)));

    BGMusic = new QMediaPlayer();
    string musicPath = "./GameData/Oves/" + inputOve + "/song.mp3";
    QString qMusicPath = QString::fromStdString(musicPath);
    BGMusic->setMedia(QUrl::fromLocalFile(QFileInfo(qMusicPath).absoluteFilePath()));
}

void PlayEngine::keyPressEvent(QKeyEvent *event)
{
    if( event->key()==Qt::Key_F)
    {
        //qDebug()<<"you pressed F !";
        emit hitKey(0);
        //playView->drum->setSmall();
        QSound::play("./GameData/DefaultResources/sounds/dong.wav");
    }
    else if( event->key()==Qt::Key_K )
    {
        //qDebug()<<"you pressed K !";
        emit hitKey(1);
        //playView->drum->setSmall();
        QSound::play("./GameData/DefaultResources/sounds/ka.wav");
    }
    else if( event->key()==Qt::Key_Escape )
    {
        qDebug()<<"按下了esc";
    }
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

    int delayAdjust;

    inputOve>>delayAdjust;

    //qDebug()<<"這首歌的延遲調整是"<<delayAdjust;

    float speedFactor = (float) 60 / (BPM*2);//每個八分音符的時間長度

    //qDebug()<<"這首歌的BPM為"<<BPM;

    for(int i=0; i<=999; i++)
    {
        float foo;
        if(inputOve>>foo)
        {
            //qDebug()<<"第"<<i<<"個拍子數是"<<foo;
            //sheetMusic.notes[i].spawnSec = foo * speedFactor * 1000 + 10370;
            sheetMusic.notes[i].spawnSec = foo * speedFactor * 1000 + delayAdjust;
            //10550後面會有一點問題，之後在改譜面
        }
        else
        {
            //qDebug()<<"ove結束";
            break;
        }
        //qDebug()<<"第"<<i<<"個note的出生時間是"<< sheetMusic.notes[i].spawnSec;
        inputOve>>foo;
        sheetMusic.notes[i].type = foo;
        //qDebug()<<"第"<<i<<"個note的類型是"<< sheetMusic.notes[i].type;
    }

}

void PlayEngine::playSheetMusic()
{
    sheetMusicPlayer->start();
    cout<<"檢查sheet開始的時間";
    timer.checkTime();
}

void PlayEngine::playMusic()
{
    BGMusic->play();
    cout<<"檢查音樂開始的時間";
    timer.checkTime();
}

void PlayEngine::spawnDongKa(int type)
{
    if (type==0)
    {
        Dong * dong = new Dong();
        scene()->addItem(dong);
        connect( moveTimer , SIGNAL(timeout()) , dong , SLOT(move()) );
        cout<<"檢查出生的時間";
        timer.checkTime();
    }
    else if (type==1)
    {
        Ka * ka = new Ka();
        scene()->addItem(ka);
        connect( moveTimer , SIGNAL(timeout()) , ka , SLOT(move()) );
        cout<<"檢查出生的時間";
        timer.checkTime();
    }
}

void PlayEngine::spawnGrade(int grade)
{
    if(grade==0)
    {
        //qDebug()<<"spawn不可";
        IconBad * bad = new IconBad();
        scene()->addItem(bad);
    }
    else if(grade==1)
    {
        //qDebug()<<"spawn可";
        IconGood * good = new IconGood();
        scene()->addItem(good);
    }
    else if(grade==2)
    {
        //qDebug()<<"spawn良";
        IconGreat * great = new IconGreat();
        scene()->addItem(great);
    }
}
