#include <QSound>
#include <QPixmap>
#include "ResultBackButton.h"
#include "../GameView.h"

extern GameView * gameView;

ResultBackButton::ResultBackButton()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/back.png"));
    setPos(0 , 400);

    setAcceptHoverEvents(true);
}

void ResultBackButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QSound::play("./GameData/DefaultResources/sounds/ka.wav");

    gameView->exitResult();
}

void ResultBackButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/backHovered.png"));
}

void ResultBackButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/back.png"));
}


