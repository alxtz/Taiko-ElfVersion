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

SongButton::SongButton(QString buttonName  , QString songOrigin , string buttonOve)
{
    oveName = buttonOve;

    buttonText = new QGraphicsTextItem(buttonName , this);
    QFont buttonTextFont("Helvetica" , 12);
    buttonTextFont.setWeight(75);
    buttonText->setFont(buttonTextFont);
    buttonText->setPos(15, 5);
    buttonText->setDefaultTextColor(QColor(16,138,112));



    songOriginText = new QGraphicsTextItem(songOrigin , this);
    QFont originTextFont("Helvetica" , 8);
    originTextFont.setWeight(70);
    songOriginText->setFont(originTextFont);
    songOriginText->setPos(150, 30);
    songOriginText->setDefaultTextColor(QColor(16,138,112));

    isDown = false;

    setPixmap(QPixmap("./GameData/DefaultResources/images/songButton.png"));

    setAcceptHoverEvents(true);

    highestScoreBox = new HighestScoreBox(oveName);
    highestScoreBox->setPos(10 , 90);
}

void SongButton::setDown()
{
    isDown = true;
    setPixmap(QPixmap("./GameData/DefaultResources/images/songButtonHover.png"));
}

void SongButton::setUp()
{
    cout<<"setUp"<<endl;

    isDown = false;
    setPixmap(QPixmap("./GameData/DefaultResources/images/songButton.png"));

    scene()->removeItem(highestScoreBox);

    emit destroyChild();
}

void SongButton::moveDown(int unit)
{
    setPos( x() , y()+60 );
}

void SongButton::moveUp(int unit)
{
    setPos( x() , y()-60 );
}

void SongButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QSound::play("./GameData/DefaultResources/sounds/ka.wav");

    ChildSongButton * childSongButton = new ChildSongButton(this);
    connect(this , SIGNAL(destroyChild()) , childSongButton , SLOT(destroySelf()));
    connect(childSongButton , SIGNAL(clicked()) , this , SLOT(gotoPlay()) );

    scene()->addItem(highestScoreBox);

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

void SongButton::gotoPlay()
{
    gameView->setPlayScene(oveName);
}
