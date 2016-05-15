#include <QDebug>
#include <fstream>
#include "GameView.h"
#include "TestTimer.h"

extern TestTimer timer;

using namespace std;

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

void GameView::backToMainMenu()
{
    mainMenu = new MainMenu();
    setScene(mainMenu);

    delete songChoose;
}

void GameView::setSongMenu()
{
    songChoose = new SongChoose();
    setScene(songChoose);

    songChoose->loadSongButtons();

    delete mainMenu;
}

void GameView::setResultScene( GamePlayResult & gamePlayResult)
{
    qDebug()<<"setResultScene";

    resultScene = new ResultScene(gamePlayResult);
    setScene(resultScene);

    resultScene->setBackground();
    resultScene->setResult();

    delete playScene;
}

void GameView::setPlayScene(string oveName)
{
    playScene = new PlayScene(oveName);
    timer.start();
    playScene->playEngine->playSheetMusic();
    playScene->playEngine->playMusic();
    setScene(playScene);
    delete songChoose;
}

void GameView::setLastPlayed(string oveName)
{
    ofstream LastSong("./GameData/GameSettings/lastSong.txt" , ios::out);

    LastSong<<oveName;
}
