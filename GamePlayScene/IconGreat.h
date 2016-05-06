#ifndef ICONGREAT_H
#define ICONGREAT_H


#include <QObject>
#include <QGraphicsPixmapItem>

class IconGreat : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        IconGreat();

    public slots:
        void destroySelf();
};

#endif // ICONGREAT_H
