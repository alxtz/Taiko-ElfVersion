#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include "IconGood.h"

IconGood::IconGood()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/good.png"));
    setPos(208,305);

    QTimer::singleShot(200 , this , SLOT(destroySelf()));
}

void IconGood::destroySelf()
{
    scene()->removeItem(this);
    delete this;
}
