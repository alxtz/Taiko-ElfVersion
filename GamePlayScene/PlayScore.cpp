#include <QFont>
#include "PlayScore.h"

PlayScore::PlayScore(QGraphicsItem * parent) :QGraphicsTextItem(parent)
{
    score = 0;

    setPlainText(QString::number(score));

    setDefaultTextColor(Qt::white);
    setFont(QFont("SansSerif" , 60));
    setPos(550 , 190 );
}

void PlayScore::addScore(int amount)
{
    score+=amount;
    setPlainText(QString::number(score));
}
