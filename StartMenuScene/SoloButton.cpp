#include <QPixmap>
#include <QSound>
#include "SoloButton.h"
#include "../GameView.h"
#include "MainMenu.h"

extern GameView * gameView;

SoloButton::SoloButton()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/solo.png"));
    setPos(365 , 200);

    setAcceptHoverEvents(true);

    connect(this , SIGNAL(clicked()) , gameView , SLOT(setSongMenu()));

    //gameView->setSongMenu();
}

void SoloButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QSound::play("./GameData/DefaultResources/sounds/ka.wav");
    emit clicked();
}

void SoloButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/soloHovered.png"));
}

void SoloButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/solo.png"));
}
