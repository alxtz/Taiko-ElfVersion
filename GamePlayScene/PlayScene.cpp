#include <QBrush>
#include <QImage>
#include <QPixmap>
#include "PlayScene.h"

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
}

void PlayScene::setBackgroundPicture()
{
    string backgroundPath;
    backgroundPath = "./GameData/Oves/" + playingOve + "/background.png";

    QString qBackgroundPath;
    qBackgroundPath = QString::fromStdString(backgroundPath);

    setBackgroundBrush(QBrush(QImage(qBackgroundPath)));
}
