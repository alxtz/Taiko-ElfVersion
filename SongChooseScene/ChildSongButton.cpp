#include <QPixmap>
#include "ChildSongButton.h"

ChildSongButton::ChildSongButton(QGraphicsItem * parent , int index) : QGraphicsPixmapItem(parent)
{
    parentIndex = index;

    setPixmap(QPixmap("./GameData/DefaultResources/images/childSongButton.png"));

    setPos( 75 , 0);
    //setPos( 75 , 70);


    setZValue(20);
}
