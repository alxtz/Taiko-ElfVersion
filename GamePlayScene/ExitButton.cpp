#include <QFont>
#include <QColor>
#include <QSound>
#include "ExitButton.h"
#include "../GameView.h"

extern GameView * gameView;

ExitButton::ExitButton(QGraphicsItem * parent)
 : QGraphicsTextItem(parent)
{
    setAcceptHoverEvents(true);

    setPlainText("Exit");
}

void ExitButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QSound::play("./GameData/DefaultResources/sounds/ka.wav");
    //emit clicked();

    gameView->exitPlay();
}

void ExitButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setDefaultTextColor(QColor(214 , 49 , 88));
}

void ExitButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setDefaultTextColor(Qt::white);
}
