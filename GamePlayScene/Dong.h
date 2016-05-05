#ifndef DONG_H
#define DONG_H


#include <QObject>
#include <QGraphicsPixmapItem>

class Dong : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Dong();

    public slots:
        void move();
};

#endif // DONG_H
