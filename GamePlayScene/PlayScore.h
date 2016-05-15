#ifndef PLAYSCORE_H
#define PLAYSCORE_H


#include <QGraphicsTextItem>

class PlayScore : public QGraphicsTextItem
{
    Q_OBJECT

    public:
        PlayScore(QGraphicsItem * parent = 0);
        int score;

    public slots:
         void addScore(int amount);
};

#endif // PLAYSCORE_H
