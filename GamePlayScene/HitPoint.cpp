#include <QPixmap>
#include <QList>
#include <QDebug>
#include <QGraphicsScene>
#include <typeinfo>
#include "HitPoint.h"
#include "Dong.h"
#include "Ka.h"

HitPoint::HitPoint()
{
    setRect(0 , 0 , 80 , 60);
    setPos(182 , 335);

    hitIcon = new QGraphicsPixmapItem(this);
    hitIcon->setPixmap(QPixmap("./GameData/DefaultResources/images/hitPoint.png"));
    hitIcon->setPos(10 , 0);
}

void HitPoint::checkCollision(int type)
{
    QList<QGraphicsItem * >colliding_items = collidingItems();
    if(type==0)
    {
        for(int i=0 , n=colliding_items.size(); i<n; i++ )
        {
            if(typeid( *(colliding_items[i]) ) == typeid(Dong))
            {
                if( colliding_items[i]->x()>=192 && colliding_items[i]->x()<=205 )
                {
                    qDebug()<<"Great Hit!";
                    emit setGrade(2);
                    emit setAddScore(500);
                    emit setAddCombo();
                    emit setHitted(true);
                }
                else if( colliding_items[i]->x()>=165 && colliding_items[i]->x()<=232 )
                {
                    qDebug()<<"Good Hit!";
                    emit setGrade(1);
                    emit setAddScore(200);
                    emit setAddCombo();
                    emit setHitted(true);
                }
                else if( colliding_items[i]->x()>=135 && colliding_items[i]->x()<=262 )
                {
                    qDebug()<<"Bad Hit!";
                    emit setGrade(0);
                    emit setEndCombo();
                    emit setHitted(false);
                }
                scene()->removeItem( colliding_items[i] );
                delete colliding_items[i];
                return;
            }
        }
    }
    else if(type==1)
    {
        for(int i=0 , n=colliding_items.size(); i<n; i++ )
        {
            if(typeid( *(colliding_items[i]) ) == typeid(Ka))
            {
                if( colliding_items[i]->x()>=192 && colliding_items[i]->x()<=205 )
                {
                    qDebug()<<"Great Hit!";
                    emit setGrade(2);
                    emit setAddScore(500);
                    emit setAddCombo();
                    emit setHitted(true);
                }
                else if( colliding_items[i]->x()>=165 && colliding_items[i]->x()<=232 )
                {
                    qDebug()<<"Good Hit!";
                    emit setGrade(1);
                    emit setAddScore(200);
                    emit setAddCombo();
                    emit setHitted(true);
                }
                else if( colliding_items[i]->x()>=135 && colliding_items[i]->x()<=262 )
                {
                    qDebug()<<"Bad Hit!";
                    emit setGrade(0);
                    emit setEndCombo();
                    emit setHitted(false);
                }
                scene()->removeItem( colliding_items[i] );
                delete colliding_items[i];
                return;
            }
        }
    }
}
