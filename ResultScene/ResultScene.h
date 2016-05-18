#ifndef RESULTSCENE_H
#define RESULTSCENE_H


#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "GamePlayResult.h"
#include "ResultBackButton.h"

class ResultScene : public QGraphicsScene
{
    public:
        ResultScene(GamePlayResult & gamePlayResult);

        QGraphicsPixmapItem * resultBoard;

        void setBackground();

        GamePlayResult & usingResult;

        QGraphicsTextItem * oveText;
        QGraphicsTextItem * scoreText;
        QGraphicsTextItem * percentText;
        QGraphicsTextItem * comboText;

        QGraphicsPixmapItem * greatPic;
        QGraphicsPixmapItem * goodPic;
        QGraphicsPixmapItem * badPic;

        QGraphicsTextItem * greatAmount;
        QGraphicsTextItem * goodAmount;
        QGraphicsTextItem * badAmount;

        QGraphicsTextItem * rank;

        ResultBackButton * backButton;

        void setResult();

        void setScoreFile();
};

#endif // RESULTSCENE_H
