#ifndef SOLOBUTTON_H
#define SOLOBUTTON_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class SoloButton : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        SoloButton();
        void mousePressEvent( QGraphicsSceneMouseEvent * event );
        void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
        void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);

    signals:
        void clicked();
};

#endif // SOLOBUTTON_H
