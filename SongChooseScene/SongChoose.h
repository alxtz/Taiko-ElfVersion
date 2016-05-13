#ifndef SONGCHOOSE_H
#define SONGCHOOSE_H


#include <vector>
#include <string>
#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "SongButton.h"
#include "BackButton.h"

using namespace std;

class SongChoose : public QGraphicsScene
{
    Q_OBJECT

    public:
        SongChoose();
        ~SongChoose();

        vector <string> songList;
        vector <SongButton * > songButtonList;

        void loadSongList();
        void loadSongButtons();

    private:
        int songFocusedIndex;

        QString qBackgroundPath;
        QString qMusicPath;
        string lastSongName;
        string currentPlaying;
        QMediaPlaylist * backgroundMusicPlaylist;
        QMediaPlayer * backgroundMusicPlayer;
        BackButton * backButton;
        QGraphicsPixmapItem * selectPic;

    public slots:
        void setBackground(string oveName = "default");
        void setMusic(string oveName = "default");
        void buttonClicked(int index);
};

#endif // SONGCHOOSE_H
