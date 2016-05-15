#ifndef PLAYSCENE_H
#define PLAYSCENE_H


#include <string>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "Drum.h"
#include "Combo.h"
#include "HitPoint.h"
#include "PlayScore.h"

#include "PercentNow.h"
#include "PlayEngine.h"
#include "../ResultScene/GamePlayResult.h"

using namespace std;

class PlayScene : public QGraphicsScene
{
    Q_OBJECT

    public:
        PlayScene(string oveName);
        ~PlayScene();

        void setBackgroundPicture();

        HitPoint * hitPoint;
        Drum * drum;
        PlayScore * playScore;
        Combo * combo;
        PercentNow * percentNow;
        PlayEngine * playEngine;
        GamePlayResult * gamePlayResult;

    public slots:
        void startResult();

    private:
        string playingOve;
        QGraphicsPixmapItem * songTrack;
};

#endif // PLAYSCENE_H
