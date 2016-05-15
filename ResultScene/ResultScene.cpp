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
    scoreText->setPos(250 , 160);
    scoreText->setDefaultTextColor(QColor(107 , 107 , 107));
    addItem(scoreText);
}
