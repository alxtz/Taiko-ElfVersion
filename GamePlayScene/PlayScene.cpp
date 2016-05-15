#include <iostream>
#include <QPen>
#include <QBrush>
#include <QImage>
#include <QPixmap>
#include <QObject>
#include "PlayScene.h"
#include "../GameView.h"

using namespace std;

extern GameView * gameView;

PlayScene::PlayScene(string oveName)
{
    setSceneRect(0 , 0 , 800 , 600);
    playingOve = oveName;

    setBackgroundPicture();

    songTrack = new QGraphicsPixmapItem();
    songTrack->setPixmap(QPixmap("./GameData/DefaultResources/images/songTrack.png"));
    songTrack->setPos(0 , 295);
    addItem(songTrack);

    playEngine = new PlayEngine(playingOve);
    addItem(playEngine);
    playEngine->setFlag(QGraphicsItem::ItemIsFocusable);
    playEngine->setFocus();
    playEngine->grabKeyboard();

    hitPoint = new HitPoint();
    hitPoint->setPen(Qt::NoPen);
    addItem(hitPoint);

    drum = new Drum();
    addItem(drum);

    playScore = new PlayScore();
    addItem(playScore);

    combo = new Combo();
    addItem(combo);

    percentNow = new PercentNow();
    addItem(percentNow);

    connect(playEngine , SIGNAL(hitKey(int)) , hitPoint , SLOT (checkCollision(int)));
    connect(playEngine , SIGNAL(hitKey(int)) , drum , SLOT(setSmall(int)) );
    connect(hitPoint , SIGNAL(setGrade(int)) , playEngine , SLOT(spawnGrade(int)));
    connect(hitPoint , SIGNAL(setAddScore(int)) , playScore , SLOT(addScore(int)));
    connect(hitPoint , SIGNAL(setAddCombo()) , combo , SLOT(addCombo()));
    connect(hitPoint , SIGNAL(setEndCombo()) , combo , SLOT(endCombo()));
    connect(hitPoint , SIGNAL(setHitted(bool)) , percentNow , SLOT(hitted(bool)) );
    connect(playEngine , SIGNAL(doResult()) , this , SLOT(startResult()) );
}

PlayScene::~PlayScene()
{
    delete playEngine;
}

void PlayScene::setBackgroundPicture()
{
    string backgroundPath;
    backgroundPath = "./GameData/Oves/" + playingOve + "/background.png";

    QString qBackgroundPath;
    qBackgroundPath = QString::fromStdString(backgroundPath);

    setBackgroundBrush(QBrush(QImage(qBackgroundPath)));
}

void PlayScene::startResult()
{
    qDebug()<<"開始計算分數";

    gamePlayResult = new GamePlayResult();
    gamePlayResult->oveName = playingOve;
    gamePlayResult->score = playScore->score;
    gamePlayResult->correctPercent = percentNow->percent;
    gamePlayResult->highestCombo = combo->highestCombo;
    gamePlayResult->greatAmount = hitPoint->greatAmount;
    gamePlayResult->goodAmount = hitPoint->goodAmount;
    gamePlayResult->badAmount = hitPoint->badAmount;

    cout<<"遊戲譜面名稱"<<gamePlayResult->oveName<<endl;
    cout<<"分數"<<gamePlayResult->score<<endl;
    cout<<"正確率"<<gamePlayResult->correctPercent<<endl;
    cout<<"最高連擊數"<<gamePlayResult->highestCombo<<endl;
    cout<<"良個數"<<gamePlayResult->greatAmount<<endl;
    cout<<"可個數"<<gamePlayResult->goodAmount<<endl;
    cout<<"不可個數"<<gamePlayResult->badAmount<<endl;

    int correctAmount;
    double correctPercent;

    correctAmount = gamePlayResult->greatAmount + gamePlayResult->goodAmount;
    correctPercent = (double)correctAmount / playEngine->sheetMusic.noteAmount;

    cout<<"true正確率為"<<correctPercent<<endl;

    if(gamePlayResult->greatAmount == playEngine->sheetMusic.noteAmount)//要是全良
     {
        gamePlayResult->rank = 4;
    }
    else if( correctPercent > 0.95 )
    {
        gamePlayResult->rank = 3;
    }
    else if( correctPercent > 0.9 )
    {
        gamePlayResult->rank = 2;
    }
    else if( correctPercent > 0.85 )
    {
        gamePlayResult->rank = 1;
    }
    else
    {
        gamePlayResult->rank = 0;
    }

    cout<<"你的rank為"<<gamePlayResult->rank<<endl;

    gameView->setResultScene( * gamePlayResult);
}
