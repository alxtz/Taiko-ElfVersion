#include <QPixmap>
#include "Dong.h"

Dong::Dong()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/dong.png"));
    setPos(800 , 343);
}

void Dong::move()
{
    setPos( x()-4 , y() );
}
