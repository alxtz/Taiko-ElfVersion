#include <QFont>
#include <QColor>
#include <QPixmap>
#include <fstream>
#include <iostream>
#include "HighestScoreBox.h"

using namespace std;

HighestScoreBox::HighestScoreBox(string oveName)
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/highScoreBox.png"));

    string path = "./GameData/Oves/" + oveName + "/score.txt";

    ifstream inputScore(path , ios::in );

    int highscore;
    int highRank;

    inputScore>>highscore;
    inputScore>>highRank;

    //highestRank = new QGraphicsTextItem(QString::fromStdString(highRank) , this);
    //highestScore = new QGraphicsTextItem(QString::number(highscore) , this);

    highestRank = new QGraphicsTextItem("", this);
    QString highestRankText;
    QFont highestRankTextFont("Helvetica" , 30);
    highestRankTextFont.setWeight(75);
    if(highRank==4)
    {
        highestRankText = "SS";
        highestRank->setDefaultTextColor(QColor(240 , 46 , 81));
        highestRank->setPos(0 , 0);
    }
    else if(highRank==3)
    {
        highestRankText = "S";
        highestRank->setDefaultTextColor(QColor(255 , 255 , 0));
        highestRank->setPos(11 , 0);
    }
    else if(highRank==2)
    {
        highestRankText = "A";
        highestRank->setDefaultTextColor(QColor(87 , 227 , 0));
        highestRank->setPos(11 , 0);
    }
    else if(highRank==1)
    {
        highestRankText = "B";
        highestRank->setDefaultTextColor(QColor(82 , 25 , 189));
        highestRank->setPos(11 , 0);
    }
    else if(highRank==0)
    {
        highestRankText = "F";
        highestRank->setDefaultTextColor(QColor(94 , 94 , 94));
        highestRank->setPos(11 , 0);
    }
    highestRank->setPlainText(highestRankText);
    highestRank->setFont(highestRankTextFont);


    highestScore = new QGraphicsTextItem("", this);
    highestScore->setPlainText(QString::number(highscore));
    QFont highestScoreTextFont("SansSerif" , 30);
    highestScoreTextFont.setWeight(50);
    highestScore->setFont(highestScoreTextFont);
    highestScore->setPos(90 , -2);
    highestScore->setDefaultTextColor(QColor(107 , 107 , 107));
}
