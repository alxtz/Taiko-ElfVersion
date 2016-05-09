#include <QSound>
#include <QPixmap>
#include "BackButton.h"
#include "../GameView.h"

extern GameView * gameView;

BackButton::BackButton()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/back.png"));
    setPos(0 , 400);

    setAcceptHoverEvents(true);
}

void BackButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QSound::play("./GameData/DefaultResources/sounds/ka.wav");

    gameView->backToMainMenu();
}

void BackButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/backHovered.png"));
}

void BackButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/back.png"));
}
