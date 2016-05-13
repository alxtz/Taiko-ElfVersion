#include <iostream>
#include <QDebug>
#include <QTimer>
#include "SheetMusicPlayer.h"
#include "../TestTimer.h"

using namespace std;

extern TestTimer timer;

SheetMusicPlayer::SheetMusicPlayer(SheetMusic * inputSheet) : sheetMusic(*inputSheet)
{
    singleTimer = new QTimer();
    singleTimer->setSingleShot(true);
    singleTimer->setTimerType(Qt::PreciseTimer);
    connect(singleTimer , SIGNAL(timeout()) , this , SLOT(spawn()));
    currentNote = 0;
}

void SheetMusicPlayer::start()
{
    cout<<"sheet播放器開始的時間為";
    timer.fromLastTime();
    count();
}

void SheetMusicPlayer::count()
{
    if(sheetMusic.notes[currentNote].type==-1)
        {
            qDebug()<<"譜面結束";
            return;
        }
    int delayTime;
    if(currentNote==0)
    {
        delayTime=sheetMusic.notes[currentNote].spawnSec;
    }
    else
    {
        delayTime=sheetMusic.notes[currentNote].spawnSec - sheetMusic.notes[currentNote-1].spawnSec;
    }
    cout<<"呼叫count";
    timer.fromLastTime();
    cout<<"暫停"<<delayTime<<endl;
    singleTimer->start(delayTime);
}

void SheetMusicPlayer::spawn()
{
    cout<<"spawn開始";
    timer.fromLastTime();
    if(sheetMusic.notes[currentNote].type==0)
    {
        //qDebug()<<"產生紅咚";
        //qDebug()<<"第"<<currentNote<<"個節拍";
        cout<<"輸出信號";
        timer.fromLastTime();
        emit shootDongKa(0);
    }
    else  if(sheetMusic.notes[currentNote].type==1)
    {
        //qDebug()<<"產生藍咚";
        //qDebug()<<"第"<<currentNote<<"個節拍";
        cout<<"輸出信號";
        timer.fromLastTime();
        emit shootDongKa(1);
    }
    currentNote++;
    cout<<"呼叫spawn";
    timer.fromLastTime();
    count();
}
