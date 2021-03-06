#include <QFont>
#include <QColor>
#include "Combo.h"

Combo::Combo()
{
    setZValue(15);

    comboAmount = 0;
    highestCombo = 0;

    setDefaultTextColor(QColor(189 , 32 , 65));
    setFont(QFont("SansSerif" , 40));
    setPos(66 , 347 );
}

void Combo::addCombo()
{
    comboAmount++;

    if(comboAmount>highestCombo)
    {
        highestCombo = comboAmount;
    }

    setPlainText(QString::number(comboAmount));

    if(comboAmount>=100)
    {
        setPos(36 , 347);
    }
    else if(comboAmount>=10)
    {
        setPos(51 , 347);
    }

}

void Combo::endCombo()
{
    comboAmount = 0;
    setPlainText(QString(""));
    setPos(66 , 347 );
}
