#ifndef SONGBUTTON_H
#define SONGBUTTON_H


#include <string>
#include <QObject>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "ChildSongButton.h"

using namespace std;

class SongButton : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        SongButton(QString buttonName , string buttonOve);

        int index;
        bool isDown;
        string oveName;
        QGraphicsTextItem * buttonText;

        void setDown();
        void setUp();

        void moveDown(int unit);
        void moveUp(int unit);

        void mousePressEvent( QGraphicsSceneMouseEvent * event );
        void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
        void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);

    public slots:
        void gotoPlay();

    signals:
        void clicked(int);
        void destroyChild();
};

#endif // SONGBUTTON_H
