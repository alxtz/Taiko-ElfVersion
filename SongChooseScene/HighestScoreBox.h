#ifndef HIGHESTSCOREBOX_H
#define HIGHESTSCOREBOX_H


#include <string>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>

using namespace std;

class HighestScoreBox : public QGraphicsPixmapItem
{
    public:
        HighestScoreBox(string oveName);

        QGraphicsTextItem * highestRank;
        QGraphicsTextItem * highestScore;
};

#endif // HIGHESTSCOREBOX_H
