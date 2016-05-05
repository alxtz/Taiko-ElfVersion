#ifndef GAMEVIEW_H
#define GAMEVIEW_H


#include <string>
#include <QObject>
#include <QGraphicsView>
#include "./StartMenuScene/MainMenu.h"
#include "./SongChooseScene/SongChoose.h"
#include "./GamePlayScene/PlayScene.h"

using namespace std;

class GameView : public QGraphicsView
{
    Q_OBJECT

    public:
        GameView();

        MainMenu * mainMenu;
        SongChoose * songChoose;
        PlayScene * playScene;

    public slots:
        void setMainMenu();
        void setSongMenu();
        void setPlayScene(string oveName);
};

#endif // GAMEVIEW_H
