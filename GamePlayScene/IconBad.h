#ifndef ICONBAD_H
#define ICONBAD_H


#include <QObject>
#include <QGraphicsPixmapItem>

class IconBad : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        IconBad();

    public slots:
        void destroySelf();
};

#endif // ICONBAD_H
