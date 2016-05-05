#include "GameView.h"

GameView::GameView()
{
    setFixedSize(800 , 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void GameView::setMainMenu()
{
    mainMenu = new MainMenu();
    setScene(mainMenu);
}

void GameView::setSongMenu()
{
    songChoose = new SongChoose();
    setScene(songChoose);

    delete mainMenu;
}

void GameView::setPlayScene(string oveName)
{
    playScene = new PlayScene(oveName);
    setScene(playScene);
}
