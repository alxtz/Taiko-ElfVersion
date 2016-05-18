#ifndef EXITBUTTON_H
#define EXITBUTTON_H


#include <QObject>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>

class ExitButton : public QGraphicsTextItem
{
    Q_OBJECT

    public:
        ExitButton(QGraphicsItem * parent = 0);

        void mousePressEvent( QGraphicsSceneMouseEvent * event );
        void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
        void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);

    signals:
        void clicked();
};

#endif // EXITBUTTON_H
