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
#include "../GameView.h"

extern TestTimer timer;
extern GameView * gameView;

using namespace std;

PlayEngine::PlayEngine(string oveName)
{
    //testMode = false;
    testMode = true;
    moveTimer = new QTimer();
    moveTimer->start(7);

    inputOve =  oveName;


    escMenu = new EscMenu();
    isEsc = false;

    cout<<"目前的譜面資料夾名稱是"<<inputOve<<endl;


    readSheetMusic();
    sheetMusicPlayer = new SheetMusicPlayer( & sheetMusic);
    connect(sheetMusicPlayer , SIGNAL(shootDongKa(int)) , this , SLOT(spawnDongKa(int)));
    connect(sheetMusicPlayer , SIGNAL(oveEnd()) , this , SLOT(endGame()));
    connect(sheetMusicPlayer , SIGNAL(disableEsc()) , this , SLOT(disableEsc()));

    BGMusic = new QMediaPlayer();
    string musicPath = "./GameData/Oves/" + inputOve + "/song.mp3";
    QString qMusicPath = QString::fromStdString(musicPath);
    BGMusic->setMedia(QUrl::fromLocalFile(QFileInfo(qMusicPath).absoluteFilePath()));

    escDisabled = false;
}

PlayEngine::~PlayEngine()
{
    BGMusic->stop();
    delete BGMusic;
}

void PlayEngine::keyPressEvent(QKeyEvent *event)
{
    if( event->key()==Qt::Key_F)
    {
        emit hitKey(0);
        QSound::play("./GameData/DefaultResources/sounds/dong.wav");
    }
    else if( event->key()==Qt::Key_K )
    {
        emit hitKey(1);
        QSound::play("./GameData/DefaultResources/sounds/ka.wav");
    }
    else if( event->key()==Qt::Key_Escape && escDisabled==false)
    {
        qDebug()<<"按下了esc";

        if(isEsc==false)
        {
            qDebug()<<"開啟escMenu";
            scene()->addItem(escMenu);
            moveTimerPause();
            BGMusic->pause();
            isEsc = true;
            sheetMusicPlayer->pause();
        }
        else
        {
            qDebug()<<"關閉escMenu";
            scene()->removeItem(escMenu);
            moveTimerResume();
            BGMusic->play();
            isEsc = false;
            sheetMusicPlayer->resume();
        }
    }
    //測試用功能,按t直接跳到結算畫面
    else if( event->key()==Qt::Key_T && testMode==true)
    {
        emit doResult();
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
            sheetMusic.noteAmount++;
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
    qDebug()<<"本歌曲的noteAmount為"<<sheetMusic.noteAmount;
}

void PlayEngine::playSheetMusic()
{
    sheetMusicPlayer->start();
    //cout<<"檢查sheet開始的時間";
    //timer.fromLastTime();
}

void PlayEngine::playMusic()
{
    BGMusic->play();
    //cout<<"檢查音樂開始的時間";
    //timer.fromLastTime();
}

void PlayEngine::spawnDongKa(int type)
{
    //cout<<"檢查呼叫playEngine的時間";
    //timer.fromLastTime();

    if (type==0)
    {
        Dong * dong = new Dong();
        scene()->addItem(dong);
        connect( moveTimer , SIGNAL(timeout()) , dong , SLOT(move()) );
        //cout<<"檢查出生的時間";
        //timer.fromLastTime();
    }
    else if (type==1)
    {
        Ka * ka = new Ka();
        scene()->addItem(ka);
        connect( moveTimer , SIGNAL(timeout()) , ka , SLOT(move()) );
        //cout<<"檢查出生的時間";
        //timer.fromLastTime();
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

void PlayEngine::moveTimerPause()
{
    moveTimer->stop();
}

void PlayEngine::moveTimerResume()
{
    moveTimer->start(7);
}

void PlayEngine::endGame()
{
    if(testMode==false)
    {
        qDebug()<<"遊戲結束";
        emit doResult();
    }
}

void PlayEngine::disableEsc()
{
    escDisabled = true;
}
