#ifndef ESCMENU_H
#define ESCMENU_H


#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include "ExitButton.h"
#include "ResumeButton.h"

class EscMenu : public QGraphicsPixmapItem
{
    public:
        EscMenu();

        QGraphicsTextItem * paused;
        ResumeButton * resumeButton;
        ExitButton * exitButton;
};

#endif // ESCMENU_H
