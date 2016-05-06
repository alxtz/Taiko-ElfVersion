#ifndef DRUM_H
#define DRUM_H


#include <QObject>
#include <QGraphicsPixmapItem>

class Drum : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Drum();

    public slots:
        void setSmall(int type);
        void setBig();
};

#endif // DRUM_H
