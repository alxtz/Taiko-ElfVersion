#ifndef TAIKOICON_H
#define TAIKOICON_H


#include <QObject>
#include <QGraphicsPixmapItem>

class TaikoIcon : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        TaikoIcon();

    public slots:
        void animation1();
        void animation2();
        void animation3();
        void animation4();
};

#endif // TAIKOICON_H
