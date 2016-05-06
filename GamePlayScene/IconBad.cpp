#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include "IconBad.h"

IconBad::IconBad()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/bad.png"));
    setPos(195,305);

    QTimer::singleShot(200 , this , SLOT(destroySelf()));
}

void IconBad::destroySelf()
{
    scene()->removeItem(this);
    delete this;
}
