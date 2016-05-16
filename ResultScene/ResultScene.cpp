#include <QFont>
#include <QColor>
#include <iostream>
#include <fstream>
#include <QPixmap>
#include "ResultScene.h"

using namespace std;

ResultScene::ResultScene(GamePlayResult & gamePlayResult) : usingResult(gamePlayResult)
{
    setSceneRect(0 , 0 , 800 , 600);

    resultBoard = new QGraphicsPixmapItem();
    resultBoard->setPixmap(QPixmap("./GameData/DefaultResources/images/result.png"));
    //resultBoard->setZValue(10);
    addItem(resultBoard);
    //因為reference只能被指派一次，所以要用member initializer來初始化

    backButton = new ResultBackButton();
    addItem(backButton);
}

void ResultScene::setBackground()
{
    cout<<"resultScene所用的譜面是"<<usingResult.oveName<<endl;
    string backgroundPath;
    backgroundPath = "./GameData/Oves/" + usingResult.oveName + "/background.png";

    QString qBackgroundPath;
    qBackgroundPath = QString::fromStdString(backgroundPath);

    setBackgroundBrush(QBrush(QImage(qBackgroundPath)));
}

void ResultScene::setResult()
{
    string songNamePath = "./GameData/Oves/" + usingResult.oveName + "/name.txt";
    ifstream inputSongName(songNamePath , ios::in);

    string songName;
    string songOrigin;

    inputSongName>>songName;

    getline(inputSongName , songOrigin);

    QString qSongName= QString::fromStdString(songName);
    QString qSongOrigin = QString::fromStdString(songOrigin);
    QString foo = qSongName +" - " + qSongOrigin;

    oveText = new QGraphicsTextItem(foo);
    QFont oveTextFont("Helvetica" , 12);
    oveTextFont.setWeight(45);
    oveText->setFont(oveTextFont);
    oveText->setPos(150 , 135);
    oveText->setDefaultTextColor(QColor(107 , 107 , 107));
    addItem(oveText);

    scoreText = new QGraphicsTextItem();
    scoreText->setPlainText(QString::number(usingResult.score));
    QFont scoreTextFont("SansSerif" , 70);
    scoreTextFont.setWeight(50);
    scoreText->setFont(scoreTextFont);
    scoreText->setPos(250 , 145);
    scoreText->setDefaultTextColor(QColor(107 , 107 , 107));
    addItem(scoreText);

    percentText = new QGraphicsTextItem();
    QString qPercentText = "正確率  : " + QString::number(usingResult.correctPercent) + "%";
    percentText->setPlainText(qPercentText);
    QFont percentTextFont("SansSerif" , 12);
    percentTextFont.setWeight(45);
    percentText->setFont(percentTextFont);
    percentText->setPos(257 , 265);
    percentText->setDefaultTextColor(QColor(107 , 107 , 107));
    addItem(percentText);

    comboText = new QGraphicsTextItem();
    QString qComboText = "最高連打  : " + QString::number(usingResult.highestCombo);
    comboText->setPlainText(qComboText);
    QFont comboTextFont("SansSerif" , 12);
    comboTextFont.setWeight(45);
    comboText->setFont(comboTextFont);
    comboText->setPos(257 , 285);
    comboText->setDefaultTextColor(QColor(107 , 107 , 107));
    addItem(comboText);

    greatPic = new QGraphicsPixmapItem();
    greatPic->setPixmap(QPixmap("./GameData/DefaultResources/images/greatAmount.png"));
    greatPic->setPos(126 , 310);
    addItem(greatPic);

    goodPic = new QGraphicsPixmapItem();
    goodPic->setPixmap(QPixmap("./GameData/DefaultResources/images/goodAmount.png"));
    goodPic->setPos(126 , 370);
    addItem(goodPic);

    badPic = new QGraphicsPixmapItem();
    badPic->setPixmap(QPixmap("./GameData/DefaultResources/images/badAmount.png"));
    badPic->setPos(126 , 430);
    addItem(badPic);

    greatAmount = new QGraphicsTextItem();
    greatAmount->setPlainText(QString::number(usingResult.greatAmount));
    QFont greatAmountFont("SansSerif" , 27);
    greatAmountFont.setWeight(70);
    greatAmount->setFont(greatAmountFont);
    greatAmount->setPos(202 , 307);
    greatAmount->setDefaultTextColor(QColor(107 , 107 , 107));
    addItem(greatAmount);

    goodAmount = new QGraphicsTextItem();
    goodAmount->setPlainText(QString::number(usingResult.goodAmount));
    QFont goodAmountFont("SansSerif" , 27);
    goodAmountFont.setWeight(70);
    goodAmount->setFont(goodAmountFont);
    goodAmount->setPos(202 , 367);
    goodAmount->setDefaultTextColor(QColor(107 , 107 , 107));
    addItem(goodAmount);

    badAmount = new QGraphicsTextItem();
    badAmount->setPlainText(QString::number(usingResult.badAmount));
    QFont badAmountFont("SansSerif" , 27);
    badAmountFont.setWeight(70);
    badAmount->setFont(badAmountFont);
    badAmount->setPos(202 , 427);
    badAmount->setDefaultTextColor(QColor(107 , 107 , 107));
    addItem(badAmount);

    rank = new QGraphicsTextItem();
    QString rankText;
    QFont rankTextFont("Helvetica" , 120);
    rankTextFont.setWeight(75);

    //usingResult.rank = 3;

    if(usingResult.rank==4)
    {
        rankText = "SS";
        rank->setDefaultTextColor(QColor(240 , 46 , 81));
        rank->setPos(380 , 290);
    }
    else if(usingResult.rank==3)
    {
        rankText = "S";
        rank->setDefaultTextColor(QColor(255 , 255 , 0));
        rank->setPos(390 , 290);
    }
    else if(usingResult.rank==2)
    {
        rankText = "A";
        rank->setDefaultTextColor(QColor(87 , 227 , 0));
        rank->setPos(390 , 290);
    }
    else if(usingResult.rank==1)
    {
        rankText = "B";
        rank->setDefaultTextColor(QColor(82 , 25 , 189));
        rank->setPos(390 , 290);
    }
    else if(usingResult.rank==0)
    {
        rankText = "F";
        rank->setDefaultTextColor(QColor(94 , 94 , 94));
        rank->setPos(390 , 290);
    }

    rank->setPlainText(rankText);
    rank->setFont(rankTextFont);
    addItem(rank);
}
