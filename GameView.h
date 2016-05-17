#ifndef GAMEVIEW_H
#define GAMEVIEW_H


#include <string>
#include <QTimer>
#include <QObject>
#include <QGraphicsView>
#include "./StartMenuScene/MainMenu.h"
#include "./SongChooseScene/SongChoose.h"
#include "./GamePlayScene/PlayScene.h"
#include "./ResultScene/GamePlayResult.h"
#include "./ResultScene/ResultScene.h"

using namespace std;

class GameView : public QGraphicsView
{
    Q_OBJECT

    public:
        GameView();

        MainMenu * mainMenu;
        SongChoose * songChoose;
        PlayScene * playScene;
        ResultScene * resultScene;
        QTimer * musicDelayTimer;

    public slots:
        void setMainMenu();
        void backToMainMenu();
        void setSongMenu();
        void setResultScene( GamePlayResult  gamePlayResult);
        void setPlayScene(string oveName);
        void setLastPlayed(string oveName);

        void exitResult();
};

#endif // GAMEVIEW_H
