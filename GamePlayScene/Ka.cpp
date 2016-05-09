#include <QPixmap>
#include "Ka.h"

Ka::Ka()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/ka.png"));
    setPos(800 , 343);
}

void Ka::move()
{
    setPos( x()-3 , y() );
}
