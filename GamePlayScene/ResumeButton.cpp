#include <QFont>
#include <QColor>
#include <QSound>
#include "ResumeButton.h"

ResumeButton::ResumeButton(QGraphicsItem * parent)
 : QGraphicsTextItem(parent)
{
    setAcceptHoverEvents(true);

    setPlainText("Resume");
}

void ResumeButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QSound::play("./GameData/DefaultResources/sounds/ka.wav");
    emit clicked();
}

void ResumeButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setDefaultTextColor(QColor(16 , 186 , 224));
}

void ResumeButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setDefaultTextColor(Qt::white);
}
