#ifndef CHILDSONGBUTTON_H
#define CHILDSONGBUTTON_H


#include <QGraphicsPixmapItem>

class ChildSongButton : public QGraphicsPixmapItem
{
    public:
        ChildSongButton(QGraphicsItem * parent , int index = 0);

        int parentIndex;
};

#endif // CHILDSONGBUTTON_H
