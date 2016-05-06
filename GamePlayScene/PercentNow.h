#ifndef PERCENTNOW_H
#define PERCENTNOW_H


#include <QObject>
#include <QGraphicsTextItem>

class PercentNow : public QGraphicsTextItem
{
    Q_OBJECT

    public:
        PercentNow();

    private:
        int totalHits;
        int correctHits;
        float percent;

    public slots:
        void hitted(bool correct);
};

#endif // PERCENTNOW_H
