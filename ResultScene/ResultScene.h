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

        void setResult();
};

#endif // RESULTSCENE_H
