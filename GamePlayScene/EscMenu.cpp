#include <QPixmap>
#include "EscMenu.h"

EscMenu::EscMenu()
{
    setPixmap(QPixmap("./GameData/DefaultResources/images/escMenu.png"));

    setZValue(50);
}
