#include <QPixmap>
#include <QTimer>
#include "TaikoIcon.h"
#include "../GameView.h"

extern GameView * gameView;

TaikoIcon::TaikoIcon()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/Taiko.png"));
    setPos(150 , 160);
    setZValue(20);

    animation1();

    //gameView1->setSongMenu();
}

void TaikoIcon::animation1()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/TaikoMid.png"));
    QTimer::singleShot(90 , this , SLOT(animation2()) );
}

void TaikoIcon::animation2()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/TaikoSmall.png"));
    QTimer::singleShot(60 , this , SLOT(animation3()) );
}

void TaikoIcon::animation3()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/TaikoMid.png"));
    QTimer::singleShot(60 , this , SLOT(animation4()) );
}

void TaikoIcon::animation4()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/Taiko.png"));
    QTimer::singleShot(90 , this , SLOT(animation1()) );
}
