#ifndef SONGCHOOSE_H
#define SONGCHOOSE_H


#include <string>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QGraphicsScene>

using namespace std;

class SongChoose : public QGraphicsScene
{
    public:
        SongChoose();

    private:
        QString qBackgroundPath;
        QString qMusicPath;
        string lastSongName;
        QMediaPlaylist * backgroundMusicPlaylist; //有一點不一樣的是，我會把所有音樂檔都存進去
        QMediaPlayer * backgroundMusicPlayer;

        void setBackground();
        void setMusic();
};

#endif // SONGCHOOSE_H
