#ifndef PLAYSCENE_H
#define PLAYSCENE_H


#include <string>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "PlayEngine.h"

using namespace std;

class PlayScene : public QGraphicsScene
{
    public:
        PlayScene(string oveName);

        void setBackgroundPicture();

    private:
        string playingOve;
        QGraphicsPixmapItem * songTrack;

        PlayEngine * playEngine;
};

#endif // PLAYSCENE_H
