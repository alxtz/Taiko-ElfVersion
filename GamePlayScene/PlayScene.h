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

using namespace std;

class PlayScene : public QGraphicsScene
{
    public:
        PlayScene(string oveName);

        void setBackgroundPicture();

        HitPoint * hitPoint;
        Drum * drum;
        PlayScore * playScore;
        Combo * combo;
        PercentNow * percentNow;

    private:
        string playingOve;
        QGraphicsPixmapItem * songTrack;

        PlayEngine * playEngine;
};

#endif // PLAYSCENE_H
