#include <QFont>
#include <QColor>
#include <QPixmap>
#include <QGraphicsScene>
#include "EscMenu.h"

EscMenu::EscMenu()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/escMenu.png"));

    setZValue(50);

    paused = new QGraphicsTextItem("Paused" , this);
    QFont pauseTextFont("Helvetica" , 60);
    pauseTextFont.setWeight(75);
    paused->setFont(pauseTextFont);
    paused->setPos(255 , 100);
    paused->setDefaultTextColor(Qt::white);

    resumeButton = new ResumeButton(this);
    resumeButton->setFont(pauseTextFont);
    resumeButton->setPos(245 , 250);
    resumeButton->setDefaultTextColor(Qt::white);

    exitButton = new ExitButton(this);
    exitButton->setFont(pauseTextFont);
    exitButton->setPos(310 , 400);
    exitButton->setDefaultTextColor(Qt::white);
}
