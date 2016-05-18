#ifndef RESUMEBUTTON_H
#define RESUMEBUTTON_H


#include <QObject>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>

class ResumeButton : public QGraphicsTextItem
{
    Q_OBJECT

    public:
        ResumeButton(QGraphicsItem * parent = 0);

        void mousePressEvent( QGraphicsSceneMouseEvent * event );
        void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
        void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);

    signals:
        void clicked();
};

#endif // RESUMEBUTTON_H
