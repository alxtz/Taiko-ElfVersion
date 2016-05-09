#include <QFont>
#include <QColor>
#include <QSound>
#include <QDebug>
#include <QPixmap>
#include <QGraphicsScene>
#include <iostream>

#include "../GameView.h"

using namespace std;

extern GameView * gameView;

SongButton::SongButton(QString buttonName , string buttonOve)
{
    oveName = buttonOve;

    buttonText = new QGraphicsTextItem(buttonName , this);
    QFont buttonTextFont("Helvetica" , 12);
    buttonTextFont.setWeight(75);
    buttonText->setFont(buttonTextFont);
    buttonText->setPos(5, 5);
    buttonText->setDefaultTextColor(QColor(16,138,112));

    isDown = false;

    setPixmap(QPixmap("./GameData/DefaultResources/images/songButton.png"));

    setAcceptHoverEvents(true);
}

void SongButton::setDown()
{
    isDown = true;
    setPixmap(QPixmap("./GameData/DefaultResources/images/songButtonHover.png"));
}

void SongButton::setUp()
{
    isDown = false;
    setPixmap(QPixmap("./GameData/DefaultResources/images/songButton.png"));
}

void SongButton::moveDown(int unit)
{
    setPos( x() , y()+60 );
}

void SongButton::moveUp(int unit)
{
    setPos( x() , y()-60 );
}

void SongButton::hideChildButton()
{
    //scene()->removeItem(childSongButton);
}

void SongButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QSound::play("./GameData/DefaultResources/sounds/ka.wav");

    //childSongButton->parentIndex=index;

    //childSongButton = new ChildSongButton(this);

    emit clicked(index);

    gameView->setLastPlayed(oveName);
}

void SongButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/songButtonHover.png"));
}

void SongButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if(isDown == false)
    {
        setPixmap(QPixmap("./GameData/DefaultResources/images/songButton.png"));
    }
}
