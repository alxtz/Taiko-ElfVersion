#ifndef BACKBUTTON_H
#define BACKBUTTON_H


#include <QObject>
#include <QGraphicsPixmapItem>

class BackButton : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        BackButton();

        void mousePressEvent( QGraphicsSceneMouseEvent * event );
        void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
        void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);

    signals:
        void clicked();
};

#endif // BACKBUTTON_H
