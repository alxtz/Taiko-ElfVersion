#ifndef COMBO_H
#define COMBO_H


#include <QObject>
#include <QGraphicsTextItem>

class Combo : public QGraphicsTextItem
{
    Q_OBJECT

    public:
        Combo();

    private:
        int comboAmount;

    public slots:
        void addCombo();
        void endCombo();
};

#endif // COMBO_H
