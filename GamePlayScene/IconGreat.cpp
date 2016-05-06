#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#include "IconGreat.h"

IconGreat::IconGreat()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/great.png"));
    setPos(208,305);

    QTimer::singleShot(200 , this , SLOT(destroySelf()));
}

void IconGreat::destroySelf()
{
    scene()->removeItem(this);
    delete this;
}
