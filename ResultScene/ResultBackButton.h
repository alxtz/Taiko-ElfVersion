#ifndef RESULTBACKBUTTON_H
#define RESULTBACKBUTTON_H


#include <QObject>
#include <QGraphicsPixmapItem>

class ResultBackButton : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        ResultBackButton();

        void mousePressEvent( QGraphicsSceneMouseEvent * event );
        void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
        void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);

    signals:
        void clicked();
};

#endif // RESULTBACKBUTTON_H
