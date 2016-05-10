#include <QFont>
#include <QSound>
#include <QPixmap>
#include "ChildSongButton.h"

ChildSongButton::ChildSongButton(QGraphicsItem * parent , int index) : QGraphicsPixmapItem(parent)
{
    parentIndex = index;

    playText = new QGraphicsTextItem("Play" , this);
    QFont buttonTextFont("Helvetica" , 12);
    buttonTextFont.setWeight(75);
    playText->setFont(buttonTextFont);
    playText->setPos(5, 5);
    playText->setDefaultTextColor(QColor(16,138,112));

    setPixmap(QPixmap("./GameData/DefaultResources/images/childSongButton.png"));

    setPos( 75 , 70);
    setZValue(20);

    setAcceptHoverEvents(true);
}

void ChildSongButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QSound::play("./GameData/DefaultResources/sounds/ka.wav");

    emit clicked();
}

void ChildSongButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{

}

void ChildSongButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{

}

void ChildSongButton::destroySelf()
{
    delete this;
}
