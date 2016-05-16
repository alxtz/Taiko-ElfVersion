#ifndef RESULTSCENE_H
#define RESULTSCENE_H


#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "GamePlayResult.h"

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
        void setResult();
};

#endif // RESULTSCENE_H
