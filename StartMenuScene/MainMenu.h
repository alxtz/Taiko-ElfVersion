#ifndef MAINMENU_H
#define MAINMENU_H


#include <string>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QGraphicsScene>
#include "TaikoIcon.h"
#include "SoloButton.h"

using namespace std;

class MainMenu : public QGraphicsScene
{
    public:
        MainMenu();
        ~MainMenu();

    private:
        QString qBackgroundPath;
        QString qMusicPath;
        string lastSongName;
        QMediaPlaylist * backgroundMusicPlaylist;
        QMediaPlayer * backgroundMusicPlayer;
        TaikoIcon * taikoIcon;
        SoloButton * soloButton;

        void setBackground();
        void setMusic();
};

#endif // MAINMENU_H
