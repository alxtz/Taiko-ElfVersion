#include <QApplication>
#include "GameView.h"

GameView * gameView;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gameView = new GameView();

    gameView->show();

    gameView->setMainMenu();

    //gameView->setPlayScene("Together");

    //gameView->setPlayScene("HareHareYukai");

    return a.exec();
}
