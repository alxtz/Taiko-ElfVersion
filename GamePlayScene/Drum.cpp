#include <QPixmap>
#include <QTimer>
#include "Drum.h"

Drum::Drum()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/drumPic.jpg"));
    setZValue(10);
    setPos(0 , 295);
}

void Drum::setSmall(int type)
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/smallDrum.jpg"));

    QTimer::singleShot(100 , this , SLOT(setBig()));
}

void Drum::setBig()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/drumPic.jpg"));
}
