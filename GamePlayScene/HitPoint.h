#ifndef HITPOINT_H
#define HITPOINT_H


#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class HitPoint : public QObject , public QGraphicsRectItem
{
    Q_OBJECT

    public:
        HitPoint();

        int greatAmount;
        int goodAmount;
        int badAmount;

    private:
        QGraphicsPixmapItem * hitIcon;

    public slots:
        void checkCollision(int type);

    signals:
        void setGrade(int);
        void setAddScore(int);
        void setAddCombo();
        void setEndCombo();
        void setHitted(bool);
};

#endif // HITPOINT_H
