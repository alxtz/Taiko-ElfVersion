#ifndef CHILDSONGBUTTON_H
#define CHILDSONGBUTTON_H


#include <QObject>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

class ChildSongButton : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        ChildSongButton(QGraphicsItem * parent , int index = 0);
        int parentIndex;

        void mousePressEvent( QGraphicsSceneMouseEvent * event );
        void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
        void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);

    private:
        QGraphicsTextItem * playText;

    signals:
        void clicked();

    public slots:
        void destroySelf();
};

#endif // CHILDSONGBUTTON_H
