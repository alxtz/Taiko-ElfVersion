#ifndef KA_H
#define KA_H


#include <QObject>
#include <QGraphicsPixmapItem>

class Ka : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Ka();

    public slots:
        void move();
};

#endif // KA_H
