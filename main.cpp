#include <unistd.h>
#include <QApplication>
#include "GameView.h"
#include "TestTimer.h"

GameView * gameView;
TestTimer timer;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gameView = new GameView();

    gameView->show();

    gameView->setMainMenu();

    return a.exec();
}
