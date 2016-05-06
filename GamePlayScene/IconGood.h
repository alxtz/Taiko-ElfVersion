#ifndef ICONGOOD_H
#define ICONGOOD_H


#include <QObject>
#include <QGraphicsPixmapItem>

class IconGood : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        IconGood();

    public slots:
        void destroySelf();
};

#endif // ICONGOOD_H
