#include <QPen>
#include <QBrush>
#include <QImage>
#include <QPixmap>
#include <QObject>
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
    playEngine->setFlag(QGraphicsItem::ItemIsFocusable);
    playEngine->setFocus();
    playEngine->grabKeyboard();

    hitPoint = new HitPoint();
    hitPoint->setPen(Qt::NoPen);
    addItem(hitPoint);

    drum = new Drum();
    addItem(drum);

    playScore = new PlayScore();
    addItem(playScore);

    combo = new Combo();
    addItem(combo);

    percentNow = new PercentNow();
    addItem(percentNow);

    connect(playEngine , SIGNAL(hitKey(int)) , hitPoint , SLOT (checkCollision(int)));
    connect(playEngine , SIGNAL(hitKey(int)) , drum , SLOT(setSmall(int)) );
    connect(hitPoint , SIGNAL(setGrade(int)) , playEngine , SLOT(spawnGrade(int)));
    connect(hitPoint , SIGNAL(setAddScore(int)) , playScore , SLOT(addScore(int)));
    connect(hitPoint , SIGNAL(setAddCombo()) , combo , SLOT(addCombo()));
    connect(hitPoint , SIGNAL(setEndCombo()) , combo , SLOT(endCombo()));
    connect(hitPoint , SIGNAL(setHitted(bool)) , percentNow , SLOT(hitted(bool)) );
}

void PlayScene::setBackgroundPicture()
{
    string backgroundPath;
    backgroundPath = "./GameData/Oves/" + playingOve + "/background.png";

    QString qBackgroundPath;
    qBackgroundPath = QString::fromStdString(backgroundPath);

    setBackgroundBrush(QBrush(QImage(qBackgroundPath)));
}

void PlayScene::endGame()
{

}
